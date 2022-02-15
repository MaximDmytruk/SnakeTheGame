/*1. Доопрацюйте гру, яку створювали на занятті :
-користувач повинен мати можливість обирати розміри поля(NxN)
- реалізуйте підрахунок балів(+1 коли змія з'їдає їжу)*/
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

using namespace std;
void Pravila();	//Функція для виклику праивил
void printPole(char** pole, int x);	//ф-ція для виведення поля 

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "--Змійка--" << endl;
	Pravila();		//Виводимо правила 
	char step=0;		//змінна для дій гравця
	int x;	//розмір поля
	int y;
	cout << "Будь ласка, введіть розмір поля = ";
	cin >> x;
	y = x;
	char** pole=nullptr;
	pole = new char* [x];		//масив для нашого поля 
	
	for (int i = 0; i < x; i++)
	{
		pole[i] = new char[y];		//розподіляємо пам ять 
	}
	char snake = '@'; //Змінна для зміїки
	int sx = 1;		//координати змії
	int sy = 1;
	char apple = '*';	//Яблука
	int ax = 1+rand() % (x-2);
	int ay = 1+rand() % (x-2);		//Рандомні координати в межах поля 
	int point = 0;					//бали за яблука
	for (; ;)	//Запускаємо безкінечний цикл
	{
		for (int i = 0; i < x; i++)		//Позначаємо наше поле стінками з #
		{
			for (int j = 0; j < x; j++)
			{
				if (i == 0 || j == 0 || i == x - 1 || j == x - 1) {

					pole[i][j] = '#';
				}
				else { pole[i][j] = ' '; }
			}
		}
		pole[sx][sy] = snake;		//Координати змії на полі 
		pole[ax][ay] = apple;		//Координати ябулка на полі 
		printPole(pole, x);			//викликаємо ф-цію друка поля 
		cout << "Ви вже зібрали " << point << " яблук." << endl;
		step = _getch();		//зчитуємо дію гравця з клавіатури 
		system("cls");			//очищуємо екран віід минулих дій 
		if (step == 'w') sx--;
		if (step == 's') sx++;		//шаги гравця 
		if (step == 'a') sy--;
		if (step == 'd') sy++;
		if (step == 'z' || step == 'Z') Pravila();	//якщо гравець захоче ще раз прочитати правила 
		if (sx == ax && sy == ay) {	//коли змія дійде до яблука, координати яблука - змінюються, +1бал
			point++;
			 ax = 1 + rand() % (x - 2);
			 ay = 1 + rand() % (x - 2);
		}
		if (sx == 0 || sx == x - 1 or sy == 0 || sy == y - 1) {	//якщо гравець впреця у стінку - програш 
			cout << endl;
			cout << "Програш! ти вперся в стінку.." << endl;
			break;
		}
		if (point==21) {
			cout << endl;		
			cout << "Вітаю ти зібрав усі яблука!" << endl;	//якщо збере усі яблука - виграш 
			break;
		}
	}
}
void printPole(char **pole,int x) {	//Функція для виводу поля
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cout << pole[i][j];

		}
		cout << endl;
	}
}
void Pravila() {//Виведення правил.
	cout << "Правила:" << endl;
	cout << "1.Для виграшу потрібно зібрати яблука '*' у кількості - 21 " << endl;
	cout << "2.В стінку впиратись НЕМОЖНА. Це Програш!" << endl;
	cout << "3.Для переміщення використовуй клавіши W-Вверх, S-Вниз, A-Ліворуч, D-Праворуч" << endl;
	cout << "4.Для того щоб ще раз викликати Правила - нажимай 'Z'" << endl;
}