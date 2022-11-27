#pragma once
#include <string>

using namespace std;

class Snack
{
public:
	string nameSnack; //Имя снека
	double priceSnake; //Цена
	int curentCountSnake; //Текущее загруженное количество снейка
	int indexProductSnake; //Порядковый номер снейка в меню

	Snack(string namesSnackPtr, double priceSnakePtr, int curentCountSnakePtr, int indexProductSnakePtr);

};

