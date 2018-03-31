#include "entity.h"

Entity::Entity(int ID)
{
    initialize(ID, new Coordinates(), "NONE");
}

Entity::Entity(int ID, Coordinates* COORDINATES)
{
    initialize(ID, COORDINATES, "NONE");
}

Entity::Entity(int ID, const char* NAME)
{
    initialize(ID, new Coordinates(), NAME);
}

Entity::Entity(int ID, Coordinates* COORDINATES, const char* NAME)
{
    initialize(ID, COORDINATES, NAME);
}

Entity::~Entity()
{
    delete coordinates;
}

Coordinates* Entity::getCoordinates()
{
    return coordinates;
}

int Entity::getId()
{
    return id;
}

std::string* Entity::getName()
{
    return name;
}

void Entity::initialize(int ID, Coordinates* COORDINATES, const char* NAME)
{
    id = ID;
    coordinates = COORDINATES;
    name = new std::string(NAME);
}
