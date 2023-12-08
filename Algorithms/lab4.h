#pragma once
#include <iostream>
#include <sstream>




struct Digit {

	int data = 0;
	Digit* next = NULL;
	Digit* prev = NULL;

};

struct BigNumber {

	Digit* first = NULL;
	Digit* last = NULL;
	bool positive = true;

};



void mainMenuLab4();

void lab4task1();
void lab4task2();
void lab4task3();
void lab4task4();

BigNumber multiply(BigNumber&, BigNumber&);

void initNum(BigNumber&, int);
void initNum(BigNumber&, std::string);

void delBigNum(BigNumber&);

BigNumber summBigNum(BigNumber&, BigNumber&);

void addBeggin(BigNumber&, int);
void addEnd(BigNumber&, int);

void printBigNum(BigNumber&);

/// <summary>
/// Число первое больше второго числа?
/// Число первое больше второго числа?
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
/// <returns></returns>
bool comparator(BigNumber&, BigNumber&);
bool equality(BigNumber&, BigNumber&);

BigNumber difference(BigNumber&, BigNumber&);

BigNumber division(BigNumber&, BigNumber&);