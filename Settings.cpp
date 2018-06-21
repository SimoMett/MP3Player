//
// Created by matteo on 16/06/18.
//

#include "Settings.h"

Settings::Settings(string settingsfile)
{
    if(!wxFileExists(settingsfile))
    {
        wxFile settings(settingsfile,wxFile::OpenMode::write_excl);
        settings.Close();
    }

    LoadSettings(settingsfile);
}

Settings::~Settings()
{
    SaveSettings();
}

void Settings::LoadSettings(string file)
{

}

void Settings::SaveSettings()
{

}