#pragma once
#include <string>

using namespace std;

class Snack
{
public:
	string nameSnack; //��� �����
	double priceSnake; //����
	int curentCountSnake; //������� ����������� ���������� ������
	int indexProductSnake; //���������� ����� ������ � ����

	Snack(string namesSnackPtr, double priceSnakePtr, int curentCountSnakePtr, int indexProductSnakePtr);

};

