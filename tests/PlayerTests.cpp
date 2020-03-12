
#define CATCH_CONFIG_MAIN

#include "../resources/catch/catch.hpp"
#include "../src/Player.hpp"

Player audio_player(1);

TEST_CASE( "Get Id from Player Object" ) {
    REQUIRE( audio_player.getId() == 1 );
}


// To compile:
// g++ -o PlayerTests PlayerTests.cpp ../src/Player.cpp ../src/Motiv.cpp -lsfml-audio -pthread