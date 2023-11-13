#include "lab2.h"





void mainMenuLab2() {

	std::cout << "Номер задания:\n\\"; int taskNum; std::cin >> taskNum;

	std::string str; std::getline(std::cin, str);

	switch (taskNum)
	{
	case 1: {

		Chain* list = createLinealList();
		Chain* sortedList = sortList(list);

		std::cout << "\nНеотсортированный список: ";
		printChain(list);

		std::cout << "\nОтсортированный список: ";
		printChain(sortedList);

		break;

	}
	case 2: {

		Chain* list1 = createLinealList();
		Chain* list2 = createLinealList();

		std::cout << "\nПервый список: "; printChain(list1);
		Chain* sortedList1 = sortList(list1);
		std::cout << "\nПервый отсортированный список: "; printChain(sortedList1);

		std::cout << "\nВторой список: "; printChain(list2);
		Chain* sortedList2 = sortList(list2);
		std::cout << "\nВторой отсортированный список: "; printChain(sortedList2);

		Chain* result = join2Lists(sortedList1, sortedList2);

		std::cout << "\nОбъединение двух списков: ";
		printChain(result);

		break;

	}
	case 3: {

		Chain* list = createLinealList();
		Chain* list1 = NULL;
		Chain* list2 = NULL;

		create2Lists(list, list1, list2);

		std::cout << "\nИсходный список: ";
		printChain(list);

		std::cout << "\nСписок только положительных: ";
		printChain(list1);

		std::cout << "\nСписок только отрицательных: ";
		printChain(list2);

		break;

	}
	case 4: {

		Chain* list1(readFromFile("input1.txt")), * list2(readFromFile("input2.txt"));

		std::cout << "\nПервый список: "; printChain(list1);
		std::cout << "\nВторой список: "; printChain(list2);

		Chain* list(join2Lists2(list1, list2));
		std::cout << "\n\nКонечный список: "; printChain(list);

		break;

	}
	case 5: {

		Chain* list1 = createLinealList();
		Chain* list2 = createLinealList();

		std::cout << "\nВведите элемент x\n\\"; int x; std::cin >> x;

		editChains(list1, list2, x);

		std::cout << "\nПервый изменённый список: "; printChain(list1);
		std::cout << "\nВторой изменённый список: "; printChain(list2);

		break;

	}
	case 6: {

		Chain* list = createLinealList();

		std::cout << "\nВведите элемент z\n\\"; int z; std::cin >> z;

		editChains2(list, z);

		std::cout << "\nИзменённый список: "; printChain(list);

		break;

	}
	case 7: {

		Chain* list = createLinealList();

		std::cout << "\nВведите вставляемый элемент x\n\\"; int x; std::cin >> x;
		std::cout << "\nВведите элемент z\n\\"; int z; std::cin >> z;

		editChains3(list, x, z);

		std::cout << "\nИзменённый список: "; printChain(list);

		break;

	}
	default:

		std::cout << "Некорректный номер";
		break;

	}


}

Chain* createLinealList() {

	std::cout << "Введите числа "; 
	std::string strTemp;
	std::getline(std::cin, strTemp);

	if (strTemp != "") {

		std::stringstream ss(strTemp);

		Chain* list = new Chain;
		Chain* ind = list;

		ss >> ind->data;

		while (!ss.eof()) {

			ind->next = new Chain;
			ind = ind->next;
			ss >> ind->data;

		}

		ind->next = NULL;

		return list;

	}
	else {

		std::cout << "\nСписок пуст";

	}

	return NULL;

}

void printChain(Chain* const chain) {

	if (chain != NULL) {

		Chain* tempChain = chain;

		while (tempChain != NULL) {

			std::cout << tempChain->data << " ";
			tempChain = tempChain->next;

		}

	}
	else std::cout << "Список пуст";

}

Chain* sortListRecurs(Chain* const chain)
{

	Chain* temp = chain;
	Chain* sortedList = new Chain;

	sortedList->data = temp->data;
	sortedList->next = NULL;
	temp = temp->next;

	Chain* tempChain = NULL;

	while (temp != NULL) {

		if (temp->data <= sortedList->data) {

			tempChain = new Chain;
			tempChain->data = temp->data;
			tempChain->next = sortedList;
			sortedList = tempChain;

		}
		else {

			Chain* preview = sortedList;
			tempChain = sortedList->next;
			while (tempChain != NULL) {

				if (temp->data < tempChain->data) {

					preview->next = new Chain;
					preview->next->data = temp->data;
					preview->next->next = tempChain;
					tempChain = NULL;

				}
				preview = tempChain;
				if (tempChain != NULL) {

					tempChain = tempChain->next;

				}


			}

			if (tempChain == NULL && preview != NULL) {

				preview->next = new Chain;
				preview->next->data = temp->data;
				preview->next->next = NULL;

			}

		}

		temp = temp->next;

	}

	return sortedList;

}

