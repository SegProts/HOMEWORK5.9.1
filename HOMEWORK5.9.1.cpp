#include <iostream>
#include "Snack.h"
#include "Slot.h"
#include "ExtendModule.h"

using namespace std;

Snack findNameSnake(Snack listSnacks[], int index);
const int countSnack = 9; //В рабочем варианте можно вынести такие значения в отдельный класс(Класс для настрйоки всего автомата).

int main()
{
	setlocale(LC_ALL, "");
	/*-------------------Блок инициализации---------------------*/
	//В рамках учебной задачи мы заполним Вендинговый автомат вручную

	//Список загруженных в автомат снэков
	Snack listSnacks[countSnack] = {
		Snack("Чипсы Lays", 120.0, 10, 1), Snack("Чипсы Doritos", 95.0, 8, 2),  Snack("Чипсы Pringles", 120.0, 5, 3),
		Snack("Круассаны 7Days", 85.0, 10, 4), Snack("Круассаны Шарлиз", 79.0, 4, 5),  Snack("Булочка", 25.0, 5, 6),
		Snack("Сок Добрый", 45.0, 9, 7), Snack("Сникерс", 55.0, 7, 8),  Snack("Сок Rich", 65.0, 6, 9),
	};

	Slot slot1 = Slot();
	slot1.SlotLoad(listSnacks[0], listSnacks[1], listSnacks[2]);

	Slot slot2 = Slot();
	slot2.SlotLoad(listSnacks[3], listSnacks[4], listSnacks[5]);

	Slot slot3 = Slot();
	slot3.SlotLoad(listSnacks[6], listSnacks[7], listSnacks[8]);

	//Заполняем слоты и ячейки снеками из списка доступных
	ExtendModule extendModule = ExtendModule(slot1, slot2, slot3);

	/*--------------------Основной блок программы--------------------*/

	cout << endl << "------------------------Вендиноговая машина----------------------------" << endl;
	cout << "                        Выбирите товар:                     " << endl;

	//Выгрузка наименований товара 1 слота
	cout << " 1: " << findNameSnake(listSnacks, extendModule.listSlots[0].listSnakeSlot[0]).nameSnack << endl;
	cout << " 2: " << findNameSnake(listSnacks, extendModule.listSlots[0].listSnakeSlot[1]).nameSnack << endl;
	cout << " 3: " << findNameSnake(listSnacks, extendModule.listSlots[0].listSnakeSlot[2]).nameSnack << endl;

	cout << " 4: " << findNameSnake(listSnacks, extendModule.listSlots[1].listSnakeSlot[0]).nameSnack << endl;
	cout << " 5: " << findNameSnake(listSnacks, extendModule.listSlots[1].listSnakeSlot[1]).nameSnack << endl;
	cout << " 6: " << findNameSnake(listSnacks, extendModule.listSlots[1].listSnakeSlot[2]).nameSnack << endl;

	cout << " 7: " << findNameSnake(listSnacks, extendModule.listSlots[2].listSnakeSlot[0]).nameSnack << endl;
	cout << " 8: " << findNameSnake(listSnacks, extendModule.listSlots[2].listSnakeSlot[1]).nameSnack << endl;
	cout << " 9: " << findNameSnake(listSnacks, extendModule.listSlots[2].listSnakeSlot[2]).nameSnack << endl;

	cout << endl << " 0: Выход" << endl;
	cout << endl << "--------------------------------------------------------------------------" << endl;

	/*---------------------Выбор снека--------------------------*/
	//Переменая-флаг - выбрана ли доступная в программе операция
	bool chouse_operation = false;
	int number_operation;

	while (!chouse_operation)
	{
		cin >> number_operation;

		if ((number_operation >= 0) && (number_operation < 7))
		{
			chouse_operation = true;
		}
		else
		{
			cout << "--------------------------------------------------------------------------" << endl;
			cout << " Товара с таким номером нету" << endl;
			cout << "--------------------------------------------------------------------------" << endl;
		}
	}

	if (number_operation == 0) return 0;

	/*--------------------Ввод денег------------------------*/

	if ((number_operation > 0) && (number_operation < 10))
	{
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "                        Стоимость " << findNameSnake(listSnacks, number_operation).nameSnack
			<< ": " << findNameSnake(listSnacks, number_operation).priceSnake << endl;
	}

	double money; //Количество внесенных денег за раз
	double deposit = 0.0; //Количество денег внесенных за все время
	bool refillMoney = false; //Было ли внесенно достаточно денег для покупки выбраного снека

	cout << "--------------------------------------------------------------------------" << endl;
	cout << "                        Внесите деньги( 0 - выход )                     " << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	while (!refillMoney)
	{
		cin >> money;

		deposit += money; //Вносим внесенные деньги на депозит

		if (money == 0)
		{
			refillMoney = true;
			break;
		}
		else
		{
			//Проверка текущий депозит больше или равен цене выбраного снека
			if (deposit >= findNameSnake(listSnacks, number_operation).priceSnake)
			{
				refillMoney = true;
				break;
			}

			if (money > 0)
			{
				cout << "--------------------------------------------------------------------------" << endl;
				cout << "                        Стоимость " << findNameSnake(listSnacks, number_operation).nameSnack
					<< ": " << findNameSnake(listSnacks, number_operation).priceSnake << endl;

				cout << "--------------------------------------------------------------------------" << endl;
				cout << "                        Внесите деньги( депозит: " << deposit << ", 0 - выход )                     " << endl;
				cout << "--------------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "--------------------------------------------------------------------------" << endl;
				cout << " Вставьте правильно купюру" << endl;
				cout << "--------------------------------------------------------------------------" << endl;
			}
		}

		if (!(number_operation >= 0) && !(number_operation < 7))
		{
			cout << "--------------------------------------------------------------------------" << endl;
			cout << " Товара с таким номером нету";
			cout << "--------------------------------------------------------------------------" << endl;
		}
	}

	/*------------------Получение снека и сдачи-------------------*/
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "                        Выбирите операцию:" << endl;
	cout << "                        Ваш депозит: " << deposit << endl;
	cout << "                        1: Получить " << findNameSnake(listSnacks, number_operation).nameSnack
		<< "(цена:" << findNameSnake(listSnacks, number_operation).priceSnake <<
		") и сдачу(" << deposit - findNameSnake(listSnacks, number_operation).priceSnake << ")" << endl;
	cout << "                        0: Выход" << endl;

	cout << "--------------------------------------------------------------------------" << endl;

	chouse_operation = false;

	while (!chouse_operation)
	{
		cin >> number_operation;

		if (number_operation == 1)
		{
			cout << "--------------------------------------------------------------------------" << endl;
			cout << " Достаньте " << findNameSnake(listSnacks, number_operation).nameSnack  << " из отсека." << endl;
			cout << " Не забудьте забрать свою сдачу (" 
				 << deposit - findNameSnake(listSnacks, number_operation).priceSnake << ")." << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			chouse_operation = true;
		}
		else
		{
			cout << "--------------------------------------------------------------------------" << endl;
			cout << " Неправильный ввод" << endl;
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

	//Тут по хорошему должна быть реакция на тот случай, когда нужного индекса снека не найдеться.
	//Но мы точно значем количество снеков и у нас нету глобального механизма установки количество снеков, поэтом опустим это момент
}
