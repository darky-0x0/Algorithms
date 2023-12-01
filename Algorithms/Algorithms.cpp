#include <iostream>
#include "lab0.h"
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"
#include "lab5.h"


int main() {
	int replace(0);

	do
	{
		system("cls");
		setlocale(0, "");

		std::cout << "Номер лабы:\n\\"; int labNum; std::cin >> labNum;

		switch (labNum)
		{
		case 1: {
			mainMenuLab1();
			break;

		}
		case 2: {
			mainMenuLab2();
			break;

		}
		case 3: {
			mainMenuLab3();
			break;

		}
		case 4: {
			mainMenuLab4();
			break;

		}
		case 5: {
			mainMenuLab5();
			break;

		}
		default:
			std::cout << "Некорректный номер";
			break;

		}

		

		std::cin >> replace;

		system("cls");

	} while (replace != 0);

}
