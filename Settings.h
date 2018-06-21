//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_SETTINGS_H
#define MP3PLAYER_SETTINGS_H

#include <fstream>
#include <wx/wx.h>
#include <wx/xml/xml.h>
#include <wx/file.h>
#include <string>

using namespace std;

class Settings {

public:
    explicit Settings(string settingsfile="settings.xml");
    ~Settings();

    float savedVolume;

    void SaveSettings();

private:
    void LoadSettings(string file);

};


#endif //MP3PLAYER_SETTINGS_H
