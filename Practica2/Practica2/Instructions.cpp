#include "Instructions.h"
#include <fstream>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <cstdlib>

//////// FUNCIONS DE LES INSTRUCCIONS DEL JUGADOR

void add(std::vector<std::string> &llista, int nombre) {
	llista.push_back(llista[nombre]);
}

void addBasics(std::vector<std::string> &llista) {  //segur que es pot fer en una linea amb el insert o algo casun l'os predrer
	llista.push_back("Air");
	llista.push_back("Earth");
	llista.push_back("Fire");
	llista.push_back("Water");
}

void deleteFunct(std::vector<std::string> &llista, int nombre) {
	if(llista.size()>=nombre)
	llista.erase(llista.begin() + nombre);
}

void info(std::vector<std::string> llista, int nombre) { //capselera <windows.h>
	std::string wikiLink = "https://en.wikipedia.org/wiki/";
	wikiLink.append(llista[nombre]);

	
    ShellExecuteA(nullptr, "open", wikiLink.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

void sort(std::vector<std::string> &llista) {
	std::string swapper;
	bool keepSort = true;

	for (int i = 0; (i < llista.size()) && keepSort; i++) {

		keepSort = false;

		for (int j = 0; j < llista.size() - 1; j++) {
			if (llista[j + 1] > llista[j]) {

				swapper = llista[j];
				llista[j] = llista[j + 1];
				llista[j + 1] = swapper;

				keepSort = true;
			}
		}
	}
}

void clean(std::vector<std::string> &llista) {
	for (int i = 0; i < llista.size(); i++) {
		for (int j = 0; j < llista.size(); j++) {
			if (llista[i] == llista[j] && i != j) {
				llista.erase(llista.begin() + j);
			}
		}
	}
}

void help() {
	std::cout << "==============" << std::endl;
	std::cout << "== TUTORIAL ==" << std::endl;
	std::cout << "==============" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Write:" << std::endl;
	std::cout << "  'add': followed by the number of an element to copy it in your inventory." << std::endl;
	std::cout << "  'add basics': add to your inventory fire, water, earth and wind." << std::endl;
	std::cout << "  'delete': followed by the number of an element to delete it from your inventory." << std::endl;
	std::cout << "  'info': followed by the number of an element to get info about it." << std::endl;
	std::cout << "  'sort': sort your inventory by alphabetical order." << std::endl;
	std::cout << "  'clean': delet all the repetead elements of your inventory." << std::endl;
	std::cout << std::endl;

	std::cout << "Press SPACE to continue.";
}

///////