#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <list>
#include "PurchaseItem.h"


class DateTime
{
private:
	int year;
	int month;
	int day;

	int hour;
	int min;
	int sec;
public:
	DateTime();
	DateTime(const DateTime & dateTime );
	DateTime(int _year, int _mount, int _day, int _hour, int _min, int _sec);
	static DateTime subMonthFromDate(const DateTime & _dateTime, int _month);
	static DateTime GetCurrentDateTime();
	void print();

	int GetMonth() { return month; }
	void setNewMonth(int _newMonth);

	bool operator < (const DateTime & _date);
	bool operator ==(const DateTime & _date);
	~DateTime();
};

class PayCheck
{
private:
	int ID;
	DateTime dateTime;
	std::list<PurchaseItem> purchaseList;
public:
	PayCheck(DateTime _dt);

	void print();
	double SumOfCheck();

	void addPurchaseItem(PurchaseItem & _item);
	
	DateTime getDateTime() { return dateTime; }
	std::list<PurchaseItem> getPurchaseList() { return purchaseList; }

	~PayCheck();
};

