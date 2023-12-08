#include "lab5.h"


void mainMenuLab5() {
	std::cout << "Номер задания:\n\\"; int taskNum; std::cin >> taskNum;
	std::string str; std::getline(std::cin, str);

	switch (taskNum)
	{
	case 1: {
		lab5task1();
		break;

	}
	case 2: {

		break;

	}
	case 3: {

		break;

	}
	case 4: {

		break;

	}
	case 5: {

		break;

	}
	default: {
		std::cout << "Некорректный номер\n\\";
		break;

	}
	}

}


void lab5task1() {
	

}

/*
std::vector<Chain*> readFromFile(std::string filename) {
	std::vector<Chain*> graph;
	
	std::ifstream out;
	out.open(filename);

	while (!out.eof()) {
		std::istringstream ss(out, cin);


	}


}
*/