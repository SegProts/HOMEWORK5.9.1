#include <string>
#include <fstream>
#include "Slot.h"

void Slot::SlotLoad(Snack itemListSlot1, Snack itemListSlot2, Snack itemListSlot3)
{
	//Записываем в ячейки слота загруженные в них снеки
	Slot::listSnakeSlot[0] = itemListSlot1.indexProductSnake;
	Slot::listSnakeSlot[1] = itemListSlot2.indexProductSnake;
	Slot::listSnakeSlot[2] = itemListSlot3.indexProductSnake;
}