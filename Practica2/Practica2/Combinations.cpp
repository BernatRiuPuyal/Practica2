#include "Combinations.h"





void Combinations::spaceDeleter(std::string stringi)
{
	// canviar el temita amb les funcions de std::string

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


Combinations::Combinations(int i) {
	std::ifstream felements("elements.dat");



	std::string line;

	while (getline(felements, line)) {

		barreja barrejaInsert;
		std::pair<barreja, std::string> combinacioInsert;


		size_t pos1 = line.find("=");
		size_t pos2 = line.find("+");

		combinacioInsert.second = line.substr(0, pos1);


		barrejaInsert.first = line.substr(pos1, pos2);
		barrejaInsert.second = line.substr(pos2, *line.end());


		spaceDeleter(barrejaInsert.first);
		spaceDeleter(barrejaInsert.second);
		spaceDeleter(combinacioInsert.second);



		combinacioInsert.first = barrejaInsert;

		combis.insert(combinacioInsert);

	}
}