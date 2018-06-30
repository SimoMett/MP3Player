//
// Created by matteo on 16/06/18.
//

#include <algorithm>
#include "Subject.h"

Subject::~Subject() {}

void Subject::attachObserver(Observer* observer)
{
    observers.push_back(observer);
}

void Subject::detachObserver(Observer* observer)
{
    observers.erase(std::remove(observers.begin(),observers.end(),observer));
}

void Subject::requestUpdate()
{
    for(auto elem : observers)
        elem->update(this);
}