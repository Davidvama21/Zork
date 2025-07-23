#include "world.h"
#include <iostream>

#include "item.h"
#include "exit.h"

World::World() {
	
	// Aquí declararemos todos los objetos que habrá en el juego

	// Salas //
	Room* hall = new Room("Hall", "You are standing on a long, red carpet.");
	entities.push_back(hall);

	Room* entrance = new Room("Entrance", "You are standing in front of a big house.");
	entities.push_back(entrance);

	Room* living_room = new Room("Living room", "The red carpet ends here.");
	entities.push_back(living_room);

	// Salidas //
	Exit* exit1 = new Exit("West", "East", entrance, hall, "door");
	entrance->addElement(exit1); hall->addElement(exit1); // NECESARIO PARA RECONOCER VÍAS POR LAS QUE SE PUEDE IR
	entities.push_back(exit1);

	Exit* exit2 = new Exit("West", "East", hall, living_room, "path");
	hall->addElement(exit2); living_room->addElement(exit2);
	entities.push_back(exit2);

	// Items //
	Item* letter = new Item("Letter", "Someone left this on the ground.", true, "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor."); // true porque se puede coger
	hall->addElement(letter); // para que se vean en la sala
	entities.push_back(letter);

	Item* box = new Item("Box", "A box made of cardboard", false);
	hall->addElement(box);
	entities.push_back(box);

	// Jugador //
	player = new Player("David", "Just an explorer.", hall);
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

		break;
	

	case 2: // Comando de 2 parámetros

		
		if (words[0] == "pick" or words[0] == "take") {

			pair < list<Entity*>::iterator, list<Entity*>* > item_position = (player->getRoom())->getItemPos (words[1]); // Buscamos item con nombre dado en el comando
			
			if (item_position.second == NULL) // => no encontrado
				cout << "The object is not in the room." << endl;

			else {
				Item* item = (Item*)(*item_position.first); // extraer item

				if (item->isPickable()) {
					(*item_position.second).erase (item_position.first); // Borramos del lugar donde estaba

					player->addElement (item); // y añadimos al inventario
					cout << "You picked up the " << item->getName() << '.' << endl;

				}else
					cout << "You can't pick this object."  << endl;
			}


		}else if (words[0] == "drop") {
			
			Item* item = (Item*) player->getAndRemoveItem (words[1]);

			if (item == NULL)
				cout << "There is no " << words[1] << " in your inventory." << endl;
			else
				cout << "You dropped the " << item->getName() << '.' << endl; // mostramos el nombre con getName() por si en el futuro los comandos son case-insensitive
		
		
		}else if (words[0] == "go") {

			Room* currentRoom = player->getRoom();
			Room* nextRoom;

			if (words[1] == "N" or words[1] == "North")
				nextRoom = currentRoom->getNextRoom("North");

			else if (words[1] == "S" or words[1] == "South")
				nextRoom = currentRoom->getNextRoom("South");

			else if (words[1] == "W" or words[1] == "West")
				nextRoom = currentRoom->getNextRoom("West");

			else if (words[1] == "E" or words[1] == "East")
				nextRoom = currentRoom->getNextRoom("East");

			else nextRoom = currentRoom; // marcador para el caso de dirección inválida


			if (nextRoom == NULL)
				cout << "There is nothing there." << endl;

			else if (nextRoom == currentRoom)
				cout << "Invalid direction." << endl;

			else { // caso de sala encontrada
				player->changeRoom(nextRoom);
				nextRoom->look(); // Para hacer preview de nueva sala
			}
		}

	}

	return true; // Nada indica que haya que salir del juego
}
