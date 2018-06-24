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

    ~Settings();

    static Settings * Istantiate(string settingsfile="resources/settings.xml");

    void SaveSettings();
    void setSavedVolume(float val);
    float getSavedVolume() const{
        return savedVolume;
    }

    static Settings * getIstance() {
        return singleIstance;
    }

protected:
    explicit Settings(string settingsfile);


private:
    static Settings * singleIstance;
    float savedVolume;
    string settingsPath;
    void LoadSettings(string file);

};


#endif //MP3PLAYER_SETTINGS_H
