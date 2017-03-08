#include "PurchaseItem.h"
#include <iomanip>

PurchaseItem::PurchaseItem(const PurchaseItem & _in)
{
	count = _in.count;
	product = _in.product;
}

PurchaseItem::PurchaseItem(const Product & _prod, double _count)
{
	product = _prod;
	count = _count;
}

double PurchaseItem::price()
{
	return product.getPrice() * count;
}

void PurchaseItem::print()
{
	cout <<setprecision(2) << fixed << count<<"\tx\t";
	product.print();
	cout << "\t="<<price()<<endl;
}


PurchaseItem::~PurchaseItem()
{
}
