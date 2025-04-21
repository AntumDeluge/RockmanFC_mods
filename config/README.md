
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

Example build of static release:

```
$ cmake -B build-release -DCMAKE_BUILD_TYPE=Release -DSTATIC=ON
$ cmake --build build-release
```
