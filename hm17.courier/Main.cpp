#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

#include "Establishment.h"
#include "Cafe.h"
#include "Courier.h"
#include "Pizzeria.h"
#include "Restaurant.h"

#define MENU 4
#define CAFEMENU 5
#define RESTMENU 6
#define PIZZMENU 8

enum navikeys {

	ENTER = 13,
	ESC = 27,
	UP = 72,
	DOWN = 80
};

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string cafeMenu[CAFEMENU] = { "cafe item 1", "cafe item 2", "cafe item 3", "cafe item 4", "cafe item 5" };
	int cafePrices[CAFEMENU] = { 230, 198, 145, 137, 187 };

	string restMenu[RESTMENU] = { "rest item 1", "rest item 2", "rest item 3", "rest item 4", "rest item 5", "rest item 6" };
	int restPrices[RESTMENU] = { 240, 220, 245, 300, 320, 500 };

	string pizzMenu[PIZZMENU] = { "pizz item 1", "pizz item 2", "pizz item 3", "pizz item 4", "pizz item 5", "pizz item 6", "pizz item 7", "pizz item 8" };
	int pizzPrices[PIZZMENU] = { 180, 190, 220, 187, 220, 200, 232, 245 };

	Courier cour;

	Establishment* est = nullptr;

	Cafe cafe("Cafe", cafeMenu, cafePrices, CAFEMENU);
	Restaurant rest("Restaurant", restMenu, restPrices, RESTMENU);
	Pizzeria pizz("Pizzeria", pizzMenu, pizzPrices, PIZZMENU);

	string menu[]
	{
		"cafe",
		"restaurant",
		"pizzeria",
		"Exit"
	};

	int select = 0;

	while (true) {

		char marker = 149;
		system("cls");

		for (int i = 0; i < MENU; i++)
		{
			if (i == select)
			{
				cout << " " << marker << " ";
				cout << menu[i] << endl;
			}
			else
			{
				cout << "   ";
				cout << menu[i] << endl;
			}
		}

		char action = _getch();
		if (action == 0 || action == 224)
			action = _getch();

		switch (action) {

		case UP:
			select = (select - 1 + MENU) % MENU;
			break;

		case DOWN:
			select = (select + 1) % MENU;
			break;

		case ENTER:
			switch (select) {

			case 0:
				est = &cafe;
				est->addToOrder();
				cour.deliver(est);
				return 0;

			case 1:
				est = &rest;
				est->addToOrder();
				cour.deliver(est);
				return 0;

			case 2:
				est = &pizz;
				est->addToOrder();
				cour.deliver(est);
				return 0;

			case 3:
				return 0;
			}
			break;

		case ESC:
			return 0;
		}
	}
	return 0;
}