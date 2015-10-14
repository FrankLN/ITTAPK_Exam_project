#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/mpl/list.hpp>
#include "Animal.h"
#include "Carnivore.h"
#include "WorldMap.h"
#include "Area.h"

namespace sc = boost::statechart;
namespace mpl = boost::mpl;

struct EvStart : sc::event< EvStart > {};
struct EvPauseRun : sc::event< EvPauseRun > {};
struct EvLogOnOff : sc::event< EvLogOnOff > {};
struct EvSimulationFinished : sc::event< EvSimulationFinished > {};
struct EvCancel : sc::event< EvCancel > {};

struct SimulatorSetup;
struct Running;
struct Paused;
struct Finished;
struct Canceled;
struct LogEnabled;
struct LogDisabled;


struct Simulator : sc::state_machine< Simulator, SimulatorSetup >
{ 

};

struct SimulatorSetup : sc::simple_state < SimulatorSetup, Simulator >
{
	typedef sc::transition< EvStart, Running> reactions;

	SimulatorSetup()
	{	
		std::cout << "SimulatorSetup Entered" << std::endl;
	}

	~SimulatorSetup()
	{
		std::cout << "SimulatorSetup Exited" << std::endl;
	}
};

struct Canceled : sc::simple_state < Canceled, Simulator >
{
	Canceled()
	{
		std::cout << "Canceled Entered" << std::endl;
	}

	~Canceled()
	{
		std::cout << "Canceled Exited" << std::endl;
	}
};

struct Paused : sc::simple_state < Paused, Simulator >
{
	typedef sc::transition< EvPauseRun, Running> reactions;

	Paused()
	{
		std::cout << "Paused Entered" << std::endl;
	}

	~Paused()
	{
		std::cout << "Paused Exited" << std::endl;
	}
};

struct Finished : sc::simple_state < Finished, Simulator >
{
	Finished()
	{
		std::cout << "Finished Entered" << std::endl;
	}

	~Finished()
	{
		std::cout << "Finished Exited" << std::endl;
	}
};

struct Running : sc::simple_state < Running, Simulator, LogEnabled >
{
	typedef mpl::list < sc::transition< EvCancel, Canceled>,
		sc::transition< EvSimulationFinished, Finished>,
		sc::transition< EvPauseRun, Paused> > reactions;
	
	Running()
	{
		std::cout << "Running Entered" << std::endl;
	}

	~Running()
	{
		std::cout << "Running Exited" << std::endl;
	}
};

struct LogEnabled : sc::simple_state < LogEnabled, Running >
{
	typedef sc::transition< EvLogOnOff, LogDisabled> reactions;

	LogEnabled()
	{
		std::cout << "LogEnabled Entered" << std::endl;
	}

	~LogEnabled()
	{
		std::cout << "LogEnabled Exited" << std::endl;
	}
};

struct LogDisabled : sc::simple_state < LogDisabled, Running >
{
	typedef sc::transition< EvLogOnOff, LogEnabled> reactions;

	LogDisabled()
	{
		std::cout << "LogDisabled Entered" << std::endl;
	}

	~LogDisabled()
	{
		std::cout << "LogDisabled Exited" << std::endl;
	}
};
 
