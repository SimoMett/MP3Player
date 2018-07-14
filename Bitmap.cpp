//
// Created by matteo on 14/07/18.
//

#include "Bitmap.h"


Bitmap::Bitmap(string path) : directory(path), wxBitmap()
{
    LoadFile(path,wxBITMAP_TYPE_ANY);
}