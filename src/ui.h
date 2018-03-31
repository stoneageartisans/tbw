#ifndef UI_H
#define UI_H

#include "appdate.h"
#include "apptime.h"
#include "constants.h"
#include "event.h"
#include "world.h"

#include <iostream>

// Screens
#define SCREEN_MAIN_MENU    1
#define SCREEN_APP_MENU    20
#define SCREEN_DATE_MENU   21
#define SCREEN_TIME_MENU   22
#define SCREEN_WORLD_MENU  30
#define SCREEN_ENTITY_MENU 31
#define SCREEN_EXIT_MENU   99

class Ui
{
public:
    Ui(AppDate* DATE, AppTime* TIME, World* WORLD, Event* EVENT);
    virtual ~Ui();
    Event* getEvent();
    void update();
    
private:
    void advanceDate();
    void advanceTime();    
    void initialize(AppDate* DATE, AppTime* TIME, World* WORLD, Event* EVENT);
    void listEntities();
    void processAmountChange();
    void processUnitChange();
    void processChoice();    
    void setAmount();
    void setEntity();
    void setUnit();
    void showDate();
    void showMenu();
    void showTime();
    char choice;
    int currentEntityId;
    int currentScreen;
    AppDate* date;
    int dateAmount;
    int dateUnit;
    int input;
    AppTime* time;
    int timeAmount;
    int timeUnit;
    Event* event;
    World* world;
};

#endif /* UI_H */
