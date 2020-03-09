/***************************************************
Character class. Represents a character, derived
from the Idea class.

****************************************************/
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <string>
#include "Idea.hpp"

class Character: public Idea{
    int mAge;
    std::string mName;
    std::string mGender;
public:
    Character(int _id);
    Character(int _id, std::string _name, std::string _gender, int _age);
    void setAge(int _age);
    void setName(std::string _name);
    void setGender(std::string _gender);
    int getAge();
    std::string getName();
    std::string getGender();
};

#endif