/* Copyright © 2025 Jordan Irwin <antumdeluge@gmail.com>
 *
 * This work is licensed under the terms of the MIT license.
 * See: LICENSE.txt
 */

#include "config.h"

#include <string>

#include "ConfigWindow.hpp"

using namespace std;


int main(int argc, char** argv) {
	ConfigWindow* window = new ConfigWindow(300, 390, ("Rockman " + to_string(ROCKMAN_VERSION)
			+ " FC Config").c_str());

	window->end();
	window->show(argc, argv);

	return Fl::run();
}
