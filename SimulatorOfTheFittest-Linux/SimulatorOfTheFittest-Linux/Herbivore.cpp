#include "Herbivore.h"

Herbivore::Herbivore(float mass)
{
	hungerBar_ = 5;
	name_ = typeid(this).name();
	name_ = name_.substr(2);
	hasEaten_ = false;
}

Herbivore::~Herbivore()
{
	std::cout << "I(Herbivore) died" << std::endl;
}

void Herbivore::show()
{
	std::cout << "I'm a " << name_ << ", I eat plants. My hunger is " << hungerBar_ << " out of 10(where 10 is dead of hunger)" << std::endl;
}