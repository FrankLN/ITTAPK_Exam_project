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
	/*Animal(Animal&&	other)
	{
		hasMoved_ = other.hasMoved_;
		hasEaten_ = other.hasEaten_;
		hungerBar_ = other.hungerBar_;
		other.hasMoved_ = nullptr;
		other.hasEaten_ = nullptr;
		other.hungerBar_ = nullptr;
	}
	Movable&	operator=(Movable&&	other)
	{
		if (this != &other) {
			delete data_;
			data_ = nullptr;
			std::swap(other.data_, data_);
		}
		return	*this;
	}*/

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