#include <fstream>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <cstdlib>
#include "Combinations.h"

void printVector(std::vector<std::string> vectorio) {

	for (int it = 0; it < vectorio.size(); it++) {

		std::cout << it+ 1 << "." << vectorio[it] << std::endl;
	}
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


		

	}
}

