#ifndef ACTOR_H
#define	ACTOR_H

#include <string>

class Actor
{
protected:
	float mass_;
	std::string name_;
public:
	virtual void show() = 0;
	virtual std::string getName(){ return name_; }
	virtual float getMass(){ return mass_; }
};

#endif