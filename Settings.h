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
#include <memory>
#include <wx/sstream.h>

using namespace std;

class Settings {

public:
    explicit Settings(string settingsfile="resources/settings.xml");
    ~Settings();

    void SaveSettings();
    void setSavedVolume(float val);

private:
    float savedVolume;
    string settingsPath;
    void LoadSettings(string file);

};


#endif //MP3PLAYER_SETTINGS_H
