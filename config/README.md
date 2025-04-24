
# Configuration Executables for Rockman 7/8 FC

## Description

Applications to replace the default configuration executables.

## Building

### Requirements

- [CMake](https://cmake.org/)
- [FLTK](https://fltk.org/)

### Build Instructions

From project directory execute:

```
$ cmake ./
$ cmake --build ./
```

To build in separate directory execute (replace `<build-dir>` with actual directory path):

```
$ cmake -B <build-dir> ./
$ cmake --build <build-dir>
```

CMake configuration options:

- `ROCKMAN_VERSION:` Version of Rockman FC. Supported values are "7" & "8" (default: "7").
- `STATIC:` Link statically to dependencies (default: OFF).
- `CMAKE_INSTALL_PREFIX:` Directory to install files using `cmake --install` (default: auto detect).
- `CMAKE_BUILD_TYPE:` Build type. Supported values are "Debug" & "Release" (default: "Debug").
- `FLTK_LIBRARIES:` Path to FLTK library (default: auto detect).

Example build of static release for Rockman 8:

```
$ cmake -B build-release -DROCKMAN_VERSION=8 -DCMAKE_BUILD_TYPE=Release -DSTATIC=ON
$ cmake --build build-release
```

Build release package archive:

```
$ cmake --build build-release -t pack
```

### Links

- Downloads: https://github.com/AntumDeluge/RockmanFC_mods/releases/latest
- Game links:
    - [Rockman 7 Famicom wiki](https://megamanfanon.fandom.com/wiki/Rockman_7_Famicom) (includes download link)
    - [Rockman 8 Famicom wiki](https://megamanfanon.fandom.com/wiki/Rockman_8_Famicom) (includes download link)
    - [English mod for Rockman 7 Famicom by Grahf78](https://www.reddit.com/r/Megaman/comments/755jak/rockman7fc_demake_translated_to_english/)
    - [English mod for Rockman 8 Famicom (v2.91b) by Sparkplug](https://www.youtube.com/watch?v=XDlPWC3yHx8) (download link in description)
