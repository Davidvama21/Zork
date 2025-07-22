#pragma once

#include <vector>
#include <string>

using namespace std;

class World
{


public:

	// ejecuta un comando en función de las palabras pasadas, y se retorna si se debe continuar el juego
	bool parseCommand(const vector<string>& words);

private:

	//list<Entity*> entities; <- creo que probaremos de usar colas
	//Player* player;
};

