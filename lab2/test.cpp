#include "testslib.hpp"

#include "PayCheck.h"
#include "Product.h"
#include "PurchaseHistory.h"
DECLARE_OOP_TEST(Date_timeTest)
{
	cout << "current dateTime\n";
	DateTime::GetCurrentDateTime().print();
}


PurchaseHistory * createHistory()
{
	PurchaseHistory * history = new PurchaseHistory();

	//check1
	PayCheck * check1 = new PayCheck(*new DateTime(2017,1,29,20,16,10));
	Product *p1=new Product(50.21, "Poroshok", category::CHEMISTRY);
	Product *p2 = new Product(28.95, "Grecha", category::FOOD);
	Product *p3 = new Product(21.1, "Мыло", category::HYGIENE);

	PurchaseItem *item1 = new PurchaseItem(*p1, 1);
	PurchaseItem *item2 = new PurchaseItem(*p2, 1.45f);
	PurchaseItem *item3 = new PurchaseItem(*p3, 2);
	check1->addPurchaseItem(*item1);
	check1->addPurchaseItem(*item2);
	check1->addPurchaseItem(*item3);
	history->addCheck(*check1);
	//end check1

	//check2
	PayCheck * check2 = new PayCheck(*new DateTime(2017, 2, 5, 18, 10, 0));
	Product *p4 = new Product(9.75, "Apple", category::FOOD);
	Product *p5 = new Product(20.1, "Orange", category::FOOD);
	Product *p6 = new Product(25.1, "Rice", category::FOOD);
	
	PurchaseItem *item4 = new PurchaseItem(*p4, 1.21f);
	PurchaseItem *item5 = new PurchaseItem(*p5, 0.75f);
	PurchaseItem *item6 = new PurchaseItem(*p6, 2);
	check2->addPurchaseItem(*item4);
	check2->addPurchaseItem(*item5);
	check2->addPurchaseItem(*item6);
	check2->addPurchaseItem(*item2);
	history->addCheck(*check2);
	//end check2

	//check3
	PayCheck * check3 = new PayCheck(*new DateTime(2017, 3, 5, 16, 10, 59));
	Product *p7 = new Product(100, "Dog food", category::OTHER);
	Product *p8 = new Product(23.1, "Shugar", category::FOOD);
	Product *p9 = new Product(4.5, "Solt", category::FOOD);


	PurchaseItem *item7 = new PurchaseItem(*p7, 1.21f);
	PurchaseItem *item8 = new PurchaseItem(*p8, 1.75f);
	PurchaseItem *item9 = new PurchaseItem(*p9, 0.95f);
	check3->addPurchaseItem(*item6);
	check3->addPurchaseItem(*item7);
	check3->addPurchaseItem(*item8);
	check3->addPurchaseItem(*item9);
	check3->addPurchaseItem(*item2);
	history->addCheck(*check3);
	//end check3
	
	//check4
	PayCheck * check4 = new PayCheck(*new DateTime(2016, 12, 25, 16, 10, 59));
	Product *p10 = new Product(4.5, "Solt", category::FOOD);
	Product *p11 = new Product(642, "Robot", category::FAN);
	Product *p12 = new Product(318, "Car", category::FAN);
	Product *p13 = new Product(118, "Vodka", category::FAN);


	PurchaseItem *item10 = new PurchaseItem(*p10, 1.21f);
	PurchaseItem *item11 = new PurchaseItem(*p11, 1.75f);
	PurchaseItem *item12 = new PurchaseItem(*p12, 0.95f);
	PurchaseItem *item13 = new PurchaseItem(*p13, 0.95f);
	check4->addPurchaseItem(*item10);
	check4->addPurchaseItem(*item11);
	check4->addPurchaseItem(*item12);
	check4->addPurchaseItem(*item13);
	check4->addPurchaseItem(*item2);
	check4->addPurchaseItem(*item1);
	history->addCheck(*check4);
	//end check4

	//check5
	PayCheck * check5 = new PayCheck(*new DateTime(2016,11, 29, 12, 10, 59));
	Product *p14 = new Product(20.1, "Бананы", category::FOOD);


	PurchaseItem *item14 = new PurchaseItem(*p14, 1.21f);
	PurchaseItem *item15 = new PurchaseItem(*p1, 1.75f);
	check5->addPurchaseItem(*item14);
	check5->addPurchaseItem(*item8);
	check5->addPurchaseItem(*item3);
	check5->addPurchaseItem(*item2);
	check5->addPurchaseItem(*item7);
	history->addCheck(*check5);
	//end check5

	return history;
}


DECLARE_OOP_TEST(exception_DATE)
{
	ASSERT_THROWS(DateTime *dt = new DateTime(2018, 22, 22, 22, 22, 22),"DateException");
}


DECLARE_OOP_TEST(printAll)
{
	PurchaseHistory * history = createHistory();
	history->printAll();
}


DECLARE_OOP_TEST(printLastMonthByCategory)
{
	PurchaseHistory * history = createHistory();
	history->printLastMonthByCategory();
}


DECLARE_OOP_TEST(avg_check_sum3m)
{
	PurchaseHistory *history = createHistory();
	cout<<history->AVGforLast3mount();
}


DECLARE_OOP_TEST(top5Purchase)
{
	PurchaseHistory * history = createHistory();
	history->top5Purchase();
}


DECLARE_OOP_TEST(top3MostExpensive)
{
	PurchaseHistory * history = createHistory();
	history->top3MostExpensive();
}


DECLARE_OOP_TEST(printSumInEweryTimeClass)
{
	PurchaseHistory * history = createHistory();
	history->printSumInEweryTimeClass();
}


DECLARE_OOP_TEST(vanga_test)
{
	PurchaseHistory * history = createHistory();
	cout<<history->vanga();
}