#pragma once

#include "Establishment.h"

class Cafe: public Establishment
{
public:
	Cafe(const string name, const string* menu, int* price, int size);

	void deliverOrder() override;
};

