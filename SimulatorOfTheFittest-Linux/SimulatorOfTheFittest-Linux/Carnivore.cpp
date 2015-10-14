#include "Carnivore.h"
#include <iostream>
#include <string>
#include <typeinfo>

Carnivore::Carnivore(float mass)
{
	mass_ = mass;
	name_ = typeid(this).name();
	name_ = name_.substr(2);
	hasEaten_ = false;
}

void Carnivore::show()
{
	std::cout << "I'm a " << name_ << ", I eat meat. I got a mass of " << mass_ << " kg" << std::endl;
}