#include "MyOFStream.h"
#include "testslib.hpp"
#include "messages.hpp"

DECLARE_OOP_TEST(exception_in_constructor)
{
	ASSERT_THROWS(
		myFout::MyOFStream fout("C:/Users/Pavel/Desktop/test.tt", myFout::REWRITE),
		Messages::FailedToOpenTargetFile
	);
}

DECLARE_OOP_TEST(standart_type_and_string)
{
	myFout::MyOFStream fout("C:/Users/Pavel/Desktop/test.txt", myFout::REWRITE);
	std::string s("standart_type_and_string_test");
	char ch('A');
	float f = 14.7f;
	fout << 10 << "\t abc\t" << s << "\t" << true << "\t" << f;
}

DECLARE_OOP_TEST(endline_and_append_test)
{
	myFout::MyOFStream fout("C:/Users/Pavel/Desktop/test.txt", myFout::APPEND);
	fout << myFout::endline << myFout::endline << myFout::endline;
}

DECLARE_OOP_TEST(test_bin)
{
	myFout::MyOFStream fout("C:/Users/Pavel/Desktop/test.txt", myFout::APPEND);
	std::string s("test_bin");
	char ch('A');
	float f = 14.7f;

	fout << myFout::bin << myFout::boolalpha << myFout::showbase << myFout::showpos;//2

	fout << 10 << "\t abc\t" << s << "\t" << true << "\t" << f << myFout::endline;

	
}

DECLARE_OOP_TEST(test_oct)
{
	myFout::MyOFStream fout("C:/Users/Pavel/Desktop/test.txt", myFout::APPEND);
	std::string s("test_oct");
	char ch('A');
	float f = 14.7f;

	fout << myFout::oct << myFout::noBoolalpha << myFout::noShowbase;//8 int (null)

	fout << 10 << "\t abc\t" << s << "\t" << true << "\t" << f << myFout::endline;

}

DECLARE_OOP_TEST(test_hex)
{
	myFout::MyOFStream fout("C:/Users/Pavel/Desktop/test.txt", myFout::APPEND);
	std::string s("test_oct");
	char ch('A');
	float f = 14.7f;

	fout <<myFout::showbase<< myFout::hex << 10 << "\t abc\t" << s << "\t" << true << "\t" << f << myFout::endline;//16
}