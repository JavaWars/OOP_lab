#pragma once
#include "Product.h"
class PurchaseItem
{
private:
	double count;
	Product product;
public:
	PurchaseItem() {}
	PurchaseItem(const PurchaseItem & _in);
	PurchaseItem(const Product & _prod, double _count);
	
	Product getProduct() { return product; }
	
	double price();
	void print();

	~PurchaseItem();
};

