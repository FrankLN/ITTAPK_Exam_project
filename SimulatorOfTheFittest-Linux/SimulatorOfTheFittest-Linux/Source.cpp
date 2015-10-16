#include "Carnivore.h"
#include "Plant.h"
#include "Herbivore.h"
#include <exception>
#include <iostream>
#include <vector>
#include "WorldMap.h"
#include "Area.h"
#include "Simulation.cpp"
#include <boost/smart_ptr.hpp>

int main()
{
	WorldMap<Area, 1> wm = WorldMap<Area, 1>();
	wm.actAll();
	wm.actAll();
	wm.actAll();
	wm.actAll();
		
	/*Actor* aPtr;
	
	aPtr = new Plant(10);
	
	bool test = myHelper::IsType<Plant, Actor>(aPtr);	
	std::cout << test << std::endl;
	
	test = myHelper::IsType<Herbivore, Actor>(aPtr);
	std::cout << test << std::endl;*/
	
	Simulator mySimulator;
	mySimulator.initiate();
	
	return 0;
}