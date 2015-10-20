#include "Carnivore.h"

Carnivore::Carnivore(float mass)
{
	hungerBar_ = 5;
	hasEaten_ = false;
	age_ = 0;
}

Carnivore::~Carnivore()
{
	//std::cout << "I(Carnivore) died" << std::endl;
}

void Carnivore::show()
{
	std::cout << "Actor:\tCarnivore" << std::endl << "Age:\t" << age_ << std::endl << "Hunger:\t" << hungerBar_ << " out of 10(where 10 is dead of hunger)" << std::endl << std::endl;
}

std::string Carnivore::showToString()
{
	std::string result = "Actor:\tCarnivore\nAge:\t";
	result += age_;
	result += "\nHunger:\t";
	result += hungerBar_;
	result += " out of 10(where 10 is dead of hunger)";

	return result;
}