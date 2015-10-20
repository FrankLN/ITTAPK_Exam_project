#include "Plant.h"

Plant::Plant(float mass)
{
	age_ = 0;
}

Plant::~Plant()
{
	//std::cout << "I(Plant) died" << std::endl;
}

void Plant::show()
{
	std::cout << "Actor:\tPlant" << std::endl << "Age:\t" << age_ << std::endl << std::endl;
}

std::string Plant::showToString()
{
	return "Actor:\tPlant\nAge:\t" + std::to_string(age_);
}