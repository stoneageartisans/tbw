#include "event.h"

Event::Event()
{
    initialize();
}

Event::~Event()
{
    delete properties;
}

void Event::clear()
{
    id = EVENT_NONE;
    
    properties->clear();
}

int Event::getId()
{
    return id;
}

Properties* Event::getProperties()
{
    return properties;
}

void Event::initialize()
{
    id = EVENT_NONE;
    
    properties = new Properties();
}

void Event::setId(int ID)
{
    id = ID;
}
