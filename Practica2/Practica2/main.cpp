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

		std::cout << it+ 1 << "." << vectorio[it] << std::endl;
	}
}

bool actDiscovered(std::vector discovered, std::string newElement) {

	bool toAdd = true;

	for (int i = 0; i < discovered.sizeof(); i++) {
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

	Combinations posCom;

	posCom.print();


	while (score < posCom.combinations.size()) {

		std::cout << "SCORE:" << score << std::endl;
		std::cout << "Elements in your table:" << std::endl;
		printVector(table);

		if (actDiscoverd(discovered, /*NEW - ELEMENT*/)) {
			discovered.push_back(/*NEW - ELEMENT*/);
			score++;
		}

	}
}

