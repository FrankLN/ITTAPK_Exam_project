#include <random>
#include <boost/smart_ptr.hpp>

#include "Area.h"
#include "SharedHelperFunctions.h"

#define chance 60

Area::Area()
{
	std::random_device rd;
	seed_ = rd();
	
	srand(seed_);

	switch (rand() % 4)
	{
	case 0:
		name_ = "Forrest area";
		break;
	case 1:
		name_ = "Beach area";
		break;
	case 2:
		name_ = "Dessert area";
		break;
	case 3:
		name_ = "Flat area";
		break;
	default:
		name_ = "default Area";
		break;
	}

	actors_ = std::vector<Actor*>();
	generateRandomActors();
}

Area::~Area()
{
	/*for (int i = 0; i < actors_.size(); i++)
	{
		delete actors_[i];
	}*/

	/*for (auto it = actors_.begin(); it != actors_.end(); it++)
	{
		delete *it;
	}*/
}

std::string Area::getName() const
{
	return name_;
}

int Area::getSeed() const
{
	return seed_;
}

int Area::getRandomNumber() const
{
	return rand();
}

void Area::generateRandomActors()
{
	// for testing
	actors_.push_back(new Carnivore(950 + rand() % 100));
	actors_.push_back(new Herbivore(950 + rand() % 100));
	actors_.push_back(new Herbivore(950 + rand() % 100));
	actors_.push_back(new Herbivore(950 + rand() % 100));
	actors_.push_back(new Plant(rand() % 100));

	/*
	while (rand() % 100 < chance)
	{
		actors_.push_back(new Plant(rand() % 100));
	}
	while (rand() % 100 < chance)
	{
		actors_.push_back(new Carnivore(950 + rand() % 100));
	}
	while (rand() % 100 < chance)
	{
		actors_.push_back(new Herbivore(950 + rand() % 100));
	}
	*/
}

void Area::printAllActors()
{
	// c++11 for loop
	for (auto &a : actors_)
	{
		a->show();
	}
}

void Area::act()
{
	// create an iterator that proints to the end of the vetor
	auto end = actors_.end();

	// set hasEaten to false for all animals
	std::for_each(actors_.begin(), end, [](Actor* a)
	{
<<<<<<< HEAD
		if (myHelper::IsType<Animal, Actor>(a))
		{
			static_cast<Animal*>(a)->setHasEaten(false);
		}
	});

	// loop through the vector
	for (auto it = actors_.begin(); it != end; it++)
	{
		if (myHelper::IsType<Carnivore, Actor>(*it))
		{
			//std::cout << (*it)->getName() << ".action()" << std::endl;
			std::cout << "Carnivore.action()" << std::endl;

			// see if there are any herbivores in the vector
			auto herb = std::find_if(actors_.begin(), actors_.end(), [](Actor *a)
			{
				//return a->getName() == "Herbivore";
				return myHelper::IsType<Herbivore, Actor>(a);
			});

			if (herb == actors_.end())
			{
				// count hungerBar up, and erase if it hits max
				if (static_cast<Carnivore*>(*it)->increaseHunger())
				{
					// erase the carnivore from the vector
					it = actors_.erase(it);
				}			
			}
			else
			{
				// erase the herbivore from the vector
				herb = actors_.erase(herb);
				// update hunger and hasEaten
				static_cast<Carnivore*>(*it)->eat();
				// update iterators
				end = actors_.end();
				it += (it > herb ? 1 : 0);
			}
		}
		else if (myHelper::IsType<Herbivore, Actor>(*it))
		{
			//std::cout << (*it)->getName() << ".action()" << std::endl;
			std::cout << "Herbivore.action()" << std::endl;

			// see if there are any plants in the vector
			auto plant = std::find_if(actors_.begin(), actors_.end(), [](Actor *a)
			{
				//return a->getName() == "Plant";
				return myHelper::IsType<Plant, Actor>(a);
			});

			if (plant == actors_.end())
			{
				// count hungerBar up, and erase if it hits max
				if (static_cast<Herbivore*>(*it)->increaseHunger())
				{
					// erase the carnivore from the vector
					it = actors_.erase(it);
				}
			}
			else
			{
				// erase the herbivore from the vector
				plant = actors_.erase(plant);
				// update hunger and hasEaten
				static_cast<Herbivore*>(*it)->eat();
	
				// update iterators
				end = actors_.end();
				it += (it > plant ? 1 : 0);
			}
		}
		else if (myHelper::IsType<Plant, Actor>(*it))
		{
			//std::cout << (*it)->getName() << ".action()" << std::endl;
			std::cout << "Plant.action()" << std::endl;
		}
	}
	
	/*// create an iterator that proints to the end of the vetor
	auto end = actors_.end();

	// set hasEaten to false for all animals
	std::for_each(actors_.begin(), end, [](Actor* a)
	{
=======
>>>>>>> 2cf2e141794e9d59d911cae2658cf6246c2c3629
		if (a->getName() != "Plant")
		{
			static_cast<Animal*>(a)->setHasEaten(false);
		}
	});

	// loop through the vector
	for (auto it = actors_.begin(); it != end; it++)
	{
		if ((*it)->getName() == "Carnivore")
		{
			std::cout << (*it)->getName() << ".action()" << std::endl;

			// see if there are any herbivores in the vector
			auto herb = std::find_if(actors_.begin(), actors_.end(), [](Actor *a)
			{
				return a->getName() == "Herbivore";
			});

			if (herb == actors_.end())
			{
				// count hungerBar up, and erase if it hits max
				if (static_cast<Carnivore*>(*it)->increaseHunger())
				{
					// erase the carnivore from the vector
					it = actors_.erase(it);
					// TODO boost signal
				}			
			}
			else
			{
				// erase the herbivore from the vector
				herb = actors_.erase(herb);
				// update hunger and hasEaten
				static_cast<Carnivore*>(*it)->eat();
				// TODO boost signal
				// update iterators
				end = actors_.end();
				it += (it > herb ? 1 : 0);
			}
		}
		else if ((*it)->getName() == "Herbivore")
		{
			std::cout << (*it)->getName() << ".action()" << std::endl;

			// see if there are any plants in the vector
			auto plant = std::find_if(actors_.begin(), actors_.end(), [](Actor *a)
			{
				return a->getName() == "Plant";
			});

			if (plant == actors_.end())
			{
				// count hungerBar up, and erase if it hits max
				if (static_cast<Herbivore*>(*it)->increaseHunger())
				{
					// erase the carnivore from the vector
					it = actors_.erase(it);
					// TODO boost signal
				}
			}
			else
			{
				// erase the herbivore from the vector
				plant = actors_.erase(plant);
				// update hunger and hasEaten
				static_cast<Herbivore*>(*it)->eat();
				// TODO boost signal
				//boost::signals2::signal<void()>	sig;
				//sig.connect(&Log::print);
				//sig();
				// update iterators
				end = actors_.end();
				it += (it > plant ? 1 : 0);
			}
		}
		else if ((*it)->getName() == "Plant")
		{
			std::cout << (*it)->getName() << ".action()" << std::endl;
		}
<<<<<<< HEAD
	}*/
=======
	}
