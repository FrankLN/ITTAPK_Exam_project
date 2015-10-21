#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/statechart/custom_reaction.hpp>
#include <boost/mpl/list.hpp>
#include <boost/algorithm/string.hpp>

#include <iostream>

namespace sc = boost::statechart;
namespace mpl = boost::mpl;

struct EvStart : sc::event< EvStart > {};
struct EvPauseRun : sc::event< EvPauseRun > {};
struct EvSimulationFinished : sc::event< EvSimulationFinished > {};
struct EvCancel : sc::event< EvCancel > {};

struct SimulatorSetup;
struct Running;
struct Paused;
struct Finished;
struct Canceled;

struct Simulator : sc::state_machine< Simulator, SimulatorSetup >
{ 
};

struct SimulatorSetup : sc::simple_state < SimulatorSetup, Simulator >
{
	typedef sc::transition< EvStart, Running> reactions;

	SimulatorSetup()
	{
		std::cout << "SimulatorSetup" << std::endl;
	}
};

struct Running : sc::simple_state < Running, Simulator>
{
	typedef mpl::list <	sc::transition< EvSimulationFinished, Finished>,
						sc::transition< EvPauseRun, Paused> > reactions;

	Running()
	{
		std::cout << "Running" << std::endl;
	}
};

struct Canceled : sc::simple_state < Canceled, Simulator >
{
	Canceled()
	{
		std::cout << "Canceled" << std::endl;
	}
};

struct Paused : sc::simple_state < Paused, Simulator >
{
	typedef mpl::list < sc::transition< EvPauseRun, Running >,
						sc::transition< EvCancel, Canceled > > reactions;

	Paused()
	{
		std::cout << "Paused" << std::endl;
	}
};

struct Finished : sc::simple_state < Finished, Simulator >
{
	Finished()
	{
		std::cout << "Finished" << std::endl;
	}
};