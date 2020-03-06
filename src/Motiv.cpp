#include "Motiv.hpp"

Motiv::Motiv(int _id, std::string _audioURL):id(_id),mAudioURL(_audioURL){};

int Motiv::getId()
{
    return id;
}

std::string Motiv::getAudioURL()
{
    return mAudioURL;
}