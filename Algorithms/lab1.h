#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct Chain
{

	int data = 0;
	Chain* next = NULL;

};

void mainMenuLab1();

int summChain(Chain*);
void coutChain(Chain*);
void reverseCoutChain(Chain*);
void task5();
int bigNums(Chain*);
void task6();
float average(Chain*);
void task7();
int maxEl(Chain*);
void task8();
