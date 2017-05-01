#pragma once

#include "Instructions.h"
#include <fstream>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <cstdlib>

void add(std::vector<std::string> llista, int nombre);
void addBasics(std::vector<std::string> llista);
void deleteFunct(std::vector<std::string> llista, int nombre);
void info(std::vector<std::string> llista, int nombre);
void sort(std::vector<std::string> llista);
void clean(std::vector<std::string> llista);
void help();