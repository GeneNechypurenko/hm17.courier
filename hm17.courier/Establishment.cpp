#include "Establishment.h"

Establishment::Establishment(const string name, const string* menu, int* price, int size)
	:
	name(name),
	menu{ nullptr, nullptr, 0 },
	order{ nullptr, nullptr, 0 }
{
	this->menu.items = new string[size];
	this->menu.price = new int[size];

	for (int i = 0; i < size; i++)
	{
		this->menu.items[i] = menu[i];
		this->menu.price[i] = price[i];
	}

	this->menu.size = size;
}

Establishment::~Establishment()
{
	if (menu.items != nullptr && menu.price != nullptr)
	{
		delete[] menu.items;
		delete[] menu.price;
	}

	if (order.items != nullptr && order.price != nullptr)
	{
		delete[] order.items;
		delete[] order.price;
	}
}

void Establishment::getMenu()
{
	for (int i = 0; i < menu.size; i++)
		cout << menu.items[i] << " " << menu.price[i] << endl;
	cout << endl;
}

void Establishment::getOrder()
{
	for (int i = 0; i < order.size; i++)
		cout << order.items[i] << " " << order.price[i] << endl;
	cout << endl;
}


void Establishment::setOrder(int select)
{
	if (order.size > 0)
	{
		string* newItems = new string[order.size + 1];
		int* newPrice = new int[order.size + 1];

		for (int i = 0; i < order.size; i++)
		{
			newItems[i] = this->order.items[i];
			newPrice[i] = this->order.price[i];
		}

		newItems[order.size] = this->menu.items[select];
		newPrice[order.size] = this->menu.price[select];

		delete[] this->order.items;
		delete[] this->order.price;

		this->order.items = newItems;
		this->order.price = newPrice;
	}
	else
	{
		this->order.items = new string[1];
		this->order.price = new int[1];

		this->order.items[0] = this->menu.items[select];
		this->order.price[0] = this->menu.price[select];
	}

	order.size++;
}

void Establishment::selectFromMenu(int select)
{
	system("cls");

	char marker = 149;

	for (int i = 0; i < menu.size; i++)
	{
		if (i == select)
		{
			cout << " " << marker << " ";
			cout << menu.items[i] << " " << menu.price[i] << "UAH" << endl;
		}
		else if (i != select)
		{
			cout << "   ";
			cout << menu.items[i] << " " << menu.price[i] << "UAH" << endl;
		}
	}
}

void Establishment::addToOrder()
{
	int select = 0;

	while (true)
	{
		selectFromMenu(select);

		cout << endl << "Press ESC for add to cart and exit" << endl;

		char action = _getch();
		if (action == 0 || action == 224)
			action = _getch();

		if (action == 72)
		{
			select = (select - 1 + menu.size) % menu.size;
		}

		else if (action == 80)
		{
			select = (select + 1) % menu.size;
		}

		else if (action == 13)
		{
			setOrder(select);

			cout << endl << "Your order: " << endl;

			getOrder();

			system("pause");
		}

		else if (action == 27)
		{
			break;
		}
	}
}
