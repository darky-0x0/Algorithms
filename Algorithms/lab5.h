#pragma once
#include "lab1.h"
#include <iostream>
#include <sstream>
#include <vector>


void mainMenuLab5();


void lab5task1();

std::vector<Chain*> readGraphFromFile(std::string);

void SearchDepth(std::vector<Chain*>, int, std::vector<std::pair<int, int>>&, std::vector<bool>&);

