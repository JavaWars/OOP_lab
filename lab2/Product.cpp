#include "Product.h"



void Product::initial()
{
	price = 0;
	name = "";
	cat = category::OTHER;
}

//Product::Product()
//{
//	initial();
//}

Product::Product()
{
}

Product::Product(const Product & _product)
{
	price = _product.price;
	name = _product.name;
	cat = _product.cat;
}

Product::Product(double _price, std::string _name, category _cat) : price(_price), name(_name), cat(_cat)
{
}

double Product::getPrice()
{
	return price;
}

void Product::print()
{
	cout << price << "\t" << name << "\t\t" << categoryToString(cat);
}


bool Product::operator==(Product & _prod)
{
	if ((price == _prod.price) && (name == _prod.name) && (cat == _prod.cat)) return true;
	return false;
}

bool Product::operator>(Product & _prod)
{
	return (price > _prod.price);
}

Product::~Product()
{
}

string categoryToString(category _cat)
{
	string res("");
	switch (_cat)
	{
	case category::CHEMISTRY: {res = "CHEMISTRY"; break; }
	case category::FOOD: res = "FOOD"; break;
	case category::HYGIENE: res = "HYGIENE"; break;
	case category::FAN: res = "FAN"; break;
	case category::OTHER: res = "OTHER"; break;
	}
	return res;
}

bool operator<(const Product & _prod1, const Product & _prod2)
{
	return (_prod1.price < _prod2.price);
}
