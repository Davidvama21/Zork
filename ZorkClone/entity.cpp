#include <iostream>

#include "entity.h"


Entity::Entity (string name, string description) {

	type = ENTITY;

	this->name = name;
	this->description = description;
}

string Entity:: getName() {

	return name;
}

string Entity::getDescription() {
	
	return description;
}

EntityType Entity::getType()
{
	return type;
}

// Devuelve un par con el iterador apuntando al entity item con el nombre dado, si es del contenido, y un puntero a la lista donde lo encontraste por si lo quieres borrar;
// en caso de que no esté el iterador no está definido y el puntero = null
pair < list<Entity*>::iterator, list<Entity*>* > Entity::getItemPos(string name) {

	for (list<Entity*>::iterator it = contents.begin(); it != contents.end(); ++it) {
		Entity* currentEntity = *it;
		if (currentEntity->getType() == ITEM) {

			if (currentEntity->getName() == name) {
				return make_pair (it, &contents); 

			}else { // Rebuscamos DENTRO de este ITEM para ver si está el que buscamos

				pair < list<Entity*>::iterator, list<Entity*>* > search_result = currentEntity->getItemPos(name);
				if (search_result.second != NULL) return search_result;
			}
		}
	}

	return pair < list<Entity*>::iterator, list<Entity*>* > (contents.end(), NULL); // si no lo encuentras
}

// Devuelve el puntero al entity item con el nombre dado del contenido, si existe; de lo contrario retorna null
// (OJO que ésto solo rebusca dentro de items si está, NO en otro tipo de entidades)
Entity * Entity::getItem(string name){

	for (list<Entity*>::iterator it = contents.begin(); it != contents.end(); ++it) {
		Entity* currentEntity = *it;
		if (currentEntity->getType() == ITEM){

			if (currentEntity->getName() == name) return currentEntity;

			else { // Rebuscamos DENTRO de este ITEM para ver si está el que buscamos

				Entity* search_result = currentEntity->getItem(name);
				if (search_result != NULL) return search_result;
			}
		}
	}

	return NULL; // si no lo encuentras
}

// Lo mismo, pero si lo encuentra además lo borra del contenido
Entity * Entity::getAndRemoveItem(string name)
{
	for (list<Entity*>::iterator it = contents.begin(); it != contents.end(); ++it) {
		Entity* currentEntity = *it;
		if (currentEntity->getType() == ITEM) {

			if (currentEntity->getName() == name) {
				contents.erase(it); // Borramos del conjunto antes de retornarlo
				return currentEntity; 
			
			}else { // Rebuscamos DENTRO de este ITEM para ver si está el que buscamos

				Entity* search_result = currentEntity->getItem(name);
				if (search_result != NULL) return search_result;
			}
		}
	}

	return NULL; // si no lo encuentras
}



void Entity::listElements()
{
	if (contents.empty())
		cout << "There are no elements to list." << endl;

	else {

		cout << "Total elements: " << contents.size() << endl;
		for (list<Entity*>::iterator it = contents.begin(); it != contents.end(); ++it) {

			cout << (*it)->getName() << endl;
		}
	}
}

// Añade una entidad a la lista de elementos que contiene este objeto
void Entity::addElement(Entity * entity)
{
	contents.push_back (entity);
}
