#ifndef ACTOR_H
#define	ACTOR_H

#include <string>
#include <vector>

class Actor
{
public:
	virtual ~Actor(){};
	virtual void show() = 0;
};

#endif