
cmake_minimum_required(VERSION 3.21)

project("Rockman FC Config")

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
endif()

option(STATIC OFF "Link dependencies statically")

set(ROCKMAN_VERSION "7" CACHE STRING "Version for which Config is to be built")
set_property(CACHE ROCKMAN_VERSION PROPERTY STRINGS "7" "8")

configure_file("config.h.in" "config.h")

if(STATIC)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
	set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
endif()

if(WIN32)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
	# strip debugging symbols
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s")
endif()

unset(FLTK_LIBRARIES CACHE)
find_library(FLTK_LIBRARIES fltk REQUIRED)

file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(Config_GUI ${SRC_FILES})

target_include_directories(
	Config_GUI PRIVATE
	"${PROJECT_SOURCE_DIR}/src"
	"${PROJECT_BINARY_DIR}"
)

target_link_libraries(
	Config_GUI PRIVATE
	${FLTK_LIBRARIES}
)

if(STATIC AND WIN32)
	target_link_libraries(
		Config_GUI PRIVATE
		ws2_32
		kernel32
		user32
		gdi32
		winspool
		shell32
		ole32
		oleaut32
		uuid
		comdlg32
		advapi32
	)
endif()
