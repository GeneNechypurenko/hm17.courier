#include "Pizzeria.h"

Pizzeria::Pizzeria(const string name, const string* menu, int* price, int size)
	:
	Establishment(name, menu, price, size)
{}

void Pizzeria::deliverOrder()
{
	cout << name << endl;
	getOrder();
	cout << "Delivering your order" << endl;
}
