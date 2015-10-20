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

void start();

int main()
{
	//WorldMapHolder* ptr = new WorldMap<Area, 1>();
	//
	//ptr->actAll();
	//std::cout << std::endl;
	//
	//ptr = new WorldMap<Area, 2>();
	//
	//ptr->actAll();
		
	/*Actor* aPtr;
	
	aPtr = new Plant(10);
	
	bool test = myHelper::IsType<Plant, Actor>(aPtr);	
	std::cout << test << std::endl;
	
	test = myHelper::IsType<Herbivore, Actor>(aPtr);
	std::cout << test << std::endl;*/
	
	//start();

	WorldMap<Area, 2> wm = WorldMap<Area, 2>();

	wm.actAll();
	wm.actAll();
	wm.actAll();
	wm.actAll();
	wm.actAll();
	wm.actAll();
	wm.actAll();
	wm.actAll();
	

	std::cout << "----------------------------------" << std::endl;

	wm.printAllActors();
	
	return 0;
}

void start()
{
	Simulator mySimulator;
	bool finish = false;
	bool quit = false;
	bool reset = false;

	while (!finish && !quit)
	{
		finish = true;
		for(int i = 0; i < 20 ; i++) std::cout << std::endl;
		std::cout << "<=--------Simulator of the fittest-------=>" << std::endl;
		std::cout << "<=----------------Main menu--------------=>" << std::endl;
		std::cout << "<=-----------------1. Start--------------=>" << std::endl;
		std::cout << "<=-----------------2. Quit---------------=>" << std::endl;
		std::cout << "<=--Select option: ";


		int option;
		std::cin >> option;
		std::string str;
		std::getline(std::cin, str);

		switch (option)
		{
		case 1:
			for (int i = 0; i < 20; i++) std::cout << std::endl;
			mySimulator.initiate();

			for (int i = 0; i < 20; i++) std::cout << std::endl;
			std::cout << "<=--------Simulator of the fittest-------=>" << std::endl;
			mySimulator.process_event(EvStart());
			break;
		case 2:
			quit = true;
			break;
		default:
			finish = false;
		}
	}

	while (!quit && !reset)
	{
		std::cout << "<=-----------------1. Quit---------------=>" << std::endl;
		std::cout << "<=-----------------2. Pause/Resume-------=>" << std::endl;
		std::cout << "<=-----------------3. Reset--------------=>" << std::endl;
		std::cout << "<=-----------------4. Toggle log---------=>" << std::endl;
		std::cout << "<=--Select option: ";

		int option;
		std::cin >> option;
		std::string str;
		std::getline(std::cin, str);

		switch (option)
		{
		case 1:
			quit = true;
			break;
		case 2:
			for (int i = 0; i < 20; i++) std::cout << std::endl;
			std::cout << "<=--------Simulator of the fittest-------=>" << std::endl;
			mySimulator.process_event(EvPauseRun());
			break;
		case 3:
			reset = true;
			break;
		case 4:
			for (int i = 0; i < 20; i++) std::cout << std::endl;
			std::cout << "<=--------Simulator of the fittest-------=>" << std::endl;
			mySimulator.process_event(EvLogOnOff());
			break;

		}
	}


	if (reset)
		start();
}