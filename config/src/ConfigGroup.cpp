/* Copyright © 2025 Jordan Irwin <antumdeluge@gmail.com>
 *
 * This work is licensed under the terms of the MIT license.
 * See: LICENSE.txt
 */

#include "ConfigGroup.hpp"


ConfigGroup::ConfigGroup(uint32_t x, uint32_t y, uint32_t w, const char* label):
Fl_Group(x, y, w, 10, label) {
	box(FL_ENGRAVED_FRAME);
}
