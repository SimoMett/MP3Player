//
// Created by matteo on 14/07/18.
//

#include "Bitmap.h"


Bitmap::Bitmap(string path) : wxBitmap()
{
    setDirectory(path);
}

void Bitmap::setDirectory(string dir)
{
    directory=dir;
    LoadFile(directory,wxBITMAP_TYPE_ANY);
}