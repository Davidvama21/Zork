#include "world.h"
#include <iostream>

bool World::parseCommand(const vector<string>& words)
{
	//cout << "-Tamano: " << words.size() << endl;


	switch (words.size()) {

	case 1: // Comando de 1 parámetro

		if (words[0] == "quit")
			return false;

	}

	return true; // Nada indica que haya que salir del juego
}
