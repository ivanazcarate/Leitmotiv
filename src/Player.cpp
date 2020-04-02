#include "Player.hpp"

Player::Player(int _id):id(_id),mStarted(false),mThread()
{
    mState = PlayerState::stopped;
}

Player::~Player()
{
    mState = PlayerState::terminated;
    if(mThread.joinable()) mThread.join();
}

int Player::getId()
{
    return id;
}

PlayerState Player::getState()
{
    return mState;
}

// Return true if the player has been started
bool Player::hasStarted()
{
    return mStarted;
}

void Player::setAudioFileURL(std::string _AudioFileURL)
{
    assert(hasStarted());
    mAudioFileURL = _AudioFileURL;
    mState = PlayerState::loading;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void Player::stop()
{
    assert(hasStarted());
    mState = PlayerState::stopping;
}

void Player::play()
{
    assert(hasStarted());
    mState = PlayerState::starting;
}

void Player::pause()
{
    assert(hasStarted());
    mState = PlayerState::pausing;
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

/*
* This method implements the state machine
* for the audio player.
*/

void Player::playerMain()
{
    sf::Music music;
    while(mState != PlayerState::terminated)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        switch(mState)
        {
            case(PlayerState::starting):
                //if (!music.openFromFile(mAudioFileURL)) return;
                music.play();
                mState = PlayerState::playing;
                break;

            case(PlayerState::pausing):
                music.pause();
                mState = PlayerState::paused;
                break;

            case(PlayerState::stopping):
                music.stop();
                mState = PlayerState::stopped;
                break;

            case(PlayerState::loading):
                if (!music.openFromFile(mAudioFileURL)) return;
                mState = PlayerState::idle;
                break;
            default:
                break;
        }
    }
}
