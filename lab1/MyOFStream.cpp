#include "MyOFStream.h"
namespace myFout {
	bool fileExist(const char &_s)
	{
		FILE *f = fopen(&_s, "r");
		if (f == NULL) {
			return false;
		}
		else
		{
			fclose(f);
			return true;
		}
	}

	void MyOFStream::initial()
	{
		intSetting = myFout::DEC;
		sign = false, base = false, boolAsAlfa = false;
	}

	MyOFStream::MyOFStream(const char * _str, fileStatus _status)
	{
		initial();
		if (!fileExist(*_str)) {
			throw logic_error("Failed to open target file");
			return;
		}

		switch (_status)
		{
		case myFout::APPEND: {
			m_oFile = fopen(_str, "a");
			break;
		}
		case myFout::REWRITE:
		{
			m_oFile = fopen(_str, "w");
			break;
		}
		}

		if (m_oFile == NULL) throw logic_error("Failed to open target file");
	}

	void MyOFStream::flush()
	{
	}

	MyOFStream::~MyOFStream()
	{
		fclose(m_oFile);
	}

	//type=sign type + if val >0 
	//				 - if val <0
	void printSign(MyOFStream & o,bool type)
	{
		if (o.getSign())
		{
			if (type)
			{
				o << "+";
			}
			else
			{
				o << "-";
			}
		}
	}

	string printCountSystem(MyOFStream & o)
	{
		string res("(");
		switch (o.getSystemCount())
		{
			case systemCount::BIN:{
				res += "2";
				break;
			}
			case systemCount::OCT:{ res += "8";
				break; 
			}
			case systemCount::DEC:{ res += "10";
				break; 
			}
			case systemCount::HEX: { res += "16";
				break;
			}
		}
		res += ")";
		return res;
	}

	MyOFStream & operator<<(MyOFStream & o, int i)
	{
		if (i != 0)
		{
			printSign(o, i > 0);
		}

		char s[200];
		switch (o.getSystemCount())
		{
		case systemCount::BIN: {
			_itoa(i, s, 2);
			break;
		}
		case systemCount::OCT: { 
			_itoa(i, s, 8);
			break;
		}
		case systemCount::DEC: { 
			_itoa(i, s, 10);
			break;
		}
		case systemCount::HEX: { 
			_itoa(i, s, 16);
			break;
		}
		}
		o << s;
		
		if (o.getBase())
			o << printCountSystem(o);
		return o;
	}

	MyOFStream & operator<<(MyOFStream & o, float f)
	{
		if (f != 0)
		{
			printSign(o, f > 0);
		}
		fprintf(o.m_oFile, "%f", f);

		return o;
	}

	MyOFStream & operator<<(MyOFStream & o, char  c)
	{
		fprintf(o.m_oFile, "%c", c);
		return o;
	}

	MyOFStream & operator<<(MyOFStream & o, bool b)
	{
		if (!o.boolAsAlfa)
			fprintf(o.m_oFile, "%i", b);
		else
		{
			fprintf(o.m_oFile, "%s", (b)?"true":"false");
		}
		return o;
	}

	MyOFStream & operator<<(MyOFStream & o, char * str)
	{
		fprintf(o.m_oFile, "%s", str);
		return o;
	}

	MyOFStream & operator<<(MyOFStream & o, std::string & str)
	{
		fprintf(o.m_oFile, "%s", str.c_str());
		return o;
	}

	MyOFStream & operator<<(MyOFStream & o, ManipulatorFunction mf)
	{
		return (*mf) (o);
	}
}
