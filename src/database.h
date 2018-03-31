#ifndef DATABASE_H
#define DATABASE_H

#include "entity.h"

#include <fstream>
#include <iostream>
#include <map>
#include <string>

#define TABLE_ENTITIES "entities.txt"

class Database
{
public:
    Database();
    virtual ~Database();
    std::map<int, Entity*>* getEntities();
    
private:
    void initialize();
};

#endif /* DATABASE_H */

