#include "PurchaseHistory.h"
#include "PurchaseItem.h"
#include <iomanip>

std::list<PayCheck> PurchaseHistory::getCheckStartFromDate(DateTime & dt)
{
	std::list<PayCheck> res;
	for (std::list<PayCheck>::iterator it = listOfCheck.begin(); it != listOfCheck.end(); ++it)
	{
		if (dt < (*it).getDateTime())
		{
			res.push_back(*it);
		}
	}
	return res;
}

bool PurchaseHistory::isCheckAfterMyDate(PayCheck & _check, DateTime & _myDate)
{
	if (_myDate<_check.getDateTime()) return true;
	return false;
}

PurchaseHistory::PurchaseHistory()
{}

void PurchaseHistory::addCheck(PayCheck & check)
{
	listOfCheck.push_back(check);
}

double PurchaseHistory::AVGforLast3mount()
{
	DateTime dateToday = DateTime::GetCurrentDateTime();
	DateTime dateSub3M = DateTime::subMonthFromDate(dateToday, 3);

	double avgCheck = 0;
	int count = 0;

	std::list<PayCheck> checks = getCheckStartFromDate(dateSub3M);

	for (std::list<PayCheck>::iterator it = checks.begin(); it != checks.end(); ++it)
	{
		avgCheck += (*it).SumOfCheck();
		count++;
	}
	double res = (avgCheck / count);
	return res;
}

void PurchaseHistory::printAll()
{
	for (list<PayCheck>::iterator it = listOfCheck.begin(); it != listOfCheck.end(); ++it)
	{
		(*it).print();
	}
}

bool compareF(PurchaseItem & first, PurchaseItem & second)
{
	if (first.price() > second.price()) return true;
	return false;
}

void printTop5(map<Product, pair<int, double> > _in)
{
	if (_in.size() <= 5) return ;
	else
	{
		for (int i = 0; i < 5; i++)
		{
			int max = (*_in.begin()).second.first;// iMax = 0;
			Product pr = (*_in.begin()).first;
			for (map < Product, pair<int, double>  >::const_iterator it = _in.begin();
				it != _in.end(); ++it)
			{
				if (max < (*it).second.first)
				{
					pr = (*it).first;
					max = (*it).second.first;
				}
			}
			pr.print();
			cout << "(" << max << ")";
			cout << "\n";
			_in.erase(_in.find(pr));
		}
	}	
}

map<Product, pair<int, double> > getMapProductCountSpend(std::list <PayCheck> listOfCheck)
{
	map<Product, pair<int, double> > mapProductCountSpend;
	for (std::list<PayCheck>::iterator it = listOfCheck.begin(); it != listOfCheck.end(); ++it)
	{
		list<PurchaseItem> elements = (*it).getPurchaseList();//1 check
		for (list<PurchaseItem>::iterator iterElem = elements.begin(); iterElem != elements.end(); ++iterElem)
		{
			Product prod((*iterElem).getProduct());
			pair <int, double> c(1, (*iterElem).price());
			if (mapProductCountSpend.find(prod) == mapProductCountSpend.end()) mapProductCountSpend.insert(pair<Product, pair<int, double> >(prod, c));
			else
			{
				(*mapProductCountSpend.find(prod)).second.first++;//int
				(*mapProductCountSpend.find(prod)).second.second += (*iterElem).price();//double
			}
		}
	}
	return mapProductCountSpend;
}

void printMapProductCountSpend(map<Product, pair<int, double> > _in)
{
	for (map < Product, pair<int, double>  >::const_iterator it = _in.begin();
		it != _in.end(); ++it)
	{
		std::cout << (*it).second.first << "\t" << std::setprecision(2) << fixed << (*it).second.second << "\t\t";
		Product pr = (*it).first;
		pr.print();
		cout << "\n";
	}
	cout << "\n\n";
}

void PurchaseHistory::top5Purchase()
{
	map<Product, pair<int, double> > mapProductCountSpend=getMapProductCountSpend(listOfCheck);
	printMapProductCountSpend(mapProductCountSpend);
	printTop5(mapProductCountSpend);
}

