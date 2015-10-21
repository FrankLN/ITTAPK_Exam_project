#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include "Actor.h"

class Plant : public Actor
{
public:
	Plant();
	~Plant();
	void show();
	std::string showToString();
};

#endif