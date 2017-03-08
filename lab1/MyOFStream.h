#ifndef _MyOFStream_
#define _MyOFStream_
#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

namespace myFout {
	//-----------------------
	enum fileStatus
	{
		APPEND,
		REWRITE
	};

	enum systemCount
	{
		BIN,//2
		OCT,//8
		DEC,//10
		HEX//16
	};
	//-----------------------


	class MyOFStream
	{
	private:

		systemCount intSetting;

		FILE * m_oFile;

		bool sign, base, boolAsAlfa;

		void initial();


	public:
		bool getSign() { return sign; }
		bool getBase() { return base; }
		bool getBoolAsAlfa() { return boolAsAlfa; }
		systemCount getSystemCount() {return intSetting; }

		MyOFStream(const char * _str, fileStatus _status);

		MyOFStream() = delete;
		MyOFStream(const MyOFStream & _os) = delete;
		MyOFStream & operator =(const MyOFStream & _os) = delete;

		void flush();

		friend MyOFStream & operator << (MyOFStream & o, int i);
		friend MyOFStream & operator << (MyOFStream & o, float f);
		friend MyOFStream & operator << (MyOFStream & o, char c);
		friend MyOFStream & operator << (MyOFStream & o, bool b);
		friend MyOFStream & operator << (MyOFStream & o, char * str);
		friend MyOFStream & operator << (MyOFStream & o, std::string & str);

		friend MyOFStream & hex(MyOFStream & o);
		friend MyOFStream & dec(MyOFStream & o);
		friend MyOFStream & oct(MyOFStream & o);
		friend MyOFStream & bin(MyOFStream & o);

		friend MyOFStream & noBoolalpha(MyOFStream & o);
		friend 	MyOFStream & boolalpha(MyOFStream & o);
		friend MyOFStream & showbase(MyOFStream & o);
		friend MyOFStream & noShowbase(MyOFStream & o);
		friend MyOFStream & showpos(MyOFStream & o);
		friend MyOFStream & noShowpos(MyOFStream & o);
		~MyOFStream();
	};

	MyOFStream & operator << (MyOFStream & o, int i);

	MyOFStream & operator << (MyOFStream & o, float f);

	MyOFStream & operator << (MyOFStream & o, char c);

	MyOFStream & operator << (MyOFStream & o, bool b);

	MyOFStream & operator << (MyOFStream & o, char * str);

	MyOFStream & operator << (MyOFStream & o, std::string & str);


	typedef MyOFStream & (*ManipulatorFunction) (MyOFStream &);
	MyOFStream & operator << (MyOFStream & o, ManipulatorFunction mf);

	inline MyOFStream & endline(MyOFStream & o)
	{
		o << '\n';
		o.flush();
		return o;
	}

	inline MyOFStream & hex(MyOFStream & o)//16
	{
		o.intSetting = myFout::HEX;
		return o;
	}

	inline MyOFStream & dec(MyOFStream & o)//10
	{
		o.intSetting = myFout::DEC;
		return o;
	}

	inline MyOFStream & oct(MyOFStream & o)//8
	{
		o.intSetting = myFout::OCT;
		return o;
	}

	inline MyOFStream & bin(MyOFStream & o)//2
	{
		o.intSetting = myFout::BIN;
		return o;
	}

	inline MyOFStream & boolalpha(MyOFStream & o)//true or false
	{
		o.boolAsAlfa=true;
		return o;
	}
	inline MyOFStream & noBoolalpha(MyOFStream & o)//1 0
	{
		o.boolAsAlfa=false;
		return o;
	}
	inline MyOFStream & showbase(MyOFStream & o)//(2)
	{
		o.base = true;
		return o;
	}
	inline MyOFStream & noShowbase(MyOFStream & o)//(null)
	{
		o.base=false;
		return o;
	}
	inline MyOFStream & showpos(MyOFStream & o)//(+-)
	{
		o.sign = true;
		return o;
	}
	inline MyOFStream & noShowpos(MyOFStream & o)//(null)
	{
		o.sign = false;
		return o;
	}
}
#endif