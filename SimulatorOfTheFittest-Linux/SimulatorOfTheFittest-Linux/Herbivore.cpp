#include "Herbivore.h"

Herbivore::Herbivore(float mass)
{
	hungerBar_ = 5;
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
	std::cout << return "Actor:\tHerbivore\nAge:\t" + age_ + "\nHunger:\t" + hungerBar_ + " out of 10(where 10 is dead of hunger)";
}