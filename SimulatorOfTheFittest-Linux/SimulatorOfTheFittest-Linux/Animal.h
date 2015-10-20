#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <vector>
#include "Actor.h"
#include "SharedHelperFunctions.h"

class Animal : public Actor
{
protected:
	bool hasMoved_;
	bool hasEaten_;
	int hungerBar_;
public:
	/*template<typename T>
	void eat(Actor* actor)
	{ 
		std::string result = "someting";
		if (myHelper::IsType<T, Actor>(actor))
			result = "a " + std::string(typeid(T).name()).substr(1);
		//else if (myHelper::IsType<Herbivore, Actor>(actor))
			//result = "Herbivore";
		//else if (myHelper::IsType<Carnivore, Actor>(actor))
			//result = "Carnivore";

		//std::cout << "I ate " << result << " and i liked it" << std::endl;
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