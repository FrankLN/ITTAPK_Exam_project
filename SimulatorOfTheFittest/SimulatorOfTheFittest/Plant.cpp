#include "Plant.h"
#include <iostream>

Plant::Plant(float mass)
{
	mass_ = mass;
	name_ = typeid(this).name();
	name_ = name_.substr(6, name_.find_last_of('*') - 7);
}

void Plant::show()
{
	std::cout << "I'm a " << name_ << ", with mass: " << mass_ << " kg" << std::endl;
}