void PurchaseHistory::printLastMonthByCategory()
{
	DateTime dateToday = DateTime::GetCurrentDateTime();
	DateTime dateSub1M = DateTime::subMonthFromDate(dateToday, 1);

	map<category, double> mapCategoryMoney;

	std::list<PayCheck> checks = getCheckStartFromDate(dateSub1M);
	for (std::list<PayCheck>::iterator it = checks.begin(); it != checks.end(); ++it)
	{
		list<PurchaseItem> elements = (*it).getPurchaseList();
		for (list<PurchaseItem>::iterator iterElem = elements.begin(); iterElem != elements.end(); ++iterElem)
		{
			Product prod((*iterElem).getProduct());
			if (mapCategoryMoney.find(prod.getCategory()) == mapCategoryMoney.end()) mapCategoryMoney.insert(pair<category, double>(prod.getCategory(), (*iterElem).price()));
			else (*mapCategoryMoney.find(prod.getCategory())).second += (*iterElem).price();
		}
	}
	//categoryToString
	for (map<category, double >::const_iterator it = mapCategoryMoney.begin();
		it != mapCategoryMoney.end(); ++it)
	{
		std::cout << categoryToString((*it).first) << "\t" << it->second << "\n";
	}
}

void PurchaseHistory::top3MostExpensive()
{
	cout << "most expensive itemsof all time\n";

	list <PurchaseItem> list;
	for (std::list<PayCheck>::iterator it = listOfCheck.begin(); it != listOfCheck.end(); ++it)
	{
		std::list<PurchaseItem> check = (*it).getPurchaseList();
		for (std::list<PurchaseItem>::iterator itItem = check.begin(); itItem != check.end(); ++itItem)
		{
			list.push_back((*itItem));
		}
	}
	list.sort(compareF);
	for (int i = 0; i < 3; i++)
	{
		list.front().print();
		//cout << list.front().price() << endl;
		list.pop_front();
	}
	cout << "====end most expensive items of all time";

}

double getAlwaysCost(map<Product, pair<int, double> > _mapProductCountSpend,int _size)
{
	double res = 0;
	int checkCount =_size;

	for (map < Product, pair<int, double>  >::const_iterator it = _mapProductCountSpend.begin();
		it != _mapProductCountSpend.end(); ++it)
	{
		if ((100 * (*it).second.first / checkCount) >= 80)
		{
			res += (*it).second.second;
		}
	}
	return res;
}

double getUsuallyCost(map<Product, pair<int, double> > _mapProductCountSpend, int _size)
{
	double res = 0;
	int checkCount = _size;

	for (map < Product, pair<int, double>  >::const_iterator it = _mapProductCountSpend.begin();
		it != _mapProductCountSpend.end(); ++it)
	{
		if (((100 * (*it).second.first / checkCount) > 20) && (((100 * (*it).second.first / checkCount) < 80)))
		{
			res += (*it).second.second;
		}
	}
	return res;
}

double getOnceCost(map<Product, pair<int, double> > _mapProductCountSpend, int _size)
{
	double res = 0;
	int checkCount = _size;

	for (map < Product, pair<int, double>  >::const_iterator it = _mapProductCountSpend.begin();
		it != _mapProductCountSpend.end(); ++it)
	{
		if ((100 * (*it).second.first / checkCount) <= 20) res += (*it).second.second;
	}
	return res;
}

void PurchaseHistory::printSumInEweryTimeClass()
{
	map<Product, pair<int, double> > mapProductCountSpend = getMapProductCountSpend(listOfCheck);
	printMapProductCountSpend(mapProductCountSpend);
	int checkCount = listOfCheck.size();

	cout << "usually " << getUsuallyCost(mapProductCountSpend,listOfCheck.size())<< "\t" << "once " << getOnceCost(mapProductCountSpend, listOfCheck.size())<<"\t" << " always" << getAlwaysCost(mapProductCountSpend, listOfCheck.size());
}

double PurchaseHistory::vanga()
{
	double result = 0;

	map<Product, pair<int, double> > mapProductCountSpend = getMapProductCountSpend(listOfCheck);
	int checkCount = listOfCheck.size();
	result += getAlwaysCost(mapProductCountSpend,listOfCheck.size());


	DateTime dateToday = DateTime::GetCurrentDateTime();
	DateTime dateSub3M = DateTime::subMonthFromDate(dateToday, 3);
	std::list<PayCheck> checks = getCheckStartFromDate(dateSub3M);

	cout << "last 3 m\n";
	map<Product, pair<int, double> > mapProductCountSpendLast3M = getMapProductCountSpend(checks);
	result += getUsuallyCost(mapProductCountSpendLast3M, mapProductCountSpendLast3M.size());

	return result;
}

PurchaseHistory::~PurchaseHistory()
{
}
