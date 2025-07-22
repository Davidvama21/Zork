#include "world.h"
#include <iostream>

World::World() {
	
	// Aquí declararemos todos los objetos que habrá en el juego

	// Salas //
	Room* hall = new Room("Hall", "You are standing on a long, red carpet.");
	entities.push_back(hall);

	// Jugador //
	player = new Player("David", "Just an explorer.", hall); // Creature (string name, string description, Room* location);
}

World::~World()
{
	// Borramos todas las entidades de la memoria
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) 
		delete *it;

	entities.clear();
}


bool World::parseCommand(const vector<string>& words)
{
	//cout << "-Tamano: " << words.size() << endl;


	switch (words.size()) {

	case 1: // Comando de 1 parámetro

		if (words[0] == "quit")
			return false;

		if (words[0] == "look"){
			Room* currentRoom = player->getRoom();
			currentRoom->look();
		}
			
	}

	return true; // Nada indica que haya que salir del juego
}
