#include "properties.h"

Properties::Properties()
{
    initialize();
}

Properties::~Properties()
{
    // TODO
}

void Properties::clear()
{
    for(int i = 0; i < size; i ++)
    {
        values[i] = 0;
    }
}

int Properties::getValue(int KEY)
{
    return values[KEY];
}

int Properties::getSize()
{
    return size;
}

void Properties::initialize()
{
    size = TOTAL_KEYS;
    
    for(int i = 0; i < size; i ++)
    {
        values[i] = 0;
    }
}

void Properties::setProperty(int KEY, int VALUE)
{
    values[KEY] = VALUE;
}
