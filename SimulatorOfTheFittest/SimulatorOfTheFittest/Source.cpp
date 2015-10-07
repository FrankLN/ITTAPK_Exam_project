#include "Carnivore.h"
#include "Plant.h"
#include "Herbivore.h"
#include <exception>
#include <iostream>
#include <vector>
#include "WorldMap.h"
#include "Area.h"

void main()
{
	Actor * actor = new Carnivore(42);
	actor->show();
	actor = new Herbivore(42);
	actor->show();
	actor = new Plant(42);
	actor->show();

	Carnivore actors(42);
	actors.show();
}