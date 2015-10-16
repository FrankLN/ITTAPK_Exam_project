#ifndef ACTOR_TYPE_LIST_H
#define ACTOR_TYPE_LIST_H

#include <iostream>
#include <typeinfo>
#include <string>
#include "Plant.h"

namespace myATL
{
	struct NullType{};	

	template<typename T, typename R>
	struct ActorTypeList
	{
		typedef T First;
		typedef R Rest;
	};

	template<>
	struct ActorTypeList<NullType, NullType>
	{
		typedef NullType First;
		typedef NullType Rest;
	};

	template<typename T>
	struct PrintIT
	{
		PrintIT()
		{
			std::string str = typeid(typename T::First).name();

			str = str.substr(0, 1) == "P" ? str.substr(1, 1) == "K" ? str.substr(3) : str.substr(2) : str.substr(1);

			std::cout << "Type:\t" << str << std::endl;
			PrintIT<typename T::Rest>();
		}
	};

	template<>
	struct PrintIT < ActorTypeList<NullType, NullType> >
	{
		PrintIT()
		{
			std::cout << "The TypeList is empty!" << std::endl;
		}
	};

	template<>
	struct PrintIT < NullType >
	{
		PrintIT()
		{
			std::cout << std::endl << "No more types!" << std::endl;
		}
	};

	template<typename TL, typename T>
	struct Push_back;
	
	template<>
	struct Push_back<NullType, NullType>
	{
		typedef NullType type;
	};

	template<typename T>
	struct Push_back<NullType, T>
	{
		typedef ActorTypeList<T, NullType> type;
	};

	template<typename First, typename Rest>
	struct Push_back<NullType, ActorTypeList<First, Rest>>
	{
		typedef ActorTypeList<First, Rest> type;
	};

	template<typename First, typename Rest, typename T>
	struct Push_back<ActorTypeList<First, Rest>, T>
	{
		typedef ActorTypeList<First, typename Push_back<Rest, T>::type> type;
	};

	template<>
	struct Push_back<ActorTypeList<NullType, NullType>, NullType>
	{
		typedef ActorTypeList<NullType, NullType> type;
	};

	template<typename T>
	struct Push_back<ActorTypeList<NullType, NullType>, T>
	{
		typedef ActorTypeList<T, NullType> type;
	};

	template<typename First, typename Rest>
	struct Push_back<ActorTypeList<NullType, NullType>, ActorTypeList<First, Rest> >
	{
		typedef ActorTypeList<First, Rest> type;
	};
	
	template<typename L>
	struct length{};
	
	template<typename First, typename Rest>
	struct length<ActorTypeList<First, Rest>>
	{
		static const int value = 1 + length<Rest>::value;
	};
	
	template<typename First>
	struct length<ActorTypeList<First, NullType>>
	{
		static const int value = 1;
	};
	
	template<>
	struct length<ActorTypeList<NullType, NullType>>
	{
		static const int value = 0;
	};
	
	template<>
	struct length<NullType>
	{
		static const int value = 0;
	};
	
	template<typename TL, size_t I>
	struct AtIndex
	{
		typedef typename AtIndex<typename TL::Rest, I - 1>::type type;
	};
	
	template<typename TL>
	struct AtIndex<TL, 0>
	{
		typedef typename TL::First type;
	};
	
	template<typename T, typename U>
	struct IsSame
	{
		static const bool value = false;
	};
	
	template<typename T>
	struct IsSame<T, T>
	{
		static const bool value = true;
	};
		
}



#endif