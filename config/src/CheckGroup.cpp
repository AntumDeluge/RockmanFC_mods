/* Copyright © 2025 Jordan Irwin <antumdeluge@gmail.com>
 *
 * This work is licensed under the terms of the MIT license.
 * See: LICENSE.txt
 */

#include "CheckGroup.hpp"

using namespace std;


void CheckGroup::addOption(const char* label, const bool selected) {
	uint32_t w = this->w() - 10;
	uint32_t h = 20;

	Fl_Check_Button* button = new Fl_Check_Button(0, 0, w, h, label);
	options.push_back(button);
	button->value(selected ? 1 : 0);

	// update group box dimensions
	resize(this->x(), this->y(), this->w(), 10 + (20 * options.size()));
	uint32_t x = this->x() + 5;
	uint32_t y = this->y() + 5;
	for (uint8_t idx = 0; idx < options.size(); idx++) {
		if (idx > 0) {
			y += 20;
		}
		options[idx]->resize(x, y, w, h);
	}
}

void CheckGroup::setSelected(uint8_t idx, const bool selected) {
	const uint8_t o_count = options.size();
	if (o_count < 1 || idx > o_count - 1) {
		return;
	}
	options[idx]->value(selected ? 1 : 0);
}

vector<bool> CheckGroup::selected() {
	vector<bool> values;
	for (auto button: options) {
		values.push_back(button->value() == 1);
	}
	return values;
}
