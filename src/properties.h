#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <cstdlib>

// Keys
#define KEY_AMOUNT       0
#define KEY_UNIT_OF_DATE 1
#define KEY_UNIT_OF_TIME 2
#define TOTAL_KEYS       3

class Properties
{
public:
    Properties();
    virtual ~Properties();
    void clear();
    int getValue(int KEY);
    int getSize();
    void setProperty(int KEY, int VALUE);
    
private:
    void initialize();
    int values[TOTAL_KEYS];
    int size;
};

#endif /* PROPERTIES_H */

