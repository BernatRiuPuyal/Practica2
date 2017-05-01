#include <fstream>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <cstdlib>
#include "Combinations.h"
#include "Instructions.h"

void printVector(std::vector<std::string> vectorio) {

	for (int it = 0; it < vectorio.size(); it++) {

		std::cout << it + 1 << ": " << vectorio[it] << std::endl;
	}
}

bool isNumber(std::string){

	bool isNumber = true;

	for(int i = 0; i < first.length(); i++){
		if(!isdigit(first[i])){
			isNumber = false;
		}		
	}

	return isNumber;
}

bool actualize(std::vector<std::string> discovered, std::string newElement) {

	bool toAdd = true;

	for (int i = 0; i < discovered.size; i++) {
		if (newElement == discovered[i]) {
			toAdd = false;
		}
	}

	return toAdd;
}

int main(void) {

	std::vector<std::string>table({ "Air","Water","Earth","Fire" });
	std::vector<std::string>discovered({ "Air","Water","Earth","Fire" });
	
	int score = 0;
	
	std::string first, second, inString, newElement;
	int inInt1, inInt2;

	Combinations posCom;

	posCom.print();

	while (score < posCom.combinations.size()) {

		std::cout << "SCORE:" << score << std::endl;
		std::cout << "Inventory:" << std::endl;
		printVector(table);

		std::cin >> first >> second;
		
		if(isNumber(first)){

			inInt1 = atoi(first);
			inInt2 = atoi(second);

			newElement = posCom.combinations[first, second]; //no funciona aixi, em sembla

		} else {

			inInt2 = atoi(second);

			switch(inString){
				case "add":
					add(table, inInt2);
					break;
				case "add basics":
					addBasics(table);
					break;
				case "delete":
					deleteFunct(table, inInt2);
					break;
				case "info":
					info(table, inInt2);
					break;
				case "sort":
					sort(table);
					break;
				case "clean":
					clean(table);
					break;
				case "help":
					help();
					break;
				default:
					std::cout << "Instruction not understood" << std::endl;
					break;
			}
		}

		if (actualize(discovered, newElement)) {
			discovered.push_back(newElement);

			table.erase(table.begin() + first);
			table.erase(table.begin() + second);

			score++;
		}
	}
}

