#include <iostream>
#include "Snack.h"
#include "Slot.h"
#include "ExtendModule.h"

using namespace std;

Snack findNameSnake(Snack listSnacks[], int index);
const int countSnack = 9; //� ������� �������� ����� ������� ����� �������� � ��������� �����(����� ��� ��������� ����� ��������).

int main()
{
	setlocale(LC_ALL, "");
	/*-------------------���� �������������---------------------*/
	//� ������ ������� ������ �� �������� ����������� ������� �������

	//������ ����������� � ������� ������
	Snack listSnacks[countSnack] = {
		Snack("����� Lays", 120.0, 10, 1), Snack("����� Doritos", 95.0, 8, 2),  Snack("����� Pringles", 120.0, 5, 3),
		Snack("��������� 7Days", 85.0, 10, 4), Snack("��������� ������", 79.0, 4, 5),  Snack("�������", 25.0, 5, 6),
		Snack("��� ������", 45.0, 9, 7), Snack("�������", 55.0, 7, 8),  Snack("��� Rich", 65.0, 6, 9),
	};

	Slot slot1 = Slot();
	slot1.SlotLoad(listSnacks[0], listSnacks[1], listSnacks[2]);

	Slot slot2 = Slot();
	slot2.SlotLoad(listSnacks[3], listSnacks[4], listSnacks[5]);

	Slot slot3 = Slot();
	slot3.SlotLoad(listSnacks[6], listSnacks[7], listSnacks[8]);

	//��������� ����� � ������ ������� �� ������ ���������
	ExtendModule extendModule = ExtendModule(slot1, slot2, slot3);

	/*--------------------�������� ���� ���������--------------------*/

	cout << endl << "------------------------������������ ������----------------------------" << endl;
	cout << "                        �������� �����:                     " << endl;

	//�������� ������������ ������ 1 �����
	cout << " 1: " << findNameSnake(listSnacks, extendModule.listSlots[0].listSnakeSlot[0]).nameSnack << endl;
	cout << " 2: " << findNameSnake(listSnacks, extendModule.listSlots[0].listSnakeSlot[1]).nameSnack << endl;
	cout << " 3: " << findNameSnake(listSnacks, extendModule.listSlots[0].listSnakeSlot[2]).nameSnack << endl;

	cout << " 4: " << findNameSnake(listSnacks, extendModule.listSlots[1].listSnakeSlot[0]).nameSnack << endl;
	cout << " 5: " << findNameSnake(listSnacks, extendModule.listSlots[1].listSnakeSlot[1]).nameSnack << endl;
	cout << " 6: " << findNameSnake(listSnacks, extendModule.listSlots[1].listSnakeSlot[2]).nameSnack << endl;

	cout << " 7: " << findNameSnake(listSnacks, extendModule.listSlots[2].listSnakeSlot[0]).nameSnack << endl;
	cout << " 8: " << findNameSnake(listSnacks, extendModule.listSlots[2].listSnakeSlot[1]).nameSnack << endl;
	cout << " 9: " << findNameSnake(listSnacks, extendModule.listSlots[2].listSnakeSlot[2]).nameSnack << endl;

	cout << endl << " 0: �����" << endl;
	cout << endl << "--------------------------------------------------------------------------" << endl;

	/*---------------------����� �����--------------------------*/
	//���������-���� - ������� �� ��������� � ��������� ��������
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
			cout << " ������ � ����� ������� ����" << endl;
			cout << "--------------------------------------------------------------------------" << endl;
		}
	}

	if (number_operation == 0) return 0;

	/*--------------------���� �����------------------------*/

	if ((number_operation > 0) && (number_operation < 10))
	{
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "                        ��������� " << findNameSnake(listSnacks, number_operation).nameSnack
			<< ": " << findNameSnake(listSnacks, number_operation).priceSnake << endl;
	}

	double money; //���������� ��������� ����� �� ���
	double deposit = 0.0; //���������� ����� ��������� �� ��� �����
	bool refillMoney = false; //���� �� �������� ���������� ����� ��� ������� ��������� �����

	cout << "--------------------------------------------------------------------------" << endl;
	cout << "                        ������� ������( 0 - ����� )                     " << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	while (!refillMoney)
	{
		cin >> money;

		deposit += money; //������ ��������� ������ �� �������

		if (money == 0)
		{
			refillMoney = true;
			break;
		}
		else
		{
			//�������� ������� ������� ������ ��� ����� ���� ��������� �����
			if (deposit >= findNameSnake(listSnacks, number_operation).priceSnake)
			{
				refillMoney = true;
				break;
			}

			if (money > 0)
			{
				cout << "--------------------------------------------------------------------------" << endl;
				cout << "                        ��������� " << findNameSnake(listSnacks, number_operation).nameSnack
					<< ": " << findNameSnake(listSnacks, number_operation).priceSnake << endl;

				cout << "--------------------------------------------------------------------------" << endl;
				cout << "                        ������� ������( �������: " << deposit << ", 0 - ����� )                     " << endl;
				cout << "--------------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "--------------------------------------------------------------------------" << endl;
				cout << " �������� ��������� ������" << endl;
				cout << "--------------------------------------------------------------------------" << endl;
			}
		}

		if (!(number_operation >= 0) && !(number_operation < 7))
		{
			cout << "--------------------------------------------------------------------------" << endl;
			cout << " ������ � ����� ������� ����";
			cout << "--------------------------------------------------------------------------" << endl;
		}
	}

	/*------------------��������� ����� � �����-------------------*/
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "                        �������� ��������:" << endl;
	cout << "                        ��� �������: " << deposit << endl;
	cout << "                        1: �������� " << findNameSnake(listSnacks, number_operation).nameSnack
		<< "(����:" << findNameSnake(listSnacks, number_operation).priceSnake <<
		") � �����(" << deposit - findNameSnake(listSnacks, number_operation).priceSnake << ")" << endl;
	cout << "                        0: �����" << endl;

	cout << "--------------------------------------------------------------------------" << endl;

	chouse_operation = false;

	while (!chouse_operation)
	{
		cin >> number_operation;

		if (number_operation == 1)
		{
			cout << "--------------------------------------------------------------------------" << endl;
			cout << " ��������� " << findNameSnake(listSnacks, number_operation).nameSnack  << " �� ������." << endl;
			cout << " �� �������� ������� ���� ����� (" 
				 << deposit - findNameSnake(listSnacks, number_operation).priceSnake << ")." << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			chouse_operation = true;
		}
		else
		{
			cout << "--------------------------------------------------------------------------" << endl;
			cout << " ������������ ����" << endl;
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

	//��� �� �������� ������ ���� ������� �� ��� ������, ����� ������� ������� ����� �� ���������.
	//�� �� ����� ������ ���������� ������ � � ��� ���� ����������� ��������� ��������� ���������� ������, ������ ������� ��� ������
}
