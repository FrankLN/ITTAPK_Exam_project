#include "Herbivore.h"
#include <iostream>

Herbivore::Herbivore(float mass)
{
	mass_ = mass; 
	name_ = typeid(this).name();
	name_ = name_.substr(6, name_.find_last_of('*') - 7);
}

void Herbivore::show()
{
	std::cout << "I'm a " << name_ << ", I eat plants. I got a mass of " << mass_ << " kg" << std::endl;
}