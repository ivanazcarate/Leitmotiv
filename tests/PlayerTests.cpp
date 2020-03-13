
#define CATCH_CONFIG_MAIN

#include "../resources/catch/catch.hpp"
#include "../src/Player.hpp"


TEST_CASE("Test if the correct Id is set")
{
    Player audio_player(1);
    REQUIRE(audio_player.getId() == 1);
}

TEST_CASE("Player starts in stopped state")
{
    Player audio_player(1);
    REQUIRE(audio_player.getState() == PlayerState::stopped);
}

TEST_CASE("Method hasStarted returns false")
{
    Player audio_player(1);
    REQUIRE(audio_player.hasStarted() == false);
}

TEST_CASE("Start Player, check if hasStarted returns true")
{
    Player audio_player(1);
    audio_player.startPlayer();
    REQUIRE(audio_player.hasStarted() == true);
}

TEST_CASE("Start Player and load a Motiv")
{
    Player audio_player(1);
    audio_player.startPlayer();
    REQUIRE(audio_player.hasStarted() == true);
    SECTION("Load a motiv")
    {
        audio_player.setAudioFileURL("../resources/leitmotives/lm_1.wav");
        REQUIRE(audio_player.getState() == PlayerState::loading);

    }

}

TEST_CASE("Player changes state from stopped to playing")
{
    Player audio_player(1);
    audio_player.startPlayer();

    SECTION("Check if the Player has started ")
    {
        REQUIRE(audio_player.hasStarted() == true);
    }

    SECTION("Check that it is in stopped stat")
    {
        REQUIRE(audio_player.getState() == PlayerState::stopped);
    }

    SECTION("Call play to start playing")
    {
        audio_player.play();
        REQUIRE(audio_player.getState() == PlayerState::starting);

        SECTION("Call stop to start stopping")
        {
            audio_player.stop();
            REQUIRE(audio_player.getState() == PlayerState::stopping);
        }
    }
}