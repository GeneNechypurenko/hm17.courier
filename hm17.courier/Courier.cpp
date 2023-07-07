#include "Courier.h"

void Courier::deliver(Establishment* establishment)
{
    system("cls");
    establishment->deliverOrder();
}
