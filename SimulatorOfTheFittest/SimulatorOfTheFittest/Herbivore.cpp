#include "Herbivore.h"
#include <iostream>
#include <typeinfo>

Herbivore::Herbivore(float mass)
{
	mass_ = mass; 
	name_ = typeid(this).name();
	name_ = name_.substr(6, name_.find_last_of('*') - 7);
	hasEaten_ = false;
}

void Herbivore::show()
{
	std::cout << "I'm a " << name_ << ", I eat plants. I got a mass of " << mass_ << " kg" << std::endl;
}