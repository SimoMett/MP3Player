//
// Created by matteo on 16/06/18.
//

#include "Settings.h"

Settings::Settings(string settingsfile) : settingsPath(settingsfile)
{
    if(!wxFileExists(settingsfile))
    {
        //Creates xml file and fills it with default values
        SaveSettings();
    }

    LoadSettings(settingsfile);
}

Settings::~Settings()
{
    SaveSettings();
}

void Settings::LoadSettings(string file)
{
    //TODO implement
    wxXmlDocument doc;
}

void Settings::SaveSettings()
{
    wxXmlDocument doc;
    if(!doc.Load(settingsPath))//If not exists create it
    {
        wxFile settings(settingsPath, wxFile::OpenMode::write_excl);
        settings.Close();
        SaveSettings();//Recursive call to avoid to repeat the else statement under here
    }
    else
    {
        wxXmlNode * root=new wxXmlNode(nullptr,wxXML_ELEMENT_NODE,"Settings");
        doc.SetRoot(root);

        wxXmlNode * node=new wxXmlNode(root,wxXML_ELEMENT_NODE,"volume");
        node->AddAttribute("value",std::to_string(savedVolume));

        wxStringOutputStream stream;
        doc.Save(stream);
    }
}