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

		std::cout << it  << ": " << vectorio[it] << std::endl;
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
	std::vector<std::string>::iterator it;
	
	int score = 0;
	
	std::string first, second, inString, newElement;
	int inInt1, inInt2;

	Combinations posCom;

	if (!posCom.loadCheck()) system("pause");

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
			if (inInt1 < table.size() && inInt2 < table.size() && inInt1 != inInt2){
				barreja entrada(table[inInt1], table[inInt2]);
				barreja entradaInv(table[inInt2], table[inInt1]); //entrada inversa

				if (posCom.combinations.count(entrada) == 0) {							//es pot fer amb find??
					std::cout << "Not a possible Combination" << std::endl;
				}
				else if (posCom.combinations.count(entradaInv) == 0) {
					std::cout << "Not a possible Combination" << std::endl;
					entrada = entradaInv;
				}
				else {
					newElement = posCom.combinations[entrada];
					table.erase(table.begin() + max(inInt1, inInt2));
					table.erase(table.begin() + min(inInt1, inInt2));
					table.push_back(newElement);

					it = find (discovered.begin()), discovered.end(), newElement);

					if (it != discovered.end())
					{
						discovered.push_back(newElement);
						score++;
					}

				}

			}
			else {
				if (inInt1 == inInt2) std::cout << "You can not combine a element with itself" << std::endl;
				else std::cout << "Number out of the table" << std::endl;
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




		}

	}
	
}

