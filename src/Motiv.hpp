/*
Class which describes a Motiv
*/
#ifndef __MOTIV_H__
#define __MOTIV_H__

#include <string>

class Motiv{
	int id;
    std::string mAudioURL;
public:
	Motiv(int _id, std::string _audioURL);
	int getId();
    std::string getAudioURL();
};

#endif