/***************************************************
Player class, can be used to load a Leitmotiv 
and  play it. 


****************************************************/

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Motiv.hpp"
#include <SFML/Audio.hpp>
#include <atomic>
#include <thread>

class Player
{
    bool mStarted;
    const int id;
    std::atomic<int> mState;
    std::string mAudioFileURL;
    std::thread mThread;
    void playerMain();

public:
    Player(int _id);
    ~Player();
    int getId();
    int getState();
    void play();
    void pause();
    void stop();
    void loadMotiv(std::shared_ptr<Motiv> _motiv);
    void startPlayer();
};


#endif //__PLAYER_H__