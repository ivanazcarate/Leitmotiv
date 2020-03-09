#include "Character.hpp"

Character::Character(int _id) : Idea{_id} {}

Character::Character(int _id, std::string _name, std::string _gender, int _age): 
                     Idea{_id}, mName(_name), mGender(_gender), mAge(_age){};


void Character::setAge(int _age)
{
    mAge = _age;
}

void Character::setName(std::string _name)
{
    mName = _name;
}

void Character::setGender(std::string _gender)
{
    mGender = _gender;
}

int Character::getAge()
{
    return mAge;
}

std::string Character::getName()
{
    return mName;
}

std::string Character::getGender()
{
    return mGender;
}