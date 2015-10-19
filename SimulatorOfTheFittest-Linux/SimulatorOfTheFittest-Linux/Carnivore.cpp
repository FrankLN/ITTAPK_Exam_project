#include <algorithm>
#include "Carnivore.h"

Carnivore::Carnivore(float mass)
{
	hungerBar_ = 5;
	name_ = typeid(this).name();
	name_ = name_.substr(2);
	hasMoved_ = false;
	hasEaten_ = false;
}

void Carnivore::show()
{
	std::cout << "I'm a " << name_ << ", I eat meat. My hunger is " << hungerBar_ << " out of 10(where 10 is dead of hunger)" << std::endl;
}