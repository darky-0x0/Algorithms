#pragma once
#include <iostream>
#include <sstream>




struct Digit {

	int data;
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