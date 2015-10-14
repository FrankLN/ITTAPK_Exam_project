#ifndef PLANT_H
#define PLANT_H


#include "Actor.h"

class Plant : public Actor
{
public:
	Plant(float mass);
	void show();
};

#endif