>>>>>>> 2cf2e141794e9d59d911cae2658cf6246c2c3629

	//std::for_each(actors_.begin(), actors_.end(), [=](Actor *a){ a->action(&actors_); });

	/*
	std::cout << "<<<Before act>>>" << std::endl;
	printAllActors();
	
	size_t s = actors_.size();
	
	for(int i=0; i<s; i++)
	{
		if(myHelper::IsType<Herbivore, Actor>(actors_[i]))
		{
			for (int j = 0; j < s; j++)
			{
				if (myHelper::IsType<Carnivore, Actor>(actors_[j]))
				{
					Carnivore* temp = dynamic_cast<Carnivore*>(actors_[j]);
					if (!temp->hasEaten())
					{
						temp->eat<Herbivore>(actors_[i]);
						delete actors_[i];
						actors_.erase(actors_.begin() + i);
						s = actors_.size();
						i--;
						break;
					}
				}
			}
		}
		else if (myHelper::IsType<Plant, Actor>(actors_[i]))
		{
			for(int j=i; j<s; j++)
			{
				if (myHelper::IsType<Herbivore, Actor>(actors_[j]))
				{
					Herbivore* temp = dynamic_cast<Herbivore*>(actors_[j]);
					if (!temp->hasEaten())
					{
						temp->eat<Plant>(actors_[i]);
						actors_.erase(actors_.begin() + i);
						s = actors_.size();
						i--;
						break;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < s; i++)
	{
		if (!myHelper::IsType<Plant, Actor>(actors_[i]))
		{
			Animal* temp  = dynamic_cast<Animal*>(actors_[i]);
			temp->setHasEaten(false);
			if (temp->increaseHunger())
			{
				actors_.erase(actors_.begin() + i);
				s = actors_.size();
				i--;
			}
				
		}
	}
	
	
	std::cout << "<<<After act>>>" << std::endl;
	printAllActors();
	
	
	std::cout << "<<<New generates>>>" << std::endl;
	generateRandomActors();
	printAllActors();
	*/
<<<<<<< HEAD
}

void Area::move()
{
	
}

=======
}

void Area::move()
{
	
}

>>>>>>> 2cf2e141794e9d59d911cae2658cf6246c2c3629
std::vector<Actor*> *Area::getActors()
{
	return &actors_;
}