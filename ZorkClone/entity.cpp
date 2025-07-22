#include "entity.h"


Entity::Entity (string name, string description) {

	type = ENTITY;

	this->name = name;
	this->description = description;
}

string Entity:: getname() {

	return name;
}

string Entity::getdescription() {
	
	return description;
}