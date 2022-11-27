#include "ExtendModule.h"

ExtendModule::ExtendModule(Slot& slot1, Slot& slot2, Slot& slot3)
{
	ExtendModule::listSlots[0] = slot1;
	ExtendModule::listSlots[1] = slot2;
	ExtendModule::listSlots[2] = slot3;
}