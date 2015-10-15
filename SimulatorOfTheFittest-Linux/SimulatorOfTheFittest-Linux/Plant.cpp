#include "Plant.h"

Plant::Plant(float mass)
{
	name_ = typeid(this).name();
	name_ = name_.substr(2);
}

Plant::~Plant()
{
	std::cout << "I(Plant) died" << std::endl;
}

void Plant::show()
{
	std::cout << "I'm a " << name_ << std::endl;
}
