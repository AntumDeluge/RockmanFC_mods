/* Copyright © 2025 Jordan Irwin <antumdeluge@gmail.com>
 *
 * This work is licensed under the terms of the MIT license.
 * See: LICENSE.txt
 */

#include "config.h"

#include "CheckGroup.hpp"
#include "ConfigIO.hpp"
#include "ConfigWindow.hpp"
#include "RadioGroup.hpp"

using namespace std;


static void _onAccept(Fl_Widget* w, void* userdata) {
	ConfigWindow* window = (ConfigWindow*) userdata;
	window->writeConfig();
	// close app
	window->hide();
}

static void _onCancel(Fl_Widget* w, void* userdata) {
	// just close app
	((ConfigWindow*) userdata)->hide();
}

ConfigWindow::ConfigWindow(uint32_t width, uint32_t height, const char* title)
: Fl_Window(width, height, title) {
	// center on display
	position((Fl::w() - width) / 2, (Fl::h() - height) / 2);

	g_input = new RadioGroup(10, 20, width - 20, "Input");
	g_input->addOption("Z = jump, X = shoot");
	g_input->addOption("Z = shoot, X = jump");
	g_input->end();
	groups.push_back(g_input);

	g_display = new RadioGroup(10, 110, width - 20, "Display");
	g_display->addOption("256 x 224 (1x)");
	g_display->addOption("512 x 448 (2x)");
	g_display->addOption("768 x 672 (3x)");
#if ROCKMAN_VERSION != 7
	g_display->addOption("1024 x 896 (4x)");
	g_display->addOption("1280 x 1120 (5x)");
	g_display->addOption("Fullscreen");
#endif
	g_display->end();
	groups.push_back(g_display);

#if ROCKMAN_VERSION == 7
	g_audio = new CheckGroup(10, 270, width - 20, "Audio");
	g_audio->addOption("Music", true);
	g_audio->addOption("Sound effects", true);
	g_audio->end();
	groups.push_back(g_audio);
#else
	g_vsync = new RadioGroup(10, 270, width - 20, "VSync");
	g_vsync->addOption("On");
	g_vsync->addOption("Off");
	g_vsync->end();
	groups.push_back(g_vsync);
#endif

	btn_accept = new Fl_Button((width / 4) - 40, height - 30, 80, 20, "Ok");
	btn_cancel = new Fl_Button((width * 0.75) - 40, height - 30, 80, 20, "Cancel");
	btn_accept->callback(_onAccept, (void*) this);
	btn_cancel->callback(_onCancel, (void*) this);

	update();
	readConfig();
}

void ConfigWindow::update() {
	uint32_t h = 20; // height of buttons
	for (auto g: groups) {
		h += g->h() + 30;
	}

	resize(x(), y(), w(), h);

	uint32_t y_offset = 20;
	for (uint32_t idx = 0; idx < groups.size(); idx++) {
		auto g = groups[idx];
		g->position(g->x(), y_offset);
		g->redraw();
		y_offset += g->h() + 20;
	}

	// button positions need updated
	btn_accept->position(btn_accept->x(), y_offset);
	btn_accept->redraw();
	btn_cancel->position(btn_cancel->x(), y_offset);
	btn_cancel->redraw();
}

void ConfigWindow::readConfig() {
	vector<uint32_t> data = ReadConfig();

	uint32_t d_count = data.size();
	if (d_count > 0) {
		g_input->setSelected(data[0]);
	}
	if (d_count > 1) {
		g_display->setSelected(data[1]);
	}
	if (d_count > 2) {
#if ROCKMAN_VERSION == 7
		g_audio->setSelected(0, data[2] > 0 ? true : false);
	}
	if (d_count > 3) {
		g_audio->setSelected(1, data[3] > 0 ? true : false);
#else
		g_vsync->setSelected(data[2]);
#endif
	}
}

void ConfigWindow::writeConfig() {
	vector<uint32_t> data;

	data.push_back(g_input->selected());
	data.push_back(g_display->selected());
#if ROCKMAN_VERSION == 7
	for (bool value: g_audio->selected()) {
		data.push_back(value ? 1 : 0);
	}
#else
	data.push_back(g_vsync->selected());
#endif

	WriteConfig(data);
}
