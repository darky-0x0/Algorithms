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
	std::vector<Chain*> graph;
	graph = readGraphFromFile("lab5task1.txt");
	std::vector<std::pair<int, int>> result;
	std::vector<bool> passed(graph.size(), false);
	passed[1] = true;

	SearchDepth(graph, 1, result, passed);

	for (std::pair<int, int> path : result)
	{
		std::cout << path.first << " -> " << path.second << std::endl;
	}

}


std::vector<Chain*> readGraphFromFile(std::string filename) {
	std::vector<Chain*> graph;
	Chain* tempNullPlug = new Chain;
	graph.push_back(tempNullPlug);
	std::string s;
	
	std::ifstream out;
	out.open(filename);

 	while (std::getline(out, s)) {
		Chain* list = new Chain;
		Chain* temp = list;
		Chain* lastConnectPoint = NULL;
		int counter(1);
		bool oneConnectPoint(true); //одиночный элемент графа
		for (int i = 0; i < s.size(); i+=2) {
			if (s[i] == '1') {
				lastConnectPoint = temp;
				temp->data = counter;
				temp->next = new Chain;
				temp = temp->next;
				oneConnectPoint = false;

			}
			counter++;

		}
		if (oneConnectPoint == false) {
			delete lastConnectPoint->next;
			lastConnectPoint->next = NULL;

		}
		else {
			delete lastConnectPoint;
			lastConnectPoint = NULL;

		}
		graph.push_back(list);

	}

	return graph;

}

void SearchDepth(std::vector<Chain*> graph, int vertex, std::vector<std::pair<int, int>>& result, std::vector<bool>& passed) {
	Chain* paths = graph[vertex];

	while (paths != NULL) {
		if (!passed[paths->data]) {
			passed[paths->data] = true;
			result.push_back(std::pair<int, int>(vertex, paths->data));
			SearchDepth(graph, paths->data, result, passed);
			
		}
		paths = paths->next;

	}

}
