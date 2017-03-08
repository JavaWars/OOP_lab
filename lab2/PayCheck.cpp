#include "PayCheck.h"
#include <exception>
#include <ctime>

DateTime::DateTime()
{
}

DateTime::DateTime(const DateTime & dateTime)
{
	year = dateTime.year;
	month = dateTime.month;
	day = dateTime.day;
	hour = dateTime.hour;
	min = dateTime.min;
	sec = dateTime.sec;
}

DateTime::DateTime(int _year, int _month, int _day, int _hour, int _min, int _sec)
{
	int leapYear = year % 4;

	if (_day < 1 || _day > 31) {
		throw logic_error("DateException");
	}

	if (_month < 1 || _month > 12) {
		throw logic_error("DateException");
	}

	if (_month == 2 && _day > 29 - leapYear) {
		throw logic_error("DateException");
	}

	if (_day > 30 + _month % 2) {
		throw logic_error("DateException");
	}

	
	if (_hour < 0 || _hour>24)
		throw logic_error("DateException");

	if (_min < 0 || _min>60)
		throw logic_error("DateException");

	if (_sec < 0 || _sec>60)
		throw logic_error("DateException");

	year = _year;
	month = _month;
	day = _day;

	hour = _hour;
	min = _min;
	sec = _sec;
}

DateTime DateTime::subMonthFromDate(const DateTime & _dateTime, int _month)
{
	DateTime dateTime(_dateTime);
	dateTime.setNewMonth(dateTime.GetMonth() - _month);
	return dateTime;
}

DateTime DateTime::GetCurrentDateTime()
{
	static DateTime result;

	// current date/time based on current system
	time_t t = time(0);
	struct tm * now = localtime(&t);
	
	result.year = (now->tm_year + 1900);
	result.month = (now->tm_mon + 1);
	result.day = (now->tm_mday);
	result.hour = (now->tm_hour);
	result.min = now->tm_min;
	result.sec = now->tm_sec;

	return result;
}

void DateTime::print()
{
	cout << year << "/" << month << "/" << day << " " << hour << ":" << min << ":" << sec;
}

void DateTime::setNewMonth(int _newMonth)
{
	if (_newMonth <= 0)
	{
		year--;
		_newMonth += 12;
	}

	if (_newMonth > 12)
	{
		year++;
		_newMonth -= 12;
	}

	if (_newMonth>0 && _newMonth<=12)
		month = _newMonth;
}

bool DateTime::operator<(const DateTime & _date)
{
	if (year > _date.year) return false;
	else if (year < _date.year) return true;

	if (month > _date.month) return false;
	else if (month < _date.month) return true;

	if (day > _date.day) return false;
	else if(day < _date.day) return true;

	if (hour > _date.hour) return false;
	else if(hour < _date.hour) return true;

	if (min > _date.hour) return false;
	else if (min < _date.hour) return true;
	
	if(sec > _date.sec) return false;
	else if (sec < _date.sec) return true;
	return true;
}

bool DateTime::operator==(const DateTime & _date)
{
	if ((year == _date.year) && (month == _date.month) && (day == _date.day) &&
		(hour == _date.hour) && (min == _date.hour) && (sec == _date.sec)) return true;
	return false;
}

DateTime::~DateTime()
{
}

//_--------------------------------------------------------------------------------------------------

int initial()
{
	static int maxID = 0;
	maxID++;
	return maxID;
}

PayCheck::PayCheck(DateTime _dt):dateTime(_dt)
{
	ID=initial();
}

void PayCheck::addPurchaseItem(PurchaseItem & _item)
{
	purchaseList.push_back(_item);
}

void PayCheck::print()
{
	cout << "=======check¹" << ID << "=======(date:)"; dateTime.print();cout << "\n";
	for (list<PurchaseItem>::iterator it = purchaseList.begin(); it != purchaseList.end(); ++it)
		(*it).print();
}

double PayCheck::SumOfCheck()
{
	double result=0;

	for (std::list<PurchaseItem>::iterator it = purchaseList.begin(); it != purchaseList.end(); ++it)
	{
		result += (*it).price();
	}

	return result;
}

PayCheck::~PayCheck()
{
}


