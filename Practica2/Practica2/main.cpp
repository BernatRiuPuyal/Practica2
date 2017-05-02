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

bool isNumber(std::string stringi){

	bool isNumber = true;

	for(int i = 0; i < stringi.length(); i++){
		if(!isdigit(stringi[i])){
			isNumber = false;
		}		
	}

	return isNumber;
}

bool actualize(std::vector<std::string> discovered, std::string newElement) {

	bool toAdd = true;

	for (int i = 0; i < discovered.size(); i++) {
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

	//posCom.print();

	while (score < posCom.combinations.size()) {

		std::cout << "SCORE:" << score << std::endl;
		std::cout << "Inventory:" << std::endl;
		printVector(table);

		std::cin >> first >> second;
		
		/*first = inString.substr(0, inString.find(" "));
		second = inString.substr(inString.find(" ") + 1, inString.npos - inString.find(" "));*/


		if(isNumber(first)){

			inInt1 = atoi(first.c_str()); // c_str converteix  de string de C++ a string de C, que es amb el qual funciona l'atoi
			inInt2 = atoi(second.c_str());

			barreja entrada(table[inInt1], table[inInt2]);

			newElement = posCom.combinations[entrada]; //no funciona aixi, em sembla - tu si que no funciones

			table.erase(table.begin() + inInt1);
			table.erase(table.begin() + inInt2);

		} else {

			inInt2 = atoi(second.c_str());
						
			

			if (first == "add") {

				add(table, inInt2);
			}
			else if (first == "add basics") {
				addBasics(table);
			}
			else if (first == "add basics") {
				deleteFunct(table, inInt2);
			}

			else if (first == "info") {
				info(table, inInt2);
			}
			else if (first == "sort") {
				sort(table);
			}
			else if (first == "clean") {
				clean(table);
			}
			else if (first == "help") {
				help();
			}
			else {
				std::cout << "Instruction not understood" << std::endl;
			}




			//switch (first) {
			//	case "add":
			//		add(table, inInt2);
			//		break;
			//	case "add basics":
			//		addBasics(table);
			//		break;
			//	case "delete":
			//		deleteFunct(table, inInt2);
			//		break;
			//	case "info":
			//		info(table, inInt2);
			//		break;
			//	case "sort":
			//		sort(table);
			//		break;
			//	case "clean":
			//		clean(table);
			//		break;
			//	case "help":
			//		help();
			//		break;
			//	default:
			//		std::cout << "Instruction not understood" << std::endl;
			//		break;
			//}
		}

		if (actualize(discovered, newElement)) {
			discovered.push_back(newElement);

			score++;
		}
	}
}

