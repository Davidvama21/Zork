#pragma once

#include <vector>
#include <string>
#include <list>

#include "Entity.h"
#include "Room.h"
#include "Player.h"

using namespace std;

class World
{


public:

	World();
	~World();

	// ejecuta un comando en función de las palabras pasadas, y se retorna si se debe continuar el juego
	bool parseCommand(const vector<string>& words);

private:

	list<Entity*> entities; // Para seguir entidades del juego y borrarlas cuando acabemos; creo que podríamos usar una pila...
	Player* player;
};

