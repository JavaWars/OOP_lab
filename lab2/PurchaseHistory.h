#pragma once
#include <list>
#include "PayCheck.h"
class PurchaseHistory
{
private:
	//map<Product, pair<int, double> > getMapProductCountSpend();
	std::list <PayCheck> listOfCheck;
	std::list<PayCheck> getCheckStartFromDate(DateTime & dt);
	bool isCheckAfterMyDate(PayCheck & _check,DateTime & _myDate);
public:
	PurchaseHistory();
	void addCheck(PayCheck & check);
	double AVGforLast3mount();
	void printAll();

	
	void top5Purchase();
	void printLastMonthByCategory();
	void top3MostExpensive();//of all time
	void printSumInEweryTimeClass();
	double vanga();

	~PurchaseHistory();
};

