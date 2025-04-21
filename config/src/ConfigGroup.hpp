/* Copyright © 2025 Jordan Irwin <antumdeluge@gmail.com>
 *
 * This work is licensed under the terms of the MIT license.
 * See: LICENSE.txt
 */

#ifndef RMFC_MODS_CONFIG_GROUP
#define RMFC_MODS_CONFIG_GROUP

#include <cstdint> // *int*_t

#include <FL/Fl_Group.H>


class ConfigGroup: public Fl_Group {
public:
	/**
	 * Constructs a new configuration group.
	 *
	 * @param x
	 * @param y
	 * @param w
	 * @param label
	 */
	ConfigGroup(uint32_t x, uint32_t y, uint32_t w, const char* label);

	/** Virtual destructor. */
	virtual ~ConfigGroup() {}

	/**
	 * Adds an option to the group.
	 *
	 * @param label
	 *   Displayed text.
	 */
	virtual void addOption(const char* label) = 0;

	/**
	 * Adds an option to the group.
	 *
	 * @param label
	 *   Displayed text.
	 * @param selected
	 *   Whether or not option should be enabled by default (does nothing in this implementation).
	 */
	virtual void addOption(const char* label, const bool selected) {
		addOption(label);
	}

	/**
	 * Sets selected option.
	 *
	 * @param idx
	 *   Index of option to select.
	 */
	virtual void setSelected(uint32_t idx) = 0;

	/**
	 * Sets selected option.
	 *
	 * @param idx
	 *   Index of option to select.
	 * @param selected
	 *   Whether or not option should be enabled (does nothing in this implementation).
	 */
	virtual void setSelected(uint32_t idx, const bool selected) {
		setSelected(idx);
	}
};

#endif /* RMFC_MODS_CONFIG_GROUP */
