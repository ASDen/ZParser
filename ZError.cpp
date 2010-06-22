#include "stdafx.h"


template<class T>
inline
static void ZError::DoWrite(T mess)
{
	std::cout<<mess<<std::endl;
}

template <ZErrorTypes T>
static void ZError::Throw()
{
	Speak<T>();
	exit();
}

template <>
static void ZError::Speak<ZBadConversionError>()
{
	DoWrite(_ZC("Error un-expected type passed")); 
}