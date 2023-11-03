#include <iostream>
#include "lab0.h"
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"

int main()
{
        
	setlocale(0, "");

    std::cout << "Номер лабы:\n\\"; int labNum; std::cin >> labNum;

	switch (labNum)
	{
	case 1: {
		mainMenuLab1();
		break;

	}
	default:
		std::cout << "Некорректный номер";
		break;

	}



	std::cin.get(); std::cin.get();


	//gff
}
