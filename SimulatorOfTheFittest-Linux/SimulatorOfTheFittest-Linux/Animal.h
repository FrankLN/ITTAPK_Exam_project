#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <vector>
#include "Actor.h"

class Animal : public Actor
{
protected:
	bool hasMoved_;
	bool hasEaten_;
	int hungerBar_;
public:
	virtual bool hasEaten(){ return hasEaten_; }
	/*virtual void eat(Actor* actor)
	{ 
		std::cout << "I ate a " << actor->getName() << " and i liked it" << std::endl;
		hungerBar_--;
		hasEaten_ = true;
	}*/
	virtual void eat()
	{
		hungerBar_--;
		hasEaten_ = true;
	}
	virtual void setHasEaten(bool c)
	{
		hasEaten_ = c;
	}
	virtual bool increaseHunger()
	{
		hungerBar_++;
		if (hungerBar_ >= 10)
			return true;
		return false;
	}
	virtual bool getHasEaten()
	{
		return hasEaten_;
	}
	virtual bool getHasMoved()
	{
		return hasMoved_;
	}
	virtual void setHasMoved(bool c)
	{
		hasMoved_ = c;
	}
};

#endif