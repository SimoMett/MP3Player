cmake_minimum_required(VERSION 3.5)
project(MP3Player)

set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED net gl core base adv)
include(${wxWidgets_USE_FILE})

add_executable(MP3Player MainApp.h MainApp.cpp MainFrame.h MainFrame.cpp AppEventHandler.cpp AppEventHandler.h Subject.cpp Subject.h Observer.cpp Observer.h PlayList.cpp PlayList.h Track.cpp Track.h)

target_link_libraries(MP3Player ${wxWidgets_LIBRARIES})