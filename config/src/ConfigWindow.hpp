/* Copyright © 2025 Jordan Irwin <antumdeluge@gmail.com>
 *
 * This work is licensed under the terms of the MIT license.
 * See: LICENSE.txt
 */

#ifndef RMFC_MODS_CONFIG_WINDOW
#define RMFC_MODS_CONFIG_WINDOW

#include <cstdint> // *int*_t
#include <vector>

#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>

#include "CheckGroup.hpp"
#include "ConfigGroup.hpp"
#include "RadioGroup.hpp"


class ConfigWindow: public Fl_Window {
private:
	std::vector<ConfigGroup*> groups;

public:
	/**
	 * Constructs a GUI configuration window.
	 *
	 * @param width
	 *   Window width.
	 * @param height
	 *   Window height.
	 * @param title
	 *   Window title string.
	 */
	ConfigWindow(uint32_t width, uint32_t height, const char* title);

	void readConfig();
	void writeConfig();

private:
	RadioGroup* g_input;
	RadioGroup* g_display;
	RadioGroup* g_vsync;
	CheckGroup* g_audio;

	Fl_Button* btn_accept;
	Fl_Button* btn_cancel;

	/** Updates window size according to configured groups. */
	void update();
};

#endif /* RMFC_MODS_CONFIG_WINDOW */
