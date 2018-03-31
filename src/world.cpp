#include <map>

#include "world.h"

World::World()
{
    initialize(NULL);
}

World::World(std::map<int,Entity*>* ENTITIES)
{
    initialize(ENTITIES);
}

World::~World()
{
    delete entities;
}

void World::addEntity(const char* NAME)
{
    entities->insert(std::pair<int, Entity*>(nextEntityId, new Entity(nextEntityId, NAME)));
    nextEntityId ++;
}

void World::addEntity(Entity* ENTITY)
{
    entities->insert(std::pair<int, Entity*>(nextEntityId, ENTITY));
    nextEntityId ++;
}

std::map<int, Entity*>* World::getEntities()
{
    return entities;
}

Entity* World::getEntity(int ID)
{
    try
    {
        return entities->at(ID);
    }
    catch(const std::out_of_range& EXCEPTION)
    {
        return NULL;
    }
}

int World::getTotalEntities()
{
    return nextEntityId;
}

void World::initialize(std::map<int, Entity*>* ENTITIES)
{
    entities = new std::map<int, Entity*>();
    nextEntityId = 0;
    
    if(ENTITIES != NULL)
    {
        entities = ENTITIES;
        nextEntityId = ENTITIES->size();
    }
}