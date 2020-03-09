#include "Player.hpp"

Player::Player(int _id):id(_id),mStarted(false),mThread()
{
    mState = static_cast<int>(PlayerState::idle);
}

Player::~Player()
{
    mState = static_cast<int>(PlayerState::terminated);
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
/**
* Loads a motiv to be played into the player by 
* setting mAudioFileURL to the motiv's URL
*
* @param  _motiv shared pointer to a motiv object 
* @return
*/
void Player::loadMotiv(std::shared_ptr<Motiv> _motiv)
{
    mAudioFileURL = _motiv->getAudioURL();
    mState = static_cast<int>(PlayerState::stopping); 
}

void Player::stop()
{
    mState = static_cast<int>(PlayerState::stopping);
}

void Player::play()
{
    mState = static_cast<int>(PlayerState::starting);
}

void Player::pause()
{
    mState = static_cast<int>(PlayerState::pausing);
}

/**
* Creates a new thread if the Player has not already
* been started. The thread runs the method playerMain()
* which implements the audio player state machine.
*/
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
    // State Machine
    // Run while it is not in "terminated" state
    while(mState != static_cast<int>(PlayerState::terminated))
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        if(mState == static_cast<int>(PlayerState::starting))
        {
            if (!music.openFromFile(mAudioFileURL)) return;
            music.play();
            mState = static_cast<int>(PlayerState::playing);
        }
        // pausing
        if(mState == static_cast<int>(PlayerState::pausing)) 
        {
            music.pause();
            mState = static_cast<int>(PlayerState::paused);
        }
        // stopping
        if(mState == static_cast<int>(PlayerState::stopping))
        {
            music.stop();
            mState = static_cast<int>(PlayerState::stopped);
        }

    }
}
