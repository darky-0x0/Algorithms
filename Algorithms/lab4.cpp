#include "lab4.h"


void mainMenuLab4() {
	std::cout << "Номер задания:\n\\"; int taskNum; std::cin >> taskNum;
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
		std::cout << "Некорректный номер\n\\";
		break;

	}
	}

}


void lab4task1() {
	std::cout << "Введите число int n, (n>0)\n\\";
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
	std::cout << "Введите первое большое число:\n\\";
	std::string BigNum1; std::getline(std::cin, BigNum1);
	initNum(num1, BigNum1);
	std::cout << "Введите второе большое число:\n\\";
	std::string BigNum2; std::getline(std::cin, BigNum2);
	initNum(num2, BigNum2);
	
	BigNumber result = multiply(num1, num2);
	printBigNum(result);

}

void lab4task3() {
	BigNumber num1;
	BigNumber num2;
	BigNumber result;
	std::cout << "Введите первое большое число:\n\\";
	std::string BigNum1; std::getline(std::cin, BigNum1);
	initNum(num1, BigNum1);
	std::cout << "Введите второе большое число:\n\\";
	std::string BigNum2; std::getline(std::cin, BigNum2);
	initNum(num2, BigNum2);

	if (comparator(num1, num2) == false) {
		BigNumber temp = num1;
		num1 = num2;
		num2 = temp;
	}

	result = difference(num1, num2);


	printBigNum(result);

}

void lab4task4() {
	BigNumber num1;
	BigNumber num2;
	BigNumber result;
	std::cout << "Введите первое большое число:\n\\";
	std::string BigNum1; std::getline(std::cin, BigNum1);
	initNum(num1, BigNum1);
	std::cout << "Введите второе большое число:\n\\";
	std::string BigNum2; std::getline(std::cin, BigNum2);
	initNum(num2, BigNum2);

	result = division(num1, num2);
	printBigNum(result);
}


BigNumber multiply(BigNumber& BigNum1, BigNumber& BigNum2) {
	int t(0); //число смещения
	BigNumber result; 
	BigNumber multiplyTemp; //временная сторка при перемножении

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
		if (str[i] == '-') {
			num.positive = false;
		}
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

bool comparator(BigNumber& num1, BigNumber& num2) {
	bool bigOne(false);
	Digit* digit1 = num1.first;
	Digit* digit2 = num2.first;

	if (num1.positive == false && num2.positive == true) bigOne = false;
	else if (num2.positive == false && num1.positive == true) bigOne = true;
	else {
		bool oneComparation(false);
		while ((digit1 != NULL) && (digit2 != NULL)) {
			if (oneComparation == false) { //первое успешное сравнение
				if(digit1->data != digit2->data) oneComparation = true;
				if (digit1->data > digit2->data) bigOne = true;
				else if (digit1->data < digit2->data) bigOne = false;
			}
			digit1 = digit1->next;
			digit2 = digit2->next;

		}
		if (digit1 != NULL || digit2 != NULL) { //проверка по размеру
			if (digit1 == NULL) bigOne = false;
			else bigOne = true;

		}

	}

	if (num2.positive == false && num1.positive == false) if (bigOne == true) bigOne = false; else bigOne = true;

	return bigOne;

}

bool equality(BigNumber& num1, BigNumber& num2) {
	Digit* digit1 = num1.first;
	Digit* digit2 = num2.first;
	while ((digit1 != NULL) && (digit2 != NULL)) {
		if (digit1->data != digit2->data) return false;
		digit1 = digit1->next;
		digit2 = digit2->next;
	}
	if (digit1 != NULL || digit2 != NULL) return false; //разные по размеру
	return true;
}

BigNumber difference(BigNumber& num1, BigNumber& num2) {
	BigNumber result;

	if ((num2.positive == false) && (num1.positive == true)) result = summBigNum(num1, num2);
	else {
		if ((num1.positive == false && (num2.positive == false))) {
			BigNumber temp = num1;
			num1 = num2;
			num2 = temp;

		}

		Digit* digit1 = num1.last;
		Digit* digit2 = num2.last;

		short transfer(0); //занимаем
		while ((digit1 != NULL) && (digit2 != NULL)) {
			int temp = digit1->data - digit2->data - transfer;
			transfer = 0;
			if (temp < 0) {
				transfer += 1; //перенос
				temp += 10; //увеличиваем разряд

			}
			addBeggin(result, temp);

			digit1 = digit1->prev;
			digit2 = digit2->prev;

		}

		while (digit1 != NULL) {
			int temp = digit1->data - transfer;
			transfer = 0;
			if (temp < 0) {
				transfer = abs(temp); //перенос
				temp += 10; //увеличиваем разряд

			}
			if (!(digit1->prev == NULL && temp == 0)) addBeggin(result, temp);

			digit1 = digit1->prev;

		}

		while (digit2 != NULL) {
			int temp = digit2->data - transfer;
			transfer = 0;
			if (temp < 0) {
				transfer = abs(temp); //перенос
				temp += 10; //увеличиваем разряд

			}
			if (digit2->prev != NULL) addBeggin(result, temp);

			digit2 = digit2->prev;

		}
	}

	while ((result.first != NULL) && (result.first->data == 0)) {
		Digit* temp = result.first;
		result.first = temp->next;
		delete temp;
		temp = result.first;
		if(temp != NULL) temp->prev = NULL;
		if (temp == NULL) result.last = NULL;
	}

	delBigNum(num1);

	return result;

}


BigNumber division(BigNumber& num1, BigNumber& num2) {
	BigNumber result;
	if (comparator(num2, num1)) { //если второе больше
		addEnd(result, 0);
		return result;
	}
	else {
		BigNumber dividend;

		Digit* digit = num1.first;

		do
		{
			addEnd(dividend, digit->data);
			digit = digit->next;

		} while ((digit != NULL) && (comparator(num2, dividend))); //первый добор делимого

		while (true) {
			if (digit != NULL) {
				int i(0);

				while ((digit != NULL) && (comparator(num2, dividend))) { //первый добор делимого
					addEnd(dividend, digit->data);
					digit = digit->next;
					i++;
					if (i > 1) addEnd(result, 0); //смещаем на 0, если взяли больше одного десятка

				}

				if ((digit != NULL) || (digit == NULL && comparator(dividend, num2))) { //если мы не дошли до конца числа, или дошли и получили верное делимое

					int counter(0);
					do
					{
						dividend = difference(dividend, num2);
						counter++;
					} while ((comparator(dividend, num2)) || (equality(dividend, num2))); //вычитаем, пока делимое больше или равен делителю

 					addEnd(result, counter);

				}
				else if ((digit == NULL) && i != 0) addEnd(result, 0); //если уткнулись в конец числа, но дополнили делимое разрядами, а делимое получилось меньше делителя
				else return result;
			}
			else return result;

		}

	}

}


