/* Copyright © 2025 Jordan Irwin <antumdeluge@gmail.com>
 *
 * This work is licensed under the terms of the MIT license.
 * See: LICENSE.txt
 */

#ifndef RMFC_MODS_CONFIG_IO
#define RMFC_MODS_CONFIG_IO

#include "config.h"

#include <cstdint> // *int*_t
#include <vector>


/**
 * Loads binary config data.
 *
 * For Rockman 7 target is text file `config.ini`. For Rockman 8 its binary file `ini.bin`.
 *
 * @return
 *   Data representing configuration values.
 */
extern std::vector<uint32_t> ReadConfig();

/**
 * Exports config data to binary file.
 *
 * For Rockman 7 target is text file `config.ini`. For Rockman 8 its binary file `ini.bin`.
 *
 * @param data
 *   Data representing configuration values.
 */
extern void WriteConfig(std::vector<uint32_t> data);

#endif /* RMFC_MODS_CONFIG_IO */
