// rebuda i guardatge de les possibles combinacions

#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>




class Combinations {

	typedef std::pair<std::string, std::string> barreja;


	struct barrejaHash {

		size_t operator()(const barreja &c) {

			return ((std::hash<char>()(c.first[0]) ^ (std::hash<char>()(c.second[0]) << 1)) >> 1);

		}

		};
	




	std::unordered_map < barreja, std::string,barrejaHash>combinations;



	Combinations() {

		std::ifstream felements("elements.dat");



		std::string line;

		while (getline(felements, line)) {

			barreja barrejaInsert;
			std::pair<barreja, std::string> combinacioInsert;

			for (auto it = line.begin(); it < line.end(); it++) {
				if (*it == ' ')
					line.erase(*it,1);
			}

			size_t pos1 = line.find("=");
			size_t pos2 = line.find("+");

			combinacioInsert.second = line.substr(0,pos1);
					

			barrejaInsert.first = line.substr(pos1, pos2);
			barrejaInsert.second = line.substr(pos2, *line.end());

			combinacioInsert.first = barrejaInsert;

			combinations.insert(combinacioInsert);

		}




	}





};