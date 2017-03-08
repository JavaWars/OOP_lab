#include <iostream>
#include "MyOFStream.h"
#include <string>
#include <thread>
void test();
//int main()
//{
//	test();
//	return 0;
//}
void test()
{
	try
	{
		myFout::MyOFStream fout("C:/Users/Pavel/Desktop/test.txt", myFout::REWRITE);
		std::string s("def");
		char ch('A');
		float f = 14.7f;
		fout << 10 << "\t abc\t" << s << "\t" << true << "\t" << f << myFout::endline;
		//
		fout << myFout::bin << myFout::boolalpha << myFout::showbase << myFout::showpos;//2

		fout << 10 << "\t abc\t" << s << "\t" << true << "\t" << f << myFout::endline;

		fout << myFout::oct << myFout::noBoolalpha << myFout::noShowbase;//8 int (null)

		fout << 10 << "\t abc\t" << s << "\t" << true << "\t" << f << myFout::endline;

		fout << myFout::hex << 10 << "\t abc\t" << s << "\t" << true << "\t" << f << myFout::endline;//16

		myFout::MyOFStream exceptionTest("C:/Users/Pavel/Desktop/test.tt", myFout::APPEND);
	}
	catch (std::logic_error& e)
	{
		std::cout << e.what();
	}

	std::this_thread::sleep_for(5s);
}