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

// Añade una entidad a la lista de elementos que contiene este objeto
void Entity::addElement(Entity * entity)
{
	contents.push_back (entity);
}
