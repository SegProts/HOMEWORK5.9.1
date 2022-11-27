#pragma once
#include "Slot.h"
#include <iostream>

class ExtendModule
{
public:
	ExtendModule(Slot& slot1, Slot& slot2, Slot& slot3);
	Slot listSlots[3]; //Слоты под товары
};

