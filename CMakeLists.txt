cmake_minimum_required(VERSION 3.6)
project(MP3Player)

set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED net core base adv xml media)
include(${wxWidgets_USE_FILE})

add_subdirectory(GTest)

set(SOURCE_FILES Mp3Player.h Mp3Player.cpp MainApp.h MainApp.cpp MainFrame.h MainFrame.cpp  Subject.h Subject.cpp Observer.cpp Observer.h PlayList.cpp PlayList.h PlaylistFactory.cpp PlaylistFactory.h Settings.cpp Settings.h Album.cpp Album.h TrackFactory.cpp Track.cpp Track.h TrackFactory.h Slider.cpp Slider.h VolumeSlider.cpp VolumeSlider.h TrackSlider.cpp TrackSlider.h PlaylistsListBox.cpp PlaylistsListBox.h TracksListBox.cpp TracksListBox.h WindowIDs.h Bitmap.cpp Bitmap.h AlbumListBox.cpp AlbumListBox.h AlbumFactory.cpp AlbumFactory.h AbstractPlayList.cpp AbstractPlayList.h)
add_executable(MP3Player ${SOURCE_FILES})

add_library(core ${SOURCE_FILES} )

target_link_libraries(MP3Player ${wxWidgets_LIBRARIES} core)