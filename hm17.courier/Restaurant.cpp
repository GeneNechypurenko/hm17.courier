#include "Restaurant.h"

Restaurant::Restaurant(const string name, const string* menu, int* price, int size)
	:
	Establishment(name, menu, price, size)
{}

void Restaurant::deliverOrder()
{
	cout << name << endl;
	getOrder();
	cout << "Delivering your order" << endl;
}
