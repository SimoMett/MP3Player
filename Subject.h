//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_SUBJECT_H
#define MP3PLAYER_SUBJECT_H

#include <vector>
#include "Observer.h"

using namespace std;

class Subject {

public:
    virtual ~Subject();

    virtual void attachObserver(Observer* observer);
    virtual void detachObserver(Observer* observer);
    virtual void requestUpdate();


protected:
    vector<Observer*> observers;
};


#endif //MP3PLAYER_SUBJECT_H
