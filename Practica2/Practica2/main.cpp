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

		std::cout << it/* + 1*/ << ": " << vectorio[it] << std::endl;
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






int main(void) {

	std::vector<std::string>table({ "Air","Water","Earth","Fire" });
	std::vector<std::string>discovered({ "Air","Water","Earth","Fire" });
	
	int score = 0;
	
	std::string first, second, inString, newElement;
	int inInt1, inInt2;

	Combinations posCom;

	//posCom.print();

	while (score < posCom.combinations.size()) {

		

		std::cout << "SCORE:" << score << std::endl << std::endl;
		std::cout << "Inventory:" << std::endl;
		printVector(table);

		std::cin >> first;
		system("cls");
		


		if (isNumber(first)) {
			std::cin >> second;

			inInt1 = atoi(first.c_str()); // c_str converteix  de string de C++ a string de C, que es amb el qual funciona l'atoi
			inInt2 = atoi(second.c_str());
			if (inInt1 < table.size() && inInt2 < table.size()){
				barreja entrada(table[inInt1], table[inInt2]);
				bool foundElement = false;
				if (posCom.combinations.count(entrada) == 0) {
					entrada.first = table[inInt2];
					entrada.second = table[inInt1];

					if (posCom.combinations.count(entrada) == 0) {
						std::cout << "Not a possible Combination" << std::endl;
					}
					else {
						foundElement = true;
					}
				}
				else {
					foundElement = true;
				}

				if (foundElement) {
					newElement = posCom.combinations[entrada];
					table.erase(table.begin() + max(inInt1, inInt2));
					table.erase(table.begin() + min(inInt1, inInt2));
					table.push_back(newElement);



					bool discoveredElement = true;
					for (int i = 0; i < discovered.size(); i++) {
						if (newElement == discovered[i]) {
							discoveredElement = false;
						}
					}
					if (discoveredElement) {
						discovered.push_back(newElement);
						score++;
					}

				}


			}
			else {
				std::cout << "Number out of the table" << std::endl;
			}
		}
		else {

			
			if (first == "add") {
				std::cin >> second;

				if (second == "basics") {

					addBasics(table);
				}
				else if (isNumber(second)) {
					inInt2 = atoi(second.c_str());
					if (inInt2 < table.size()) {
						add(table, inInt2);
					}
					else {
						std::cout << "Number out of the table" << std::endl;
					}
				}
				else {
					std::cout << "Instruction not understood" << std::endl;
				}
				
			}
			
			else if (first == "delete") {
				std::cin >> second;
				inInt2 = atoi(second.c_str());
				deleteFunct(table, inInt2);
			}

			else if (first == "info") {
				std::cin >> second;

				inInt2 = atoi(second.c_str());

				if (inInt2 < table.size()) {
					info(table, inInt2);
				}
				else {
					std::cout << "Number out of the table" << std::endl;
				}

				
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

	}
	
}

