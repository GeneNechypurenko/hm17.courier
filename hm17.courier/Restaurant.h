#pragma once

#include "Establishment.h"

class Restaurant : public Establishment
{
public:
	Restaurant(const string name, const string* menu, int* price, int size);

	void deliverOrder() override;
};