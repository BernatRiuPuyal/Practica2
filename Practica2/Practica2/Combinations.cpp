// rebuda i guardatge de les possibles combinacions
/*
#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>




class Combinations {

	typedef std::pair<std::string, std::string> barreja;


	struct barrejaHash {

		size_t operator()(const barreja &c) {

			return ((std::hash<std::string>()(c.first) ^ (std::hash<std::string>()(c.second) << 1)) >> 1);

		}

		};
	
	void spaceDeleter(std::string stringi) {// canviar el temita amb les funcions de std::string

		auto it = stringi.begin();

		while (*it == ' ') {
			stringi.erase(it);
			it++;
		}
		auto rit = stringi.end()--;

		while (*rit == ' ') {
			stringi.erase(rit);
			rit--;
		}
	}



	std::unordered_map < barreja, std::string,barrejaHash>combinations;



	Combinations() {

		std::ifstream felements("elements.dat");



		std::string line;

		while (getline(felements, line)) {

			barreja barrejaInsert;
			std::pair<barreja, std::string> combinacioInsert;

			
			size_t pos1 = line.find("=");
			size_t pos2 = line.find("+");

			combinacioInsert.second = line.substr(0,pos1);
					

			barrejaInsert.first = line.substr(pos1, pos2);
			barrejaInsert.second = line.substr(pos2, *line.end());

			
			spaceDeleter(barrejaInsert.first);
			spaceDeleter(barrejaInsert.second);
			spaceDeleter(combinacioInsert.second);
			


			combinacioInsert.first = barrejaInsert;

			combinations.insert(combinacioInsert);

		}




	}





};*/