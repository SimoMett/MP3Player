//
// Created by matteo on 16/06/18.
//

#include <algorithm>
#include "Subject.h"

void Subject::attachObserver(shared_ptr<Observer> observer)
{
    observers.push_back(observer);
}

void Subject::detachObserver(shared_ptr<Observer> observer)
{
    observers.erase(std::remove(observers.begin(),observers.end(),observer));
}

void Subject::requestUpdate() const
{
    for(auto elem : observers)
        elem->update();
}