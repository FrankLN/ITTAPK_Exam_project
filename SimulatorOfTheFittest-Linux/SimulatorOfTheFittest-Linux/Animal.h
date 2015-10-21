#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include "Actor.h"

class Animal : public Actor
{
protected:
	bool hasMoved_;
	bool hasEaten_;
	int hungerBar_;
public:
	virtual bool eat()
	{
		if (hungerBar_ > 0)
		{
			hungerBar_--;
			hasEaten_ = true;
			return true;
		}
		return false;
	}
	
	virtual void setHasEaten(bool c)
	{
		hasEaten_ = c;
	}
	
	virtual bool increaseHunger()
	{
		// increase hunger
		hungerBar_++;
		
		// return true if hunger reaches 10
		if (hungerBar_ >= 10)
		{
			return true;
		}
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