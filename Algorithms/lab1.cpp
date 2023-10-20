#include "lab1.h"



void mainMenu() {

	std::cout << "����� �������:\n\\"; int taskNum; std::cin >> taskNum;

	system("cls");

	switch (taskNum)
	{
	case 5: {
		/*��������� ��������� ������������ ��������� ������ ��������� �����.
		������ ������ ��������  ����������.�������� �������, ������������ ����� 
		��������� ��������������� ������.��������� ������ ��������� ����������� 
		��������� ������ ��������� ������ � ������ � �������� �������.*/

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
		std::cout << "������������ �����"; std::cin; system("cls");
		break;
	
	}



}



void task5() {

    std::cout << "������� ������ ������: "; size_t size; std::cin >> size;

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



}


void task7() {



}


void task8() {



}