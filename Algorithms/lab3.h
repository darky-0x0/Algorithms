#pragma once

#include "lab1.h"
#include <math.h>
#include <vector>
#include <fstream>
#include <string>

struct Chain3 { ///chars

	char data;
	Chain3* next;

};

struct Chain4 { ///chars

	float data;
	Chain4* next;

};

struct Chain5 { ///chars

	char data;
	Chain5* next;

};


void mainMenuLab3();

void staples(std::string);
float PolishWrite(std::string);

float calculateOperation(float, float, int, char);

void PolishWriting(std::string);

bool isOperand(int);

bool isDigit(int);

/// <summary>
/// Проверка условия приоритета операндов
/// Операнд2 старше операнд1 - true
/// иначе - false
/// </summary>
/// <param name="op1 - junior"></param>
/// <param name="op2 - senior"></param>
/// <returns></returns>
bool isPriority(int, int);

void chain5Write(Chain5*&, char);

void chain5Read(Chain5*&);

void lab3task4();

void lab3task5();

int queueRead(Chain*&);

void queueWrite(Chain*&, int);

int queueRead(Chain3*&);

void queueWrite(Chain3*&, int);

bool queueEmpty(Chain*);