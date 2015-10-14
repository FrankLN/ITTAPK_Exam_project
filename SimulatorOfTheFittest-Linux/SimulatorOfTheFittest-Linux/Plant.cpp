#include "Plant.h"
#include <iostream>
#include <typeinfo>

Plant::Plant(float mass)
{
	mass_ = mass;
	name_ = typeid(this).name();
	name_ = name_.substr(2);
}

void Plant::show()
{
	std::cout << "I'm a " << name_ << ", with mass: " << mass_ << " kg" << std::endl;
}
