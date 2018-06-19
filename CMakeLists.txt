cmake_minimum_required(VERSION 3.6)
project(MP3Player)

set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED net gl core base adv)
include(${wxWidgets_USE_FILE})

add_executable(MP3Player Mp3Player.h Mp3Player.cpp MainApp.h MainApp.cpp MainFrame.h MainFrame.cpp AppEventHandler.cpp AppEventHandler.h Subject.h Subject.cpp Observer.cpp Observer.h PlayList.cpp PlayList.h PlaylistFactory.cpp PlaylistFactory.h Settings.cpp Settings.h Album.cpp Album.h TrackFactory.cpp Track.cpp Track.h TrackFactory.h)

target_link_libraries(MP3Player ${wxWidgets_LIBRARIES})