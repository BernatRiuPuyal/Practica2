#include "Combinations.h"


void Combinations::spaceDeleter(std::string stringi)
{
	size_t start = stringi.find_last_not_of(" ");

	stringi = stringi.substr(start, start - stringi.find_first_not_of(" ")+ 1);

}


Combinations::Combinations() {
	std::ifstream felements("elements.dat");

	std::string line;

	while (getline(felements, line)) {

		barreja barrejaInsert;
		std::pair<barreja, std::string> combinacioInsert;


		size_t pos1 = line.find("=");
		size_t pos2 = line.find("+");

		combinacioInsert.second = line.substr(0, pos1);


		barrejaInsert.first = line.substr(pos1 + 1, pos2 - (pos1 + 1));
		barrejaInsert.second = line.substr(pos2 + 1, std::string::npos);


		spaceDeleter(barrejaInsert.first);
		spaceDeleter(barrejaInsert.second);
		spaceDeleter(combinacioInsert.second);



		combinacioInsert.first = barrejaInsert;

		combinations.insert(combinacioInsert);

	}
}

void Combinations::print()
{

	for (auto it = combinations.begin(); it != combinations.end(); it++) {

		std::cout << (*it).first.first << " + " << (*it).first.second << " = " << (*it).second << std::endl;

	}

}
