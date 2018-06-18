//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_SUBJECT_H
#define MP3PLAYER_SUBJECT_H

#include <vector>
#include <memory>
#include "Observer.h"

using namespace std;

class Subject {

public:
    virtual ~Subject()=0;

    virtual void attachObserver(shared_ptr<Observer> observer);
    virtual void detachObserver(shared_ptr<Observer> observer);
    virtual void requestUpdate();


protected:
    vector<shared_ptr<Observer>> observers;
};


#endif //MP3PLAYER_SUBJECT_H
