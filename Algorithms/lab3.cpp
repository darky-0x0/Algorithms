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
		if ((i != 0) && isOperand(str[i])) {
			if ((str[i - 1] == ' ')) numbersType = 'b';
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
			if (str[i] == '-' && i < str.size() - 1 && numbersType == 'b' && str[i + 1] != ' ') isNegativeNumber = true; //определение унарного/бинарного минуса (если во втором случае после минуса стоит число, а не пробел, значит он унарный)

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
			else if (str[i] != ' ') { //операции над стеком
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
		return stack->data;

	}
	else if (isError == true) std::cout << "\nНеверный формат выражения";

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
					chain5Read(stack);

				}
				chain5Read(stack);

			}
			else if (str[i] == '(' || stack == NULL || isPriority(stack->data, str[i])) {
				chain5Write(stack, str[i]);

			}
			else {
				do
				{
					result += stack->data;
					chain5Read(stack);

				} while (stack != NULL && stack->data != '(' && (isPriority(stack->data, str[i])));

				if (stack != NULL && stack->data == '(') {
					chain5Read(stack);

				}

				chain5Write(stack, str[i]);

			}

		}

	}

	while (stack != NULL) {
		result += stack->data;
		chain5Read(stack);

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
	int preorityA;
	int preorityB;

	if (a == '^') preorityA = 1;
	else if (a == '*' || a == '/') preorityA = 2;
	else if (a == '+' || a == '-') preorityA = 3;
	else preorityA = 4;

	if (b == '^') preorityB = 1;
	else if (b == '*' || b == '/') preorityB = 2;
	else if (b == '+' || b == '-') preorityB = 3;
	else preorityB = 4;

	if (preorityA < preorityB) return true;
	else return false;

}

void chain5Write(Chain5*& stack, char chr) {
	Chain5* temp = new Chain5;
	temp->data = chr;
	temp->next = stack;
	stack = temp;

}

void chain5Read(Chain5*& stack) {
	Chain5* temp = stack->next;
	delete stack;
	stack = temp;

}

void lab3task4() {
	Chain* queue1 = NULL;
	Chain* queue1End = queue1;
	Chain* queue2 = NULL;
	Chain* queue2End = queue2;
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
				queueWrite(queue1End, num);
				if (queue1 == NULL) queue1 = queue1End;


			}
			else {
				queueWrite(queue2End, num);
				if (queue2 == NULL) queue2 = queue2End;

			}

		}

		out << "\n";
		while (queue1 != NULL) {
			num = queueRead(queue1);
			out << num << ' ';

		}
		out << "\n";
		while (queue2 != NULL) {
			num = queueRead(queue2);
			out << num << ' ';

		}

	}
	std::cout << "output4.txt готов.\n\n";

}

void lab3task5() {

	std::ofstream out;
	std::ifstream in;
	in.open("input5.txt");
	out.open("output5.txt");

	int num;
	std::string s;
	while (std::getline(in, s)) {
		Chain3* queue = NULL;
		Chain3* queueEnd = queue;
		for (size_t i = 0; i < s.size(); ++i) {
			if ((int)s[i] > 47 && (int)s[i] < 58) {
				queueWrite(queueEnd, (int)s[i] - 48);
				if (queue == NULL) queue = queueEnd;
			}
			else {
				out << s[i];

			}

		}

		while (queue != NULL) {
			num = queueRead(queue);
			out << num;

		}
		out << '\n';

	}
	std::cout << "output5.txt готов\n\n";

}

int queueRead(Chain*& stack) {
	int num(stack->data);
	if (stack->next != NULL) {
		Chain* temp = stack->next;
		delete stack;
		stack = temp;
	}
	else {
		delete stack;
		stack = new Chain;

	}
	
	return num;

}

void queueWrite(Chain*& stack, int num) {
	Chain* temp = new Chain;
	temp->data = num;
	temp->next = NULL;
	if (stack->data == 0 && stack->next == NULL) stack = temp;
	else {
		Chain* firstEl = stack;
		while (stack->next != NULL) stack = stack->next;
		stack->next = temp;
		stack = firstEl;

	}

}

int queueRead(Chain3*& stack) {
	char chr(stack->data);
	Chain3* temp = stack->next;
	delete stack;
	stack = temp;

	return chr;

}

void queueWrite(Chain3*& stack, int num) {
	Chain3* temp = new Chain3;
	temp->data = num;
	temp->next = NULL;
	if (stack == NULL) stack = new Chain3;
	stack->next = temp;
	stack = temp;

}

bool queueEmpty(Chain* queue) {
	if (queue->data == 0 && queue->next == NULL) return true;
	return false;

}