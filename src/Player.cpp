#include "Player.hpp"

Player::Player(int _id):id(_id), mState(0),mStarted(false),mThread(){}

Player::~Player()
{
    mState = 7;
    if(mThread.joinable()) mThread.join();
}

int Player::getId()
{
    return id;
}

int Player::getState()
{
    return mState;
}
/*
  Load the motiv to be played by the
  Player object.
*/
void Player::loadMotiv(Motiv& _motiv)
{
    mAudioFileURL = _motiv.getAudioURL();
    mState = 5; // Stop the current audio
}

void Player::stop()
{
    mState = 5;
}

void Player::play()
{
    mState = 1;
    //while(music.getStatus() == 2 && mState==1){}
}

void Player::pause()
{
    // change to pausing
    mState = 3;
}

void Player::startPlayer()
{
    if(!mStarted)
    {
        mThread = std::thread(&Player::playerMain,this);
        mStarted = true;
    }
}

void Player::playerMain()
{
    sf::Music music;
    // QnD States: 0 idle, 1 starting, 2 playing, 3 pausing, 4 paused, 5 stopping, 6 stopped
    // States missing : loading a new file -> goes back to...stopped
    while(mState != 7)  // 7 Terminate
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        if(mState == 1)
        {
            if (!music.openFromFile(mAudioFileURL)) return;
            music.play();
            mState = 2;
            // play music ... mState = 2, playing
        }
        if(mState == 3)  // pausing
        {
            music.pause();
            mState = 4; // paused
        }
        if(mState == 5) // stopping
        {
            music.stop();
            mState = 6;  // stopped
        }

    }
}
