#pragma once

enum ZErrorTypes{
	ZBadConversionError,
	ZOperationNotSupported,
	ZDivisionByZeroException,
	ZWrongNumberOfArguments,
	ZWrongNumberInList
};

#define OUT_STRM std::cout

class ZError
{
public:
	
	static void DoWrite(ZChar* mess)
	{
		std::cout<<mess;
	}

	template <ZErrorTypes T>
	static void Throw()
	{
		OUT_STRM << (_ZC("Error : "));
		Speak<T>();
		OUT_STRM << (_ZC(" , at Line : ")) << Lnum() << " At Character : " << Cnum() << std::endl;
		exit(1);
	}

	static int Lnum();
	static int Cnum();

	template <ZErrorTypes T>
	static void Speak()
	{}


	template <>
	static void Speak<ZBadConversionError>(){
		OUT_STRM<<(_ZC("Un-expected type passed")); 
	}

	template <>
	static void Speak<ZOperationNotSupported>(){
		OUT_STRM<<(_ZC("Operation not supported on types")); 
	}

	template <>
	static void Speak<ZDivisionByZeroException>(){
		OUT_STRM<<(_ZC("Division by Zero")); 
	}

	template <>
	static void Speak<ZWrongNumberOfArguments>(){
		OUT_STRM<<(_ZC("Wrong number of passed arguments")); 
	}

	template <>
	static void Speak<ZWrongNumberInList>(){
		OUT_STRM<<(_ZC("Wrong number of arguments passed in the List")); 
	}
	
};