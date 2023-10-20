#include "lab1.h"



void mainMenuLab1() {



	std::cout << "Номер задания:\n\\"; int taskNum; std::cin >> taskNum;

	system("cls");

	switch (taskNum)
	{
	case 5: {
		/*Составить программу формирования линейного списка случайных чисел.
		Размер списка задается  константой. Написать функцию, определяющую сумму 
		элементов сформированного списка. Программа должна содержать рекурсивные 
		процедуры вывода линейного списка в прямом и обратном порядке*/

        task5();
        break;

	}
	case 6: {
        task6();
        break;

	}
	case 7: {
        task7();
        break;

	}
	case 8: {
        task8();
        break;

	}
	default:
		std::cout << "Некорректный номер";
		break;
	
	}



}





void task5() {

    std::cout << "Введите размер списка: "; size_t size; std::cin >> size;

    Chain* A = new Chain();
    Chain* first = A;

    srand(time(0));

    first->data = rand() % 100 + 1;

    for (int i = 0; i < size - 1; i++) {
        first->next = new Chain();
        first = first->next;
        first->data = rand() % 100 + 1;

    }

    first = NULL;

    std::cout << summChain(A) << "\n";
    coutChain(A); std::cout << "\n";
    reverseCoutChain(A); std::cout << "\n";

}


int summChain(Chain* first) {

    int summ(0);

    while (first != nullptr) {

        summ += first->data;
        first = first->next;

    }

    return summ;

}


void coutChain(Chain* first) {

    if (first != NULL) {

        std::cout << first->data << " ";

        coutChain(first->next);

    }

}


void reverseCoutChain(Chain* first) {

    if (first != NULL) {

        reverseCoutChain(first->next);

        std::cout << first->data << " ";

    }

}


void task6() {
    std::ifstream in("lab1task6.txt");

    std::string line;

    Chain* A = new Chain;
    Chain* first = A;

    if (in.is_open()) {
        std::cout << "Данные файла: ";

        while (!in.eof()) {
            in >> first->data;

            std::cout << first->data << " ";

            while (!in.eof()) {
                first->next = new Chain();

                first = first->next;

                in >> first->data;

                std::cout << first->data << " ";

            }

            first->next = NULL;

        }

        std::cout << "\nКоличесвто элементов, больших первого элемента: " << bigNums(A) << "\n";

    }
    else {
        std::cout << "Файл не был найден";

    }
    

}


int bigNums(Chain* first) {
    int cout(0);

    int bigNum = first->data;
    first = first->next;

    while (first != NULL) {
        if (first->data > bigNum) cout++;

        first = first->next;

    }

    return cout;

}


void task7() {
    std::cout << "Вводите элементы(0-закончить ввод):\n\\";

    Chain* A = new Chain;
    Chain* first = A;

    int element(1);

    std::cin >> element; 

    if (element != 0) first->data = element;

    std::cin >> element;

    while (element != 0) {
        first->next = new Chain;

        first = first->next;

        first->data = element;

        std::cin >> element;

    }

    first->next = NULL;
    
    system("cls"); std::cout << "Были введены следующие значения: "; coutChain(A);

    std::cout << "\nСреднее арифметическое введённых значений: " << average(A);


}


float average(Chain* first) {
    int summ(0);
    int count(0);

    while (first != NULL) {
        summ += first->data;

        count++;

        first = first->next;

    }

    return summ / count;

}


void task8() {
    std::cout << "Введите элементы в строку:\n\\";

    Chain* A = new Chain;
    Chain* first = A;

    std::string elements;

    std::getline(std::cin, elements);
    std::getline(std::cin, elements);

    std::stringstream ss(elements);

    ss >> first->data;
    while (!ss.eof()) {
        first->next = new Chain;

        first = first->next;

        ss >> first->data;

    }

    first->next = NULL;

    system("cls"); std::cout << "Были введены следующие значения: "; coutChain(A);

    std::cout << "\nМаксимальный элемент списка: " << maxEl(A);

}


int maxEl(Chain* first) {

    int maxElement(first->data);

    first->next;

    while (first != NULL) {

        if (maxElement < first->data) maxElement = first->data;

        first = first->next;

    }

    return maxElement;

}