#ifndef WORLD_H
#define WORLD_H

#include "entity.h"

#include <map>
#include <stdexcept>

class World
{
public:
    World();
    World(std::map<int, Entity*>* ENTITIES);
    virtual ~World();
    void addEntity(const char* NAME);
    void addEntity(Entity* ENTITY);
    Entity* getEntity(int ID);
    int getTotalEntities();
    std::map<int, Entity*>* getEntities();
    
private:    
    void initialize(std::map<int, Entity*>* ENTITIES);
    int nextEntityId;
    std::map<int, Entity*>* entities;
};

#endif /* WORLD_H */
