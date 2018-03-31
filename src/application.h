#ifndef APPLICATION_H
#define APPLICATION_H

#include "apptime.h"
#include "appdate.h"
#include "database.h"
#include "event.h"
#include "ui.h"
#include "world.h"

#include <cstdlib>
#include <fstream>

#define LOG_TEST_DATES 1

class Application
{
public:
    Application();
    virtual ~Application();
    void run();
    
private:
    void clearEvent();
    void exit();
    void initialize();
    void log(int LOG_TYPE);
    void processEvent();
    void update();
    bool running;
    Database* database;
    AppDate* date;
    Event* event;
    AppTime* time;
    Ui* ui;
    World* world;
};

#endif /* APPLICATION_H */