Chain* sortList(Chain* const chain)
{

	Chain* temp = chain;
	Chain* sortedList = new Chain;

	sortedList->data = temp->data;
	sortedList->next = NULL;
	temp = temp->next;

	Chain* tempChain = NULL;

	while(temp != NULL) {
		
		if (temp->data <= sortedList->data) {

			tempChain = new Chain;
			tempChain->data = temp->data;
			tempChain->next = sortedList;
			sortedList = tempChain;

		}
		else {

			Chain* preview = sortedList;
			tempChain = sortedList->next;
			while (tempChain != NULL) {

				if (temp->data < tempChain->data) {

					preview->next = new Chain;
					preview->next->data = temp->data;
					preview->next->next = tempChain;
					tempChain = NULL;

				}
				preview = tempChain;
				if (tempChain != NULL) {

					tempChain = tempChain->next;

				}


			}

			if (tempChain == NULL && preview != NULL) {

				preview->next = new Chain;
				preview->next->data = temp->data;
				preview->next->next = NULL;

			}

		}

		temp = temp->next;
	
	}

	return sortedList;

}


Chain* join2Lists(Chain* first, Chain* second) {

	if (first == NULL && second == NULL) {

		std::cout << "Списков не существует\n";
		return NULL;

	}
	else {

		Chain* result = NULL;
		Chain* last = NULL;

		while (first != NULL && second != NULL) {

			if (first->data > second->data) {

				if (last == NULL) {

					result = new Chain;
					last = result;
					last->data = second->data;
					last->next = NULL;
					second = second->next;

				}
				else {

					last->next = new Chain;
					last = last->next;
					last->data = second->data;
					last->next = NULL;
					second = second->next;

				}

			}
			else {

				if (last == NULL) {

					result = new Chain;
					last = result;
					last->data = first->data;
					last->next = NULL;
					first = first->next;

				}
				else {

					last->next = new Chain;
					last = last->next;
					last->data = first->data;
					last->next = NULL;
					first = first->next;

				}

			}

		}

		while (first != NULL) {

			last->next = new Chain;
			last = last->next;
			last->data = first->data;
			last->next = NULL;
			first = first->next;

		}

		while (second != NULL) {

			last->next = new Chain;
			last = last->next;
			last->data = second->data;
			last->next = NULL;
			second = second->next;

		}

		return result;

	}


}


void create2Lists(Chain* chain, Chain*& ch1, Chain*& ch2) {


	if (chain == NULL) {

		std::cout << "Список пуст...\n";

	}
	else {

		Chain* tempCh1 = ch1;
		Chain* tempCh2 = ch2;

		Chain* last = chain;

		while (last != NULL) {

			if (last->data > 0) {

				if (ch1 == NULL) {

					ch1 = new Chain;
					ch1->data = last->data;
					ch1->next = NULL;
					tempCh1 = ch1;

				}
				else {

					tempCh1->next = new Chain;
					tempCh1 = tempCh1->next;
					tempCh1->data = last->data;
					tempCh1->next = NULL;

				}

			}
			else if (last->data < 0) {

				if (ch2 == NULL) {

					ch2 = new Chain;
					ch2->data = last->data;
					ch2->next = NULL;

				}
				else {

					tempCh2 = new Chain;
					tempCh2->data = last->data;
					tempCh2->next = ch2;
					ch2 = tempCh2;

				}

			}

			last = last->next;

		}

	}

}

Chain* join2Lists2(Chain* first, Chain* second) {

	Chain* tempSecond = second;
	Chain* tempFirst = first;
	Chain* list = new Chain;
	Chain* ind = list;

	while ((tempFirst != NULL) && (tempSecond != NULL)) {

		ind->next = new Chain;
		ind = ind->next;
		ind->data = tempFirst->data + tempSecond->data;
		ind->next = NULL;

		tempFirst = tempFirst->next;
		tempSecond = tempSecond->next;

	}

	list = list->next;

	return list;

}

Chain* readFromFile(std::string fileName) {

	std::ifstream file;
	file.open(fileName);

	Chain* list = NULL;
	Chain* ind = NULL;

	if (file.is_open()) {

		while (!file.eof()) {

			if (ind == NULL) {

				list = new Chain;
				ind = list;

				file >> ind->data;
				ind->next = NULL;

			}
			else {

				ind->next = new Chain;
				ind = ind->next;

				file >> ind->data;
				ind->next = NULL;

			}

		}

		file.close();
	
	}

	return list;

}

void editChains(Chain*& first, Chain*& second, int x) {

	while ((first != NULL) && (first->data != x)) {

		Chain* temp = new Chain;
		temp->data = first->data;
		temp->next = second;
		second = temp;

		Chain* ind = first->next;

		delete first;

		first = ind;

	}

}


void editChains2(Chain*& list, int z) {

	Chain* chain = list;
	Chain* preview = NULL;

	while ((chain != NULL) && (chain->data != 0)) {
		if (chain->data == z) {
			if (preview == NULL) {
				Chain* temp = chain->next;
				delete chain;
				chain = temp;
				list = temp;

			}
			else if (chain->next == NULL) {
				Chain* temp = preview->next;
				delete temp;
				preview->next = NULL;
				chain = preview;

			}
			else {
				Chain* temp = chain->next;
				delete chain;
				preview->next = temp;
				chain = temp;


			}

		}
		else {
			preview = chain;
			chain = chain->next;

		}

	}

}


void editChains3(Chain*& list, int x, int z) {

	Chain* chain = list;
	Chain* preview = NULL;

	while (chain != NULL) {

		if (chain->data == z) {
			Chain* temp = new Chain;
			temp->data = x;
			temp->next = chain;

			if (preview == NULL) { 
				list = temp;

			}
			else {
				preview->next = temp;

			}
			

		}

		preview = chain;
		chain = chain->next;


	}

}