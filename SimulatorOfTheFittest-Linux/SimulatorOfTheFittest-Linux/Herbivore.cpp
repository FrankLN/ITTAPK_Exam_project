#include "Herbivore.h"

Herbivore::Herbivore(float mass)
{
	hungerBar_ = 5;
	//name_ = typeid(this).name();
	//name_ = name_.substr(2);
	hasMoved_ = false;
	hasEaten_ = false;
	age_ = 0;
}

Herbivore::~Herbivore()
{
	//std::cout << "I(Herbivore) died" << std::endl;
}

void Herbivore::show()
{
	std::cout << "Actor:\tHerbivore" << std::endl << "Age:\t" << age_ << std::endl << "Hunger:\t" << hungerBar_ << " out of 10(where 10 is dead of hunger)" << std::endl << std::endl;
}

std::string Herbivore::showToString()
{
	std::string result = "Actor:\tHerbivore\nAge:\t";
	result += age_;
	result += "\nHunger:\t";
	result += hungerBar_;
	result += " out of 10(where 10 is dead of hunger)";

	return result;
}