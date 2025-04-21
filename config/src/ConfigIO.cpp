/* Copyright © 2025 Jordan Irwin <antumdeluge@gmail.com>
 *
 * This work is licensed under the terms of the MIT license.
 * See: LICENSE.txt
 */

#include "config.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "ConfigIO.hpp"

using namespace std;


static filesystem::path config_file = "config.ini";

/**
 * Converts a string to unsigned char.
 *
 * @param st
 *   String to be converted.
 * @param d
 *   Default value if conversion fails.
 */
static uint8_t toUChar(string st, uint8_t d) {
	uint8_t c = d;
	try {
		c = (uint8_t) stoul(st);
	} catch (const invalid_argument& e) {
	} catch (const std::out_of_range& e) {
	}
	return c;
}

void SetAppDir(filesystem::path dir) {
#if ROCKMAN_VERSION == 7
	config_file = dir / "config.ini";
#else
	config_file = dir / "ini.bin";
#endif
}

vector<uint8_t> ReadConfig() {
	vector<uint8_t> data;

#if ROCKMAN_VERSION == 7
	string data_string;
	// use binary mode to preserve CRLF line endings
	ifstream in_txt(config_file.string(), ios::binary);
	if (in_txt.is_open()) {
		stringstream ss;
		ss << in_txt.rdbuf();
		data_string = ss.str();
		in_txt.close();
	}

	if (data_string.length() > 0) {
		vector<string> lines;
		// split by newline
		size_t pos_l = 0;
		size_t pos_r = data_string.find("\r\n");
		while (pos_r != string::npos) {
			lines.push_back(data_string.substr(pos_l, pos_r - pos_l));
			pos_l = pos_r + 2;
			pos_r = data_string.find("\r\n", pos_l);
		}

		for (string li: lines) {
			size_t delim_idx = li.find("=");
			if (delim_idx == string::npos) {
				continue;
			}
			string key = li.substr(0, delim_idx);
			string value = li.substr(delim_idx+1, li.length()-(delim_idx+1));
			if (key == "Attack") {
				if (value == "90") {
					data.push_back(1);
				} else {
					data.push_back(0);
				}
			} else if (key == "Size") {
				data.push_back(toUChar(value, 1)-1);
			} else if (key == "BGM") {
				data.push_back(toUChar(value, 1));
			} else if (key == "SE") {
				data.push_back(toUChar(value, 1));
			}
		}
	}

#else
	// defaults
	data = {0, 1, 1};

	ifstream in_bin(config_file.string(), ios::binary);
	if (in_bin.is_open()) {
		vector<uint8_t> temp(3);
		in_bin.read(reinterpret_cast<char*>(temp.data()), temp.size());
		uint64_t byte_count = static_cast<uint64_t>(in_bin.gcount());
		if (byte_count > 2) {
			// Note: index 0 is display, 1 is input
			data[0] = temp[1];
			data[1] = temp[0];
			data[2] = temp[2];
		}
	}
#endif

	return data;
}

void WriteConfig(vector<uint8_t> data) {
	const uint8_t d_count = data.size();

#if ROCKMAN_VERSION == 7
	string data_string = "[Key]\r\nAttack=88\r\nJump=90\r\n";
	if (d_count > 0 && data[0] > 0) {
		data_string = "[Key]\r\nAttack=90\r\nJump=88\r\n";
	}
	data_string += "[Window]\r\nSize=";
	if (d_count > 1) {
		data_string += to_string(data[1]+1) + "\r\n";
	} else {
		data_string += "1\r\n";
	}
	uint8_t bgm = 1;
	uint8_t se = 1;
	data_string += "[Sound]\r\n";
	if (d_count > 2) {
		bgm = data[2];
	}
	if (d_count > 3) {
		se = data[3];
	}
	data_string += "BGM=" + to_string(bgm) + "\r\nSE=" + to_string(se) + "\r\n";

	// use binary mode to enforce CRLF line endings
	ofstream out_txt(config_file.string(), ios::binary);
	if (!out_txt.is_open()) {
		cerr << "ERROR: cannot open file for writing: " << config_file.string() << endl;
		return;
	}
	out_txt << data_string;
	out_txt.close();

#else
	// Note: index 0 is display, 1 is input
	uint8_t input = data[0];
	uint8_t display = data[1];
	data[0] = display;
	data[1] = input;

	ofstream out_bin(config_file.string(), ios::binary);
	if (!out_bin.is_open()) {
		cerr << "ERROR: cannot open file for writing: " << config_file.string() << endl;
		return;
	}
	out_bin.write(reinterpret_cast<const char*>(data.data()), data.size());
	out_bin.close();

#endif
}
