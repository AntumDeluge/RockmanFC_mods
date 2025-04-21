/* Copyright © 2025 Jordan Irwin <antumdeluge@gmail.com>
 *
 * This work is licensed under the terms of the MIT license.
 * See: LICENSE.txt
 */

#ifndef RMFC_MODS_CONFIG_RADIO_GROUP
#define RMFC_MODS_CONFIG_RADIO_GROUP

#include <vector>

#include <FL/Fl_Round_Button.H>

#include "ConfigGroup.hpp"


class RadioGroup: public ConfigGroup {
private:
	std::vector<Fl_Round_Button*> options;

public:
	/**
	 * Constructs a new radio group.
	 *
	 * @param x
	 * @param y
	 * @param w
	 * @param label
	 */
	RadioGroup(uint32_t x, uint32_t y, uint32_t w, const char* label): ConfigGroup(x, y, w, label) {}

	/**
	 * Adds an option to the group.
	 *
	 * @param label
	 *   Displayed text.
	 */
	void addOption(const char* label) override;

	/**
	 * Sets selected option.
	 *
	 * @param idx
	 *   Index of option to select.
	 */
	void setSelected(uint8_t idx) override;

	/**
	 * Retreives selected value.
	 *
	 * @return
	 *   Selected index.
	 */
	uint8_t selected();
};

#endif /* RMFC_MODS_CONFIG_RADIO_GROUP */
