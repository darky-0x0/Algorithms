#include "lab4.h"


void mainMenuLab4() {
	std::cout << "Ќомер задани€:\n\\"; int taskNum; std::cin >> taskNum;
	std::string str; std::getline(std::cin, str);

	switch (taskNum)
	{
	case 1: {
		lab4task1();
		break;

	}
	case 2: {
		lab4task2();
		break;

	}
	case 3: {
		lab4task3();
		break;

	}
	case 4: {
		lab4task4();
		break;

	}
	default: {
		std::cout << "Ќекорректный номер\n\\";
		break;

	}
	}

}


void lab4task1() {
	std::cout << "¬ведите число int n, (n>0)\n\\";
	int n; std::cin >> n;

	BigNumber num;
	BigNumber tempNum; //второй множитель

	for (int i = 2; i <= n; i++) {
		initNum(tempNum, i);
		num = multiply(num, tempNum);
		delBigNum(tempNum);

	}

	printBigNum(num);

}

void lab4task2() {
	BigNumber num1;
	BigNumber num2;
	std::cout << "¬ведите первое большое число:\n\\";
	std::string BigNum1; std::getline(std::cin, BigNum1);
	initNum(num1, BigNum1);
	std::cout << "¬ведите второе большое число:\n\\";
	std::string BigNum2; std::getline(std::cin, BigNum2);
	initNum(num2, BigNum2);
	
	BigNumber result = multiply(num1, num2);
	printBigNum(result);

}

void lab4task3() {


}

void lab4task4() {


}


BigNumber multiply(BigNumber& BigNum1, BigNumber& BigNum2) {
	int t(0); //число смещени€
	BigNumber result; 
	BigNumber multiplyTemp; //временна€ сторка при перемножении

	Digit* num1 = BigNum1.last;
	Digit* num2 = BigNum2.last;

	if (num1 == NULL) {
		Digit* tempNum = new Digit;
		tempNum->data = num2->data;
		result.first = tempNum;
		result.last = tempNum;
		

	}
	else {
		while (num2 != NULL) {
			num1 = BigNum1.last;
			short transfer(0);
			while (num1 != NULL) {
				short temp = num1->data * num2->data + transfer;
				transfer = 0;
				if (temp >= 10) {
					transfer = temp / 10; //перенос
					temp = temp % 10;
					
				} 
				addBeggin(multiplyTemp, temp);

				num1 = num1->prev;

			}

			if (transfer != 0) addBeggin(multiplyTemp, transfer);

			for (int i = 0; i < t; i++) {
				addEnd(multiplyTemp, 0); //смещение строки при сложении
			}
			t++;

			result = summBigNum(result, multiplyTemp);

			num2 = num2->prev;

		}

	}

	if (BigNum1.positive == false || BigNum2.positive == false) result.positive = false;

	return result;

}


void initNum(BigNumber& num, int n) {
	delBigNum(num);

	Digit* temp = new Digit;

	num.last = temp;

	while (n != 0) {
		temp->data = n % 10;
		n /= 10;
		if (n != 0) {
			Digit* temp2 = new Digit;
			temp2->next = temp;
			temp->prev = temp2;
			temp = temp2;
		}

	}

	num.first = temp;

}

void initNum(BigNumber& num, std::string str) {
	for (int i = 0; i < str.size(); i++) {
		if (i == '-') num.positive = false;
		else {
			char chr = str[i];
			addEnd(num, std::atoi(&chr));

		}

	}

}

void delBigNum(BigNumber& num) {
	Digit* tempNum = num.first;

	while (tempNum != NULL) {
		Digit* temp = tempNum->next;
		delete tempNum;
		tempNum = temp;

	}

	num.first = NULL;
	num.last = NULL;

}

BigNumber summBigNum(BigNumber& BigNum1, BigNumber& BigNum2) {
	BigNumber result;

	Digit* num1 = BigNum1.last;
	Digit* num2 = BigNum2.last;

	short transfer(0); //перенос
	while ((num1 != NULL) && (num2 != NULL)) {
		int temp = num1->data + num2->data + transfer;
		transfer = 0;
		if (temp >= 10) {
			transfer = temp / 10; //перенос
			temp = temp % 10;

		}
		addBeggin(result, temp);

		num1 = num1->prev;
		num2 = num2->prev;

	}

	while (num1 != NULL) {
		int temp = num1->data + transfer;
		transfer = 0;
		if (temp >= 10) {
			transfer = temp / 10; //перенос
			temp = temp % 10;

		}
		addBeggin(result, temp);

		num1 = num1->prev;

	}

	while (num2 != NULL) {
		int temp = num2->data + transfer;
		transfer = 0;
		if (temp >= 10) {
			transfer = temp / 10; //перенос
			temp = temp % 10;

		}
		addBeggin(result, temp);

		num2 = num2->prev;

	}

	if(transfer != 0) addBeggin(result, transfer);

	delBigNum(BigNum1);
	delBigNum(BigNum2);

	return result;

}

void addBeggin(BigNumber& num, int n) {
	if (num.first == NULL) {
		Digit* temp = new Digit;
		temp->data = n;
		num.first = temp;
		num.last = temp;

	}
	else {
		num.first->prev = new Digit;
		Digit* temp = num.first;
		num.first = num.first->prev;
		num.first->data = n;
		num.first->next = temp;

	}

}

void addEnd(BigNumber& num, int n) {
	if (num.last == NULL) {
		Digit* temp = new Digit;
		temp->data = n;
		num.first = temp;
		num.last = temp;

	}
	else {
		num.last->next = new Digit;
		Digit* temp = num.last;
		num.last = num.last->next;
		num.last->data = n;
		num.last->prev = temp;

	}

}

void printBigNum(BigNumber& num) {
	Digit* digit = num.first;
	std::cout << "\n\\";
	if (num.positive == false) std::cout << "-";
	while (digit != NULL) {
		std::cout << digit->data;
		digit = digit->next;

	}

}