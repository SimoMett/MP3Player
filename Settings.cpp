//
// Created by matteo on 16/06/18.
//

#include "Settings.h"
#include <exception>
#include <algorithm>

Settings * Settings::singleIstance= nullptr;

void Settings::Istantiate(string settingsfile)
{
    if(singleIstance== nullptr) {
        singleIstance=new Settings(settingsfile);
    }
}

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
        doc.Load(settingsPath,"UTF-8");

        wxXmlNode *root = doc.GetRoot();
        if (root == nullptr || root->GetName() != "Settings")
            throw std::runtime_error("'settings.xml' has a bad format. Default settings will be loaded");

        wxXmlNode *node = root->GetChildren();
        while (node)
        {
            if (node->GetName() == "volume")
            {
                wxXmlAttribute *attributes=node->GetAttributes();
                while(attributes)
                {
                    if(attributes->GetName()=="value")
                    {
                        float val;
                        val=stof(attributes->GetValue().ToStdString());
                        setSavedVolume(val);
                    }
                    attributes=attributes->GetNext();
                }
            }
            node=node->GetNext();
        }
    }

    catch(std::runtime_error &e)
    {
        cerr<<e.what()<<endl;
        //TODO handle exception (load default values)
        setSavedVolume(100);
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
        doc.SetFileEncoding("UTF-8");
        doc.SetVersion("1.0");
        wxXmlNode * root=new wxXmlNode(nullptr,wxXML_ELEMENT_NODE,"Settings");
        doc.SetRoot(root);

        wxXmlNode * node=new wxXmlNode(root,wxXML_ELEMENT_NODE,"volume");
        node->AddAttribute("value",std::to_string(savedVolume));

        wxStringOutputStream stream;
        doc.Save(stream);
        wxFile file(settingsPath,wxFile::OpenMode::write);
        if(file.IsOpened())
        {
            file.Write(stream.GetString());
            file.Close();
        }
    }
}

void Settings::setSavedVolume(float val)
{
    if(val>100 || val <0)
        val=100;
    savedVolume=val;
}