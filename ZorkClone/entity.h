#pragma once

#include <string>
#include <list>
#include <utility>

//#include "item.h"

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE,
	PLAYER
};

class Entity
{
public:
	Entity(string name, string description);
	string getName();
	string getDescription();
	EntityType getType();


	// (OJO, los siguientes getItem solo rebuscan dentro de items por si está, NO en otro tipo de entidades)
	// Devuelve un par con el iterador apuntando al entity item con el nombre dado, si es del contenido, y un puntero a la lista donde lo encontraste por si lo quieres borrar;
	// en caso de que no esté el iterador no está definido y el puntero = null
	pair < list<Entity*>::iterator, list<Entity*>* > getItemPos(string name);

	// Devuelve el puntero al entity item con el nombre dado del contenido, si existe; de lo contrario retorna null
	Entity* getItem(string name);
	// Lo mismo, pero si lo encuentra además lo borra del contenido
	Entity* getAndRemoveItem(string name);
	

	void addElement(Entity* entity);

protected:

	EntityType type;

	string name;
	string description;

	list <Entity*> contents; // Lista para que se respete el orden de elementos al explorarla
};

