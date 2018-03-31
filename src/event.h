#ifndef EVENT_H
#define EVENT_H

#include "properties.h"

// Event IDs
#define EVENT_NONE          0
#define EVENT_START        10
#define EVENT_ADVANCE_DATE 20
#define EVENT_ADVANCE_TIME 21
#define EVENT_EXIT         99

class Event
{
public:
    Event();
    virtual ~Event();
    void clear();
    int getId();
    Properties* getProperties();
    void setId(int ID);
    
private:
    void initialize();
    int id;
    Properties* properties;
};

#endif /* EVENT_H */
