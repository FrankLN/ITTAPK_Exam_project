#ifndef ACTOR_TYPE_LIST_H
#define ACTOR_TYPE_LIST_H

struct NullType;

template<typename T, typename R>
struct ActorTypeList
{
	typedef T First;
	typedef R Rest;
};

#endif