#ifndef ENTITY_H
#define ENTITY_H

#include "coordinates.h"

#include <string>

#define ENTITY_ID_NONE -1

class Entity
{
public:
    Entity(int ID);
    Entity(int ID, Coordinates* COORDINATES);
    Entity(int ID, const char* NAME);    
    Entity(int ID, Coordinates* COORDINATES, const char* NAME);
    virtual ~Entity();
    Coordinates* getCoordinates();
    int getId();
    std::string* getName();
    
private:
    void initialize(int ID, Coordinates* COORDINATES, const char* NAME);
    Coordinates* coordinates;
    int id;
    std::string* name;
};

#endif /* ENTITY_H */
