#pragma once

#include "Establishment.h"

class Pizzeria : public Establishment
{
public:
	Pizzeria(const string name, const string* menu, int* price, int size);

	void deliverOrder() override;
};

