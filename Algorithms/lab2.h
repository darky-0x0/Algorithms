#pragma once

#include "lab1.h"



void mainMenuLab2();
Chain* createLinealList();
void printChain(Chain* const);
Chain* sortListRecurs(Chain* const);
Chain* sortList(Chain* const);
Chain* join2Lists(Chain*, Chain*);
void create2Lists(Chain*, Chain*&, Chain*&);
Chain* join2Lists2(Chain*, Chain*);
Chain* readFromFile(std::string);
void editChains(Chain*&, Chain*&, int);
void editChains2(Chain*&, int);
void editChains3(Chain*&, int, int);