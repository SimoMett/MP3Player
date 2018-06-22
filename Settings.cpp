//
// Created by matteo on 16/06/18.
//

#include "Settings.h"
#include <exception>
#include <algorithm>

Settings::Settings(string cfg) : settingsPath(cfg)
{

    if (!wxFileExists(cfg)) {
        //Creates xml file and fills it with default values
        SaveSettings();
    } else
        LoadSettings(cfg);
}

Settings::~Settings()
{
    SaveSettings();
}

void Settings::LoadSettings(string file)
{
    try {
        //TODO implement
        wxXmlDocument doc;
        doc.Load(settingsPath);

        wxXmlNode *root = doc.GetRoot();
        if (root == nullptr || root->GetName() != "Settings")
            throw std::runtime_error("'settings.xml' has a bad format. Default settings will be loaded");

        wxXmlNode *node = root->GetChildren();
        while (node) {
            if (node->GetName() == "volume") {
                wxString value;
                node->GetAttribute("volume", &value);
                cout << "value = " + value << endl;
            }
        }
    }

    catch(std::runtime_error &e)
    {
        cerr<<e.what()<<endl;
        //TODO handle exception (load default values)
        savedVolume=100;
        SaveSettings();
    }

}

void Settings::SaveSettings()
{
    wxXmlDocument doc(settingsPath);
    if(!wxFileExists(settingsPath))
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

void Settings::setSavedVolume(float val)
{
    if(val>100 || val <0)
        val=100;
    savedVolume=val;
}