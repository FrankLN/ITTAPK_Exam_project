#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include "Actor.h"

class Animal : public Actor
{
protected:
	bool hasEaten_;
public:
	virtual bool hasEaten(){ return hasEaten_; }
	virtual void eat(Actor* actor)
	{ 
		std::cout << "I eat " << actor->getName() << " and i liked it" << std::endl;
		mass_ = mass_ + actor->getMass();
	}
};

#endif