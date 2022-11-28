#include <iostream>
#include "Snack.h"
#include "Slot.h"
#include "ExtendModule.h"

using namespace std;

Snack findNameSnake(Snack listSnacks[], int index);
const int countSnack = 9; //Â ðàáî÷åì âàðèàíòå ìîæíî âûíåñòè òàêèå çíà÷åíèÿ â îòäåëüíûé êëàññ(Êëàññ äëÿ íàñòðéîêè âñåãî àâòîìàòà).

int main()
{
	setlocale(LC_ALL, "");
	/*-------------------Áëîê èíèöèàëèçàöèè---------------------*/
	//Â ðàìêàõ ó÷åáíîé çàäà÷è ìû çàïîëíèì Âåíäèíãîâûé àâòîìàò âðó÷íóþ

	//Ñïèñîê çàãðóæåííûõ â àâòîìàò ñíýêîâ
	Snack listSnacks[countSnack] = {
		Snack("×èïñû Lays", 120.0, 10, 1), Snack("×èïñû Doritos", 95.0, 8, 2),  Snack("×èïñû Pringles", 120.0, 5, 3),
		Snack("Êðóàññàíû 7Days", 85.0, 10, 4), Snack("Êðóàññàíû Øàðëèç", 79.0, 4, 5),  Snack("Áóëî÷êà", 25.0, 5, 6),
		Snack("Ñîê Äîáðûé", 45.0, 9, 7), Snack("Ñíèêåðñ", 55.0, 7, 8),  Snack("Ñîê Rich", 65.0, 6, 9),
	};

	Slot slot1 = Slot();
	slot1.SlotLoad(listSnacks[0], listSnacks[1], listSnacks[2]);

	Slot slot2 = Slot();
	slot2.SlotLoad(listSnacks[3], listSnacks[4], listSnacks[5]);

	Slot slot3 = Slot();
	slot3.SlotLoad(listSnacks[6], listSnacks[7], listSnacks[8]);

	//Çàïîëíÿåì ñëîòû è ÿ÷åéêè ñíåêàìè èç ñïèñêà äîñòóïíûõ
	ExtendModule extendModule = ExtendModule(slot1, slot2, slot3);

	/*--------------------Îñíîâíîé áëîê ïðîãðàììû--------------------*/

	cout << endl << "------------------------Âåíäèíîãîâàÿ ìàøèíà----------------------------" << endl;
	cout << "                        Âûáèðèòå òîâàð:                     " << endl;

	//Âûãðóçêà íàèìåíîâàíèé òîâàðà 1 ñëîòà
	cout << " 1: " << findNameSnake(listSnacks, extendModule.listSlots[0].listSnakeSlot[0]).nameSnack << endl;
	cout << " 2: " << findNameSnake(listSnacks, extendModule.listSlots[0].listSnakeSlot[1]).nameSnack << endl;
	cout << " 3: " << findNameSnake(listSnacks, extendModule.listSlots[0].listSnakeSlot[2]).nameSnack << endl;

	cout << " 4: " << findNameSnake(listSnacks, extendModule.listSlots[1].listSnakeSlot[0]).nameSnack << endl;
	cout << " 5: " << findNameSnake(listSnacks, extendModule.listSlots[1].listSnakeSlot[1]).nameSnack << endl;
	cout << " 6: " << findNameSnake(listSnacks, extendModule.listSlots[1].listSnakeSlot[2]).nameSnack << endl;

	cout << " 7: " << findNameSnake(listSnacks, extendModule.listSlots[2].listSnakeSlot[0]).nameSnack << endl;
	cout << " 8: " << findNameSnake(listSnacks, extendModule.listSlots[2].listSnakeSlot[1]).nameSnack << endl;
	cout << " 9: " << findNameSnake(listSnacks, extendModule.listSlots[2].listSnakeSlot[2]).nameSnack << endl;

	cout << endl << " 0: Âûõîä" << endl;
	cout << endl << "--------------------------------------------------------------------------" << endl;

	/*---------------------Âûáîð ñíåêà--------------------------*/
	//Ïåðåìåíàÿ-ôëàã - âûáðàíà ëè äîñòóïíàÿ â ïðîãðàììå îïåðàöèÿ
	bool chouse_operation = false;
	int number_operation;

	while (!chouse_operation)
	{
		cin >> number_operation;

		if ((number_operation >= 0) && (number_operation < 10))
		{
			chouse_operation = true;
		}
		else
		{
			cout << "--------------------------------------------------------------------------" << endl;
			cout << " Òîâàðà ñ òàêèì íîìåðîì íåòó" << endl;
			cout << "--------------------------------------------------------------------------" << endl;
		}
	}

	if (number_operation == 0) return 0;

	/*--------------------Ââîä äåíåã------------------------*/

	if ((number_operation > 0) && (number_operation < 10))
	{
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "                        Ñòîèìîñòü " << findNameSnake(listSnacks, number_operation).nameSnack
			<< ": " << findNameSnake(listSnacks, number_operation).priceSnake << endl;
	}

	double money; //Êîëè÷åñòâî âíåñåííûõ äåíåã çà ðàç
	double deposit = 0.0; //Êîëè÷åñòâî äåíåã âíåñåííûõ çà âñå âðåìÿ
	bool refillMoney = false; //Áûëî ëè âíåñåííî äîñòàòî÷íî äåíåã äëÿ ïîêóïêè âûáðàíîãî ñíåêà

	cout << "--------------------------------------------------------------------------" << endl;
	cout << "                        Âíåñèòå äåíüãè( 0 - âûõîä )                     " << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	while (!refillMoney)
	{
		cin >> money;

		deposit += money; //Âíîñèì âíåñåííûå äåíüãè íà äåïîçèò

		if (money == 0)
		{
			refillMoney = true;
			break;
		}
		else
		{
			//Ïðîâåðêà òåêóùèé äåïîçèò áîëüøå èëè ðàâåí öåíå âûáðàíîãî ñíåêà
			if (deposit >= findNameSnake(listSnacks, number_operation).priceSnake)
			{
				refillMoney = true;
				break;
			}

			if (money > 0)
			{
				cout << "--------------------------------------------------------------------------" << endl;
				cout << "                        Ñòîèìîñòü " << findNameSnake(listSnacks, number_operation).nameSnack
					<< ": " << findNameSnake(listSnacks, number_operation).priceSnake << endl;

				cout << "--------------------------------------------------------------------------" << endl;
				cout << "                        Âíåñèòå äåíüãè( äåïîçèò: " << deposit << ", 0 - âûõîä )                     " << endl;
				cout << "--------------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "--------------------------------------------------------------------------" << endl;
				cout << " Âñòàâüòå ïðàâèëüíî êóïþðó" << endl;
				cout << "--------------------------------------------------------------------------" << endl;
			}
		}

		if (!(number_operation >= 0) && !(number_operation < 7))
		{
			cout << "--------------------------------------------------------------------------" << endl;
			cout << " Òîâàðà ñ òàêèì íîìåðîì íåòó";
			cout << "--------------------------------------------------------------------------" << endl;
		}
	}

	/*------------------Ïîëó÷åíèå ñíåêà è ñäà÷è-------------------*/
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "                        Âûáèðèòå îïåðàöèþ:" << endl;
	cout << "                        Âàø äåïîçèò: " << deposit << endl;
	cout << "                        1: Ïîëó÷èòü " << findNameSnake(listSnacks, number_operation).nameSnack
		<< "(öåíà:" << findNameSnake(listSnacks, number_operation).priceSnake <<
		") è ñäà÷ó(" << deposit - findNameSnake(listSnacks, number_operation).priceSnake << ")" << endl;
	cout << "                        0: Âûõîä" << endl;

	cout << "--------------------------------------------------------------------------" << endl;

	chouse_operation = false;

	while (!chouse_operation)
	{
		cin >> number_operation;

		if (number_operation == 1)
		{
			cout << "--------------------------------------------------------------------------" << endl;
			cout << " Äîñòàíüòå " << findNameSnake(listSnacks, number_operation).nameSnack  << " èç îòñåêà." << endl;
			cout << " Íå çàáóäüòå çàáðàòü ñâîþ ñäà÷ó (" 
				 << deposit - findNameSnake(listSnacks, number_operation).priceSnake << ")." << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			chouse_operation = true;
		}
		else
		{
			cout << "--------------------------------------------------------------------------" << endl;
			cout << " Íåïðàâèëüíûé ââîä" << endl;
			cout << "--------------------------------------------------------------------------" << endl;
		}

		if (number_operation == 0) return 0;
	}

	//cout << endl << "------------------------------------------------------------" << endl;
	return 0;
}

Snack findNameSnake(Snack listSnacks[], int index)
{
	for (int i = 0; i < countSnack; i++)
	{
		if (listSnacks[i].indexProductSnake == index)
		{
			return listSnacks[i];
		}
	}

	//Òóò ïî õîðîøåìó äîëæíà áûòü ðåàêöèÿ íà òîò ñëó÷àé, êîãäà íóæíîãî èíäåêñà ñíåêà íå íàéäåòüñÿ.
	//Íî ìû òî÷íî çíà÷åì êîëè÷åñòâî ñíåêîâ è ó íàñ íåòó ãëîáàëüíîãî ìåõàíèçìà óñòàíîâêè êîëè÷åñòâî ñíåêîâ, ïîýòîì îïóñòèì ýòî ìîìåíò
}
