/* Copyright © 2025 Jordan Irwin <antumdeluge@gmail.com>
 *
 * This work is licensed under the terms of the MIT license.
 * See: LICENSE.txt
 */

#include "RadioGroup.hpp"


void RadioGroup::addOption(const char* label) {
	uint32_t w = this->w() - 10;
	uint32_t h = 20;

	Fl_Round_Button* button = new Fl_Round_Button(0, 0, w, h, label);
	button->type(FL_RADIO_BUTTON);
	options.push_back(button);
	if (options.size() == 1) {
		button->value(1);
	}

	// update group box dimensions
	resize(this->x(), this->y(), this->w(), 10 + (20 * options.size()));
	uint32_t x = this->x() + 5;
	uint32_t y = this->y() + 5;
	for (uint32_t idx = 0; idx < options.size(); idx++) {
		if (idx > 0) {
			y += 20;
		}
		options[idx]->resize(x, y, w, h);
	}
}

void RadioGroup::setSelected(uint32_t idx) {
	const uint32_t o_count = options.size();
	if (o_count < 1) {
		return;
	}
	if (idx > o_count - 1) {
		// use last option in list
		idx = o_count - 1;
	}
	for (auto opt: options) {
		opt->value(0);
	}
	options[idx]->value(1);
}

uint32_t RadioGroup::selected() {
	for (uint32_t idx = 0; idx < options.size(); idx++) {
		if (options[idx]->value() > 0) {
			return idx;
		}
	}
	// default to first index
	return 0;
}
