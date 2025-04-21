/* Copyright © 2025 Jordan Irwin <antumdeluge@gmail.com>
 *
 * This work is licensed under the terms of the MIT license.
 * See: LICENSE.txt
 */

#ifndef RMFC_MODS_CONFIG_CHECK_GROUP
#define RMFC_MODS_CONFIG_CHECK_GROUP

#include <vector>

#include <FL/Fl_Check_Button.H>

#include "ConfigGroup.hpp"


class CheckGroup: public ConfigGroup {
private:
	std::vector<Fl_Check_Button*> options;

public:
	/**
	 * Constructs a new radio group.
	 *
	 * @param x
	 * @param y
	 * @param w
	 * @param label
	 */
	CheckGroup(uint32_t x, uint32_t y, uint32_t w, const char* label): ConfigGroup(x, y, w, label) {}

	/**
	 * Adds an option to the group.
	 *
	 * @param label
	 *   Displayed text.
	 */
	void addOption(const char* label) override { addOption(label, false); }

	/**
	 * Adds an option to the group.
	 *
	 * @param label
	 *   Displayed text.
	 * @param selected
	 *   Whether or not option should be enabled by default.
	 */
	void addOption(const char* label, const bool selected) override;

	/** Does nothing in this implementation. */
	void setSelected(uint8_t idx) override {};

	/**
	 * Sets selected state of option.
	 *
	 * @param idx
	 *   Index of option to select.
	 * @param selected
	 *   Whether or not option should be enabled.
	 */
	void setSelected(uint8_t idx, const bool selected) override;

	/**
	 * Retreives selected values.
	 *
	 * @return
	 */
	std::vector<bool> selected();
};

#endif /* RMFC_MODS_CONFIG_CHECK_GROUP */
