#ifndef ACTOR_H
#define	ACTOR_H

#include <string>

class Actor
{
public:
	virtual ~Actor(){};
	virtual void show() = 0;
};

#endif