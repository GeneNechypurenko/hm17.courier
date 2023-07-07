#pragma once
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Establishment
{
protected:

	string name;

	struct Menu {
		string* items;
		int* price;
		int size;
	};
	Menu menu;

	struct Order {
		string* items;
		int* price;
		int size;
	};
	Order order;

	void setOrder(int select);
	void selectFromMenu(int select);

public:

	Establishment(const string name, const string* menu, int* price, int size);
	~Establishment();

	void getMenu();
	void getOrder();

	void addToOrder();

	virtual void deliverOrder() = 0;
};

