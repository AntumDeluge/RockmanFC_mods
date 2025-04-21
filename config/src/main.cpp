/* Copyright © 2025 Jordan Irwin <antumdeluge@gmail.com>
 *
 * This work is licensed under the terms of the MIT license.
 * See: LICENSE.txt
 */

#include "config.h"

#include <filesystem>
#include <iostream>
#include <string>

#include "ConfigIO.hpp"
#include "ConfigWindow.hpp"

using namespace std;


int main(int argc, char** argv) {
	if (argc == 0) {
		// shouldn't happen
		cerr << "ERROR: can't determine executing process" << endl;
		return 1;
	}

	filesystem::path exe_path = filesystem::absolute(filesystem::path(argv[0]));
	SetAppDir(exe_path.parent_path());

	ConfigWindow* window = new ConfigWindow(300, 390, ("Rockman " + to_string(ROCKMAN_VERSION)
			+ " FC Config").c_str());

	window->end();
	window->show(argc, argv);

	return Fl::run();
}
