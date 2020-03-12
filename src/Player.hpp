/***************************************************
(Audio)Player class, which can be used to load a Leitmotiv 
and  play it. 


****************************************************/

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Motiv.hpp"
#include <SFML/Audio.hpp>
#include <atomic>
#include <thread>
#include <cassert>
/*
Enum class with the states
of the state machine
*/
enum class PlayerState
{
    idle,
    starting,
    playing,
    pausing,
    paused,
    stopping,
    stopped,
    terminated
};


class Player
{
    const int id;
    bool mStarted;
    std::atomic<PlayerState> mState;
    std::string mAudioFileURL;
    std::thread mThread;
    void playerMain();

public:
    Player(int _id);
    ~Player();
    int getId();
    PlayerState getState();
    bool hasStarted();
    void play();
    void pause();
    void stop();
    void loadMotiv(std::shared_ptr<Motiv> _motiv);
    void startPlayer();
};

#endif //__PLAYER_H__