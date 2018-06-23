//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_OBSERVER_H
#define MP3PLAYER_OBSERVER_H

class Observer {

public:
    virtual ~Observer(){};

    virtual void update()=0;

};


#endif //MP3PLAYER_OBSERVER_H
