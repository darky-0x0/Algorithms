#pragma once

#include <iostream>
#include <sstream>
#include "lab1.h"



void mainMenuLab2();
Chain* createLinealList();
void printChain(Chain* const);
Chain* sortListRecurs(Chain* const);
Chain* sortList(Chain* const);
Chain* join2Lists(Chain*, Chain*);
void create2Lists(Chain*, Chain*&, Chain*&);