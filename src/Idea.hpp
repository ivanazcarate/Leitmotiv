#ifndef __IDEA_H__
#define __IDEA_H__

#include <string>
#include <memory>
#include <cassert>
#include "Motiv.hpp"

class Idea
{
    int id;
    std::shared_ptr<Motiv> mMotiv;
public:
	Idea(int id);
	int getId();
    bool hasMotiv();
    void assignMotiv(std::shared_ptr<Motiv> const& motiv);
    std::shared_ptr<Motiv> getAssignedMotiv();
    void unassignMotiv();
};

#endif //__IDEA_H__