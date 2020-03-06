#include <iostream>
#include <thread>
#include <cassert>
#include "Idea.hpp"
#include "Motiv.hpp"
#include "Player.hpp"

using namespace std;

int main(){
    // Create a Player for the Motivs
    Player p(12);
    // Use case:
    // Create a new Idea
    Idea a(123);
    // Create a new Motiv
    //Motiv m(1234567);
    auto m = make_shared<Motiv>(123222,"../resources/leitmotives/lm_1.wav");

    auto m2 = make_shared<Motiv>(122,"../resources/leitmotives/lm_2.wav");
    // Assign a Motiv to the Idea
    a.assignMotiv(m);


    assert(a.hasMotiv());

    p.loadMotiv(*(a.getAssignedMotiv()));

    p.startPlayer();

    p.play();

    this_thread::sleep_for(chrono::seconds(5));

    p.pause();

    a.assignMotiv(m2);
    p.loadMotiv(*(a.getAssignedMotiv()));
    p.play();

    this_thread::sleep_for(chrono::seconds(2));

    p.stop();

}