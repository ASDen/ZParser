#pragma once

enum ZErrorTypes{
	ZBadConversionError,
	ZOperationNotSupported,
	ZDivisionByZeroException
};

class ZError
{
public:
	
	static void DoWrite(ZChar* mess)
	{
		std::cout<<mess<<std::endl;
	}

	template <ZErrorTypes T>
	static void Throw()
	{
		Speak<T>();
		exit(1);
	}

	template <ZErrorTypes T>
	static void Speak()
	{}


	template <>
	static void Speak<ZBadConversionError>(){
		DoWrite(_ZC("Error un-expected type passed")); 
	}

	template <>
	static void Speak<ZOperationNotSupported>(){
		DoWrite(_ZC("Operation not support on types")); 
	}

	template <>
	static void Speak<ZDivisionByZeroException>(){
		DoWrite(_ZC("Division by Zero")); 
	}
};