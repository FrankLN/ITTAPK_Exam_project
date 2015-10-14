#ifndef ACTOR_H
#define	ACTOR_H

#include <string>

class Actor
{
protected:
	std::string name_;
public:
	virtual void show() = 0;
	virtual std::string getName(){ return name_; }
};

#endif