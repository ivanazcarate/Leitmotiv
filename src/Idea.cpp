#include "Idea.hpp"

Idea::Idea(int id)
{
	this->id = id;
    mMotiv = nullptr;
}

int Idea::getId()
{
	return this->id;
}

bool Idea::hasMotiv()
{
    if(mMotiv == nullptr){ return false;}
    else{ return true;}
}

void Idea::assignMotiv(std::shared_ptr<Motiv> const& motiv)
{
    mMotiv = motiv;

}

std::shared_ptr<Motiv> Idea::getAssignedMotiv()
{
    assert(hasMotiv());
    return mMotiv;
}

void Idea::unassignMotiv()
{
    mMotiv = nullptr;
}