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
	WorldMap<Area, 10> wm = WorldMap<Area, 10>();

	wm.printAll();
	wm.actAll();
}