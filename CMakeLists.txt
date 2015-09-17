cmake_minimum_required (VERSION 2.6)
project(apricots)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL REQUIRED)
include_directories(${SDL_INCLUDE_DIR})
find_package(SDL_mixer REQUIRED)

file(GLOB SOURCES *.cpp)
file(GLOB HEADERS *.h)

if(APPLE)
	set(SOURCES_EXTRA build/macosx/SDLMain.m build/macosx/SDLMain.h)
	set_source_files_properties(build/macosx/SDLMain.m PROPERTIES LANGUAGE C)
endif()

add_executable(apricots ${SOURCES} ${HEADERS} ${SOURCES_EXTRA})
target_link_libraries(apricots ${SDL_LIBRARY} ${SDLMIXER_LIBRARY})
