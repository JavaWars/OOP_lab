#ifndef _Product_
#define _Product_
#include <string>
#include <map>
#include <iostream>
using namespace std;
enum category
{
	FOOD,
	CHEMISTRY,
	HYGIENE,
	FAN,
	OTHER
};

string categoryToString(category _cat);

class Product
{
private:
	double price;
	std::string name;
	category cat;
	void initial();
public:
	Product();
	Product(const Product & _product);
	Product(double _price, std::string _name, category _cat);
	
	void print();

	double getPrice();
	category getCategory() { return cat; }

	bool operator ==( Product & _prod);
	friend bool operator <(const  Product & _prod1, const  Product & _prod2);
	bool operator >(  Product & _prod);
	~Product();
};
#endif _Product_
