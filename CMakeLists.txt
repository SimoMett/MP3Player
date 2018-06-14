cmake_minimum_required(VERSION 3.5)
project(MP3Player)

set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

add_executable(MP3Player Mp3Player.cpp Mp3Player.h)

target_link_libraries(MP3Player ${wxWidgets_LIBRARIES})