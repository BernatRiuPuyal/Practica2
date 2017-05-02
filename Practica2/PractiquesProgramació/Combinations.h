// rebuda i guardatge de les possibles combinacions

#pragma once

#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>


typedef std::pair<std::string, std::string> barreja;

class Combinations {

	struct barrejaHash {

		size_t operator()(const barreja &c) const {

			return ((std::hash<std::string>()(c.first) ^ (std::hash<std::string>()(c.second) << 1)) >> 1);

		}

	};

	public:
		std::unordered_map < barreja, std::string, barrejaHash> combinations;

		Combinations();

		void print();

		bool loadCheck();

	private:
		void spaceDeleter(std::string &stringi); 

};

