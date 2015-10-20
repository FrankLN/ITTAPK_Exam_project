#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/mpl/list.hpp>
#include <boost/algorithm/string.hpp>


#include <iostream>
#include <string>
#include <cstddef>

#include "Animal.h"
#include "Carnivore.h"
#include "WorldMap.h"
#include "Area.h"
#include "SharedHelperFunctions.h"

#define NUM_THREADS 5

namespace sc = boost::statechart;
namespace mpl = boost::mpl;

struct EvStart : sc::event< EvStart > {};
struct EvPauseRun : sc::event< EvPauseRun > {};
struct EvLogOnOff : sc::event< EvLogOnOff > {};
struct EvSimulationFinished : sc::event< EvSimulationFinished > {};
struct EvCancel : sc::event< EvCancel > {};
struct EvReset : sc::event< EvReset >{};

struct SimulatorSetup;
struct Running;
struct Paused;
struct Finished;
struct Canceled;
struct LogEnabled;
struct LogDisabled;


struct Simulator : sc::state_machine< Simulator, SimulatorSetup >
{ 
	WorldMapHolder* wmP;
};

struct SimulatorSetup : sc::simple_state < SimulatorSetup, Simulator >
{
public:
	typedef sc::transition< EvStart, Running> reactions;

	SimulatorSetup()
	{	
		std::cout << "SimulatorSetup Entered" << std::endl;
		std::string input;
		
		bool done = false;
		while (!done)
		{
			std::cout << "If you want a X * X world insert 'X'" << std::endl << "If you want a X * Y world insert 'X Y'" << std::endl;
			std::cout << "Please insert the wanted simulation size: ";
			std::getline(std::cin, input);
			
			size_t last = input.find_last_of(" ");
			size_t first = input.find(" ");
		
			if (last == first && input != "" && input.find_first_not_of("0123456789 ") == std::string::npos)
			{
				if (first == std::string::npos)
				{
					a = std::stoi(input);
					b = a;
					done = true;
				}
				else
				{
					a = std::stoi(input.substr(0, first) );
					b = std::stoi(input.substr(first) );
					done = true;
				}
			}
			else
			{
				std::cout << "Error: Invalid input" << std::endl << std::endl;
			}
		}
	}

	~SimulatorSetup()
	{
		//std::cout << "SimulatorSetup Exited" << std::endl;		
		context<Simulator>().wmP = GetWorldMap::getWorldMap(a, b);
	}
	
private:
	int a, b;
};

struct Canceled : sc::simple_state < Canceled, Simulator >
{
	typedef sc::transition< EvReset, SimulatorSetup > reactions;
	Canceled()
	{
		std::cout << "Canceled Entered";
	}

	~Canceled()
	{
		//std::cout << "Canceled Exited" << std::endl;
	}
};

struct Paused : sc::simple_state < Paused, Simulator >
{
	typedef mpl::list < sc::transition< EvPauseRun, Running >,
						sc::transition< EvReset, SimulatorSetup > > reactions;

	Paused()
	{
		std::cout << "<=----------------Paused-----------------=>" << std::endl;
	}

	~Paused()
	{
		//std::cout << "Paused Exited" << std::endl;
	}
};

struct Finished : sc::simple_state < Finished, Simulator >
{
	typedef sc::transition< EvReset, SimulatorSetup > reactions;
	Finished()
	{
		std::cout << "Finished Entered";
	}

	~Finished()
	{
		//std::cout << "Finished Exited" << std::endl;
	}
};

struct Running : sc::simple_state < Running, Simulator, LogEnabled >
{
	typedef mpl::list < sc::transition< EvCancel, Canceled>,
		sc::transition< EvSimulationFinished, Finished>,
		sc::transition< EvPauseRun, Paused> > reactions;



	Running()
	{

	}

	~Running()
	{
		//std::cout << "Running Exited" << std::endl;
	}
};

struct LogEnabled : sc::simple_state < LogEnabled, Running >
{
	typedef sc::transition< EvLogOnOff, LogDisabled> reactions;

	LogEnabled()
	{
		//context<Simulator>().myStartThread();
		std::cout << "<=---------Running: LogEnabled-----------=>" << std::endl;
	}

	~LogEnabled()
	{
		//std::cout << "LogEnabled Exited" << std::endl;
	}
};


struct LogDisabled : sc::simple_state < LogDisabled, Running >
{
	typedef sc::transition< EvLogOnOff, LogEnabled> reactions;

	LogDisabled()
	{
		std::cout << "<=---------Running: LogDisabled----------=>" << std::endl;
	}

	~LogDisabled()
	{
		//std::cout << "LogDisabled Exited" << std::endl;
	}
};
 
