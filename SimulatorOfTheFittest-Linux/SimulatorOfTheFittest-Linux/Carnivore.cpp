#include <algorithm>
#include "Carnivore.h"

Carnivore::Carnivore()
{
	hungerBar_ = 5;
	//name_ = typeid(this).name();
	//name_ = name_.substr(2);
	hasMoved_ = false;
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
	result += std::to_string(age_);
	result += "\nHunger:\t";
	result += std::to_string(hungerBar_);
	result += " out of 10(where 10 is dead of hunger)";

	return result;
}