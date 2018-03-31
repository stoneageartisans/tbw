#include "database.h"

Database::Database()
{
    initialize();
}

Database::~Database()
{
    // TODO
}

std::map<int, Entity*>* Database::getEntities()
{    
    std::map<int, Entity*>* entities = new std::map<int, Entity*>();
    
    int id = ENTITY_ID_NONE;
    std::string name("NONE");
    float x = 0.f;
    float y = 0.f;
    float z = 0.f;
        
    std::ifstream file(TABLE_ENTITIES);
    
    if(file.is_open())
    {
        std::cout << "SUCCESS: Opened file " << TABLE_ENTITIES << std::endl;
        while(file >> id >> name >> x >> y >> z)
        {
            entities->insert(std::pair<int, Entity*>(id, new Entity(id, new Coordinates(x, y, z), name.c_str())));
        }
        
        std::cout << "SUCCESS: Processed file " << TABLE_ENTITIES << std::endl;
        file.close();
        std::cout << "SUCCESS: Closed file " << TABLE_ENTITIES << std::endl;
    }
    else
    {
        std::cout << "ERROR: Unable to open " << TABLE_ENTITIES << std::endl;
    }
    
    std::cout << std::endl;
    
    return entities;
}

void Database::initialize()
{
    // TODO
}