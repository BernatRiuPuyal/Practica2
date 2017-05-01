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

bool actDiscovered(std::vector<std::string> discovered, std::string newElement) {

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
	
	std::string first, second, inString;
	int inInt1, inInt2;
	bool isNumber;

	Combinations posCom;

	posCom.print();

	while (score < posCom.combinations.size()) {

		std::cout << "SCORE:" << score << std::endl;
		std::cout << "Inventory:" << std::endl;
		printVector(table);

		std::cin >> first >> second;
		
		isNumber = true;

		for(int i = 0; i < first.length(); i++){
			if(!isdigit(first[i])){
				isNumber = false;
			}		
		}
		
		if(isNumber){
			inInt1 = atoi(first);
			inInt2 = atoi(second);

			//aqui funció per combinar dos elements. 

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

		if (actDiscoverd(discovered, /*NEW - ELEMENT*/)) {
			discovered.push_back(/*NEW - ELEMENT*/);
			score++;
		}
	}
}

