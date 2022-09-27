#pragma once

#include <iostream>
#include <fstream>
using namespace std;

#define NO_OF_CHARS 256

int find_motive(string txt, string motive);
void badHeuristic(string str, int size, int badchar[NO_OF_CHARS]);