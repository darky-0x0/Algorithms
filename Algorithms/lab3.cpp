#include "lab3.h"


void mainMenuLab3() {

	std::cout << "Номер задания:\n\\"; int taskNum; std::cin >> taskNum;

	std::string str; std::getline(std::cin, str);

	switch (taskNum)
	{
	case 1: {
		std::cout << "\nВведите выражение, дабы проверить корректность скобок:\n\\";
		std::string str; std::getline(std::cin, str);

		staples(str);
		break;

	}
	case 2: {
		std::cout << "\nВведите польскую запись на вычисление(как минимум 2 значения вначале):\n\\";
		std::string str; std::getline(std::cin, str);

		PolishWrite(str); 

		break;

	}
	case 3: {
		std::cout << "\nВведите запись, которую вы хотите преобразовать в польскую:\n\\";
		std::string str; std::getline(std::cin, str);

		PolishWriting(str);

		break;

	}
	case 4: {
		lab3task4();
		break;

	}
	case 5: {
		lab3task5();
		break;

	}
	default: {
		std::cout << "Некорректный номер\n\\";
		break;

	}
	}

}



void staples(std::string str) {
	
	bool isCorrect(true);

	Chain3* stack = NULL;

	for (int i = 0; (i < str.size()) && (isCorrect == true); i++) {
		if (str[i] == '(' || str[i] == '<' || str[i] == '[' || str[i] == '{') {
			Chain3* temp = new Chain3;

			temp->data = str[i];
			temp->next = stack;
			stack = temp;

		}
		else if (str[i] == ')' || str[i] == '>' || str[i] == ']' || str[i] == '}') {
			if (stack != NULL) {
				if (abs(stack->data - str[i]) <= 2) { //разница в таблице ASCII
					Chain3* temp = stack->next;
					delete stack;
					stack = temp;
				}

			}
			else isCorrect = false;


		}

	}

	if (stack != NULL) isCorrect = false;

	if (isCorrect == true) std::cout << "\nСтрока корректна";
	else std::cout << "\nВведена некорректная строка";

}

float PolishWrite(std::string str) {

	Chain4* stack = NULL;
	char numbersType(NULL); 
	bool isError(NULL);

	for (int i = 0; (i < str.size()) && (numbersType == NULL); i++) { //автоопрделние типов чисел
		if (isOperand(str[i])) {
			if ((i != 0) && (str[i - 1] == ' ')) numbersType = 'b';
			else numbersType = 'a';

		}

	}

	if (numbersType == NULL) {
		std::cout << "\nНеверный формат выражения";

	}
	else {
		setlocale(LC_ALL, "en-US");

		for (int i = 0; (i < str.size()) && isError == false; i++) { //идём до конца строки или до первой ошибки
			bool isNegativeNumber = false;
			if (i < str.size() && numbersType == 'b' && str[i] == 45 && isDigit(str[i])) isNegativeNumber = true; //определение унарного/бинарного минуса (если во втором случае после минуса стоит число, а не пробел, значит он унарный)

			if (isDigit(str[i]) || isNegativeNumber) { //добавление числа в стек
				Chain4* temp = new Chain4;

				if (numbersType == 'a') {
					char chr = str[i];
					temp->data = std::atoi(&chr);
					temp->next = stack;
					stack = temp;
				}
				else {
					std::string num;
					num = str[i];
					for (int j = i + 1; j < str.size() && (str[j] != ' '); j++ && i++) { //сборка числа
						num += str[j];

					}

					float tmp = std::stof(num);
					temp->data = tmp;
					temp->next = stack;
					stack = temp;

				}

			}
			else if(str[i] != ' ') { //операции над стеком
				if (stack == NULL || stack->next == NULL) { //если в стеке меньше двух ячеек
					isError = true;

				}
				else {
					float a(stack->data);
					float b(stack->next->data);
					float result;
					Chain4* temp = stack->next;
					delete stack;
					stack = temp;

					result = calculateOperation(a, b, str[i], numbersType);

					stack->data = result;


				}

			}

		}
		
		setlocale(0, "");
	
	}


	if ((stack != NULL && stack->next == NULL) && isError == false) {
		std::cout << "\nРезультат операций: " << stack->data;

	}
	else if(isError == true) std::cout << "\nНеверный формат выражения";

	return stack->data;

}


float calculateOperation(float b, float a, int operation, char NT) {

	float result(0.0);

	switch (operation)
	{
	case '+': {
		result = a + b;
		break;
	}
	case '-': {
		result = a - b;
		break;
	}
	case '*': {
		result = a * b;
		break;
	}
	case '/': {
		if (NT == 'a') {
			result = (int)a / (int)b;
		}
		else result = a / b;
		break;
	}
	case '%': {
		result = (int)a % (int)b;
		break;
	}
	case '^': {
		result = pow(a, b);
		break;
	}
	default:
		break;
	}

	return result;

}


void PolishWriting(std::string str) {

	Chain5* stack = NULL;
	std::string result;

	for (int i = 0; i < str.size(); i++) {
		if (isDigit(str[i])) {
			result += str[i];

		}
		else {
			if ((str[i] == ')')) {
				while (stack->data != '(') { //выход из скобок
					result += stack->data;
					chain5Pop(stack);

				}
				chain5Pop(stack);

			}
			else if (str[i] == '(' || stack == NULL || isPriority(stack->data, str[i])) {
				chain5PushBack(stack, str[i]);

			}
			else {
				do
				{
					result += stack->data;
					chain5Pop(stack);

				} while (stack != NULL && stack->data != '(' && (isPriority(stack->data, str[i])));

				if (stack != NULL && stack->data == '(') {
					chain5Pop(stack);

				}

				chain5PushBack(stack, str[i]);

			}

		}

	}

	while (stack != NULL) {
		result += stack->data;
		chain5Pop(stack);

	}

	std::cout << "\nПольская запись: " << result;
	PolishWrite(result);

}

bool isOperand(int asciiCod) {
	if (asciiCod == '+' || asciiCod == '-' || asciiCod == '*' || asciiCod == '/' || asciiCod == '%' || asciiCod == '^') return true;
	else return false;

}

bool isDigit(int asciiCod) {
	if (asciiCod >= '0' && asciiCod <= '9') return true;
	else return false;

}

bool isPriority(int a, int b) {
	std::vector<int> priority = { 40, 43, 45, 37, 47, 42, 93 }; //ASCII операндов

	for (int i = 0; i < priority.size(); i++) {
		if (priority[i] == a) return true;
		else if (priority[i] == b) return false;

	}

}

void chain5PushBack(Chain5*& stack, char chr) {
	Chain5* temp = new Chain5;
	temp->data = chr;
	temp->next = stack;
	stack = temp;

}

void chain5Pop(Chain5*& stack) {
	Chain5* temp = stack->next;
	delete stack;
	stack = temp;

}

void lab3task4() {
	Chain* stack1 = NULL;
	Chain* stack2 = NULL;
	std::ifstream in;
	std::ofstream out;
	in.open("input4.txt");
	out.open("output4.txt");

	std::cout << "Введите границы отрезка [a, b]: ";
	int a, b; std::cin >> a >> b;

	int num;
	std::string str;

	while (std::getline(in, str)) {

		std::stringstream ss(str);

		while (!ss.eof()) {
			ss >> num;
			if (num < a) {
				out << num << ' ';

			}
			else if (num < b) {
				(num);

			}
			else {
				push_2(num);

			}

		}

		while (!empty_1()) {
			pop_1(num);
			fout << num << ' ';

		}
		out << "\n";
		while (!empty_2()) {
			pop_2(num);
			fout << num << ' ';

		}

	}
	std::cout << "output_4.txt готов.\n\n";

}

void lab3task5() {



}