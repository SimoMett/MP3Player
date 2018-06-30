//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_OBSERVER_H
#define MP3PLAYER_OBSERVER_H

class Subject;

class Observer {

public:
    virtual ~Observer(){};

    virtual void update(Subject * subject)=0;

protected:
    Observer(){};
};


#endif //MP3PLAYER_OBSERVER_H
