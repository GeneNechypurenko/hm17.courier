#include "Cafe.h"

Cafe::Cafe(const string name, const string* menu, int* price, int size)
    :
	Establishment(name, menu, price, size)
{}

void Cafe::deliverOrder()
{
	cout << name << endl;
	getOrder();
	cout << "Delivering your order" << endl;
}
