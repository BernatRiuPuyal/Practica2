// rebuda i guardatge de les possibles combinacions

#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>

class Combinations {

	typedef std::pair<std::string, std::string> barreja;

	std::unordered_map < barreja, std::string>combinations;



	Combinations() {

		std::ifstream felements("elements.dat");



		std::string line;

		while (getline(felements, line)) {

			barreja barrejaInsert;
			std::pair<barreja, std::string> combinacioInsert;

			for (int it = line.begin; it < line.end; it++) {
				if (line[it] == ' ')
					line.erase(line[it],1);
			}

			unsigned int pos1 = line.find("=");
			unsigned int pos2 = line.find("+");

			combinacioInsert.second = line.substr(0,pos1);
					

			barrejaInsert.first = line.substr(pos1, pos2);
			barrejaInsert.second = line.substr(pos2, line.end);

			combinacioInsert.first = barrejaInsert;

			combinations.insert(combinacioInsert);

		}




	}





};