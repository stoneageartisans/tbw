#include "ui.h"

Ui::Ui(AppDate* DATE, AppTime* TIME, World* WORLD, Event* EVENT)
{
    initialize(DATE, TIME, WORLD, EVENT);
}

Ui::~Ui()
{
    /* Unbind these with the parent Applications */
    date = NULL;
    time = NULL;
    world = NULL;
    event = NULL;
    
    delete date;
    delete time;
    delete world;
    delete event;
}

void Ui::advanceDate()
{
    event->setId(EVENT_ADVANCE_DATE);
    event->getProperties()->setProperty(KEY_UNIT_OF_DATE, dateUnit);
    event->getProperties()->setProperty(KEY_AMOUNT, dateAmount);
}

void Ui::advanceTime()
{
    event->setId(EVENT_ADVANCE_TIME);
    event->getProperties()->setProperty(KEY_UNIT_OF_TIME, timeUnit);
    event->getProperties()->setProperty(KEY_AMOUNT, timeAmount);
}

Event* Ui::getEvent()
{
    return event;
}

void Ui::initialize(AppDate* DATE, AppTime* TIME, World* WORLD, Event* EVENT)
{
    choice = '0';
    input = 0;
    currentEntityId = ENTITY_ID_NONE;
    currentScreen = SCREEN_MAIN_MENU;
    date = DATE;
    dateAmount = 0;
    dateUnit = 0;
    event = EVENT;
    time = TIME;
    timeAmount = 0;
    timeUnit = 0;
    world = WORLD;
}

void Ui::listEntities()
{
    std::cout << std::endl;
    std::cout << "Entities:" << std::endl;
    std::cout << std::endl;
    std::cout << "  -------------------------" << std::endl;
    int totalEntities = world->getTotalEntities();
    for(int i = 0; i < totalEntities; i ++)
    {
        Entity* entity = world->getEntity(i);
        Coordinates* coordinates = entity->getCoordinates();
        std::cout << "  " << i << "    ";
        std::cout << entity->getName()->c_str() << " (";        
        std::cout << coordinates->getX() << ", ";
        std::cout << coordinates->getY() << ", ";
        std::cout << coordinates->getZ() << ")";
        std::cout << std::endl;
    }
    std::cout << "  -------------------------" << std::endl;
}

void Ui::processAmountChange()
{
    input = 0;
    
    std::cin >> input;
    
    switch(currentScreen)
    {
        case SCREEN_DATE_MENU:
            if(input > 0)
            {
                dateAmount = input;
            }
            else
            {
                dateAmount = 0;
            }
            break;
        case SCREEN_TIME_MENU:
            if(input > 0)
            {
                timeAmount = input;
            }
            else
            {
                timeAmount = 0;
            }
            break;
        default:
            break;
    }
    
    std::cout << std::endl;
}

void Ui::processChoice()
{
    choice = '0';
    
    std::cin >> choice;
    
    switch(currentScreen)
    {
        case SCREEN_MAIN_MENU:
            switch(choice)
            {
                case '1': // Start
                    event->setId(EVENT_START);
                    currentScreen = SCREEN_APP_MENU;
                    break;
                case '2': // Exit app
                    currentScreen = SCREEN_EXIT_MENU;
                    break;
                default:
                    break;
            }
            break;
        case SCREEN_APP_MENU:
            switch(choice)
            {
                case '1': // Date Menu
                    currentScreen = SCREEN_DATE_MENU;
                    break;
                case '2': // Time Menu
                    currentScreen = SCREEN_TIME_MENU;
                    break;
                case '3': // World Menu
                    currentScreen = SCREEN_WORLD_MENU;
                    break;
                case '4': // Exit to Main Menu
                    currentScreen = SCREEN_MAIN_MENU;
                    break;
                default:
                    break;
            }
            break;
        case SCREEN_DATE_MENU:
            switch(choice)
            {
                case '1': // Show Date
                    showDate();
                    break;
                case '2': // Set Amount
                    setAmount();
                    break;
                case '3': // Set Unit
                    setUnit();
                    break;
                case '4': // Advance Date
                    advanceDate();
                    break;
                case '5': // Go Back
                    currentScreen = SCREEN_APP_MENU;
                    break;
                default:
                    break;
            }
            break;
        case SCREEN_TIME_MENU:
            switch(choice)
            {
                case '1': // Show Time
                    showTime();
                    break;
                case '2': // Set Amount
                    setAmount();
                    break;
                case '3': // Set Unit
                    setUnit();
                    break;
                case '4': // Advance Time
                    advanceTime();
                    break;
                case '5': // Go Back
                    currentScreen = SCREEN_APP_MENU;
                    break;
                default:
                    break;
            }
            break;
        case SCREEN_WORLD_MENU:
            switch(choice)
            {
                case '1': // List Entities
                    listEntities();
                    break;
                case '2': // Edit Entity
                    currentScreen = SCREEN_ENTITY_MENU;
                    break;
                case '3': // Go Back
                    currentScreen = SCREEN_APP_MENU;
                    break;
                default:
                    break;
            }
            break;
        case SCREEN_ENTITY_MENU:
            switch(choice)
            {
                case '1': // Set Entity
                    setEntity();
                    break;
                case '2': // Set Name
                    // TODO;
                    break;
                case '3': // Set Coordinates
                    // TODO;
                    break;
                case '4': // Go Back
                    currentScreen = SCREEN_WORLD_MENU;
                    break;
                default:
                    break;
            }
            break;
        case SCREEN_EXIT_MENU:
            switch(choice)
            {
                case '1': // Go Back
                    currentScreen = SCREEN_MAIN_MENU;
                    break;
                case '2': // Confirm Exit
                    event->setId(EVENT_EXIT);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    
    std::cout << std::endl;
}

void Ui::processUnitChange()
{
    choice = '0';
    
    std::cin >> choice;
    
    switch(currentScreen)
    {
        case SCREEN_DATE_MENU:            
            dateUnit = std::atoi(&choice);
            if(dateUnit > TOTAL_DATE_UNITS)
            {
                dateUnit = 0;
            }
            break;
        case SCREEN_TIME_MENU:
            timeUnit = std::atoi(&choice);
            if(timeUnit > TOTAL_TIME_UNITS)
            {
                timeUnit = 0;
            }
            break;
        default:
            break;
    }
    
    std::cout << std::endl;
}

void Ui::setAmount()
{
    switch(currentScreen)
    {
        case SCREEN_DATE_MENU:
            std::cout << std::endl;
            std::cout << "  Enter new amount [" << dateAmount << "]: ";
            processAmountChange();
            break;
        case SCREEN_TIME_MENU:
            std::cout << std::endl;
            std::cout << "  Enter new amount [" << timeAmount << "]: ";
            processAmountChange();
            break;
        default:
            break;
    }
}

void Ui::setEntity()
{
    input = 0;
    
    std::cout << std::endl;
    if(currentEntityId > ENTITY_ID_NONE)
    {
        std::cout << "  Enter entity id [" << currentEntityId << "]: ";
    }
    else
    {
        std::cout << "  Enter entity id [NONE]: ";
    }
    
    std::cin >> input;
    
    if(world->getEntity(input) != NULL)
    {        
        currentEntityId = input;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "  ERROR: Invalid entity id" << std::endl;
    }
}

void Ui::setUnit()
{
    switch(currentScreen)
    {
        case SCREEN_DATE_MENU:
            std::cout << std::endl;
            for(int unit = 1; unit < TOTAL_DATE_UNITS + 1; unit ++)
            {
                std::cout << "  " << unit << " - " << DATE_UNIT[unit] << std::endl;
            }
            std::cout << "  Enter new unit [" << DATE_UNIT[dateUnit] << "]: ";
            processUnitChange();
            break;
        case SCREEN_TIME_MENU:
            std::cout << std::endl;
            for(int unit = 1; unit < TOTAL_TIME_UNITS + 1; unit ++)
            {
                std::cout << "  " << unit << " - " << TIME_UNIT[unit] << std::endl;
            }
            std::cout << "  Enter new unit [" << DATE_UNIT[timeUnit] << "]: ";
            processUnitChange();
            break;
        default:
            break;
    }
}

void Ui::showDate()
{
    std::cout << std::endl;
    std::cout << "Date: ";
    std::cout << DAY_NAME[date->getDayOfWeek()] << ", ";
    std::cout << MONTH_NAME[date->getMonthOfYear()] << " ";
    std::cout << date->getDayOfMonth() << ", ";
    std::cout << date->getYear() << " [";
    std::cout << SEASON_NAME[date->getSeason()] << "]";
    std::cout << std::endl;
}

void Ui::showMenu()
{
    switch(currentScreen)
    {
        case SCREEN_MAIN_MENU:
            std::cout << "MAIN MENU" << std::endl;
            std::cout << std::endl;
            std::cout << "  1 - Start" << std::endl;
            std::cout << "  2 - Exit App" << std::endl;
            std::cout << std::endl;
            std::cout << "  Enter choice: ";
            break;
        case SCREEN_APP_MENU:
            std::cout << "APP MENU" << std::endl;
            std::cout << std::endl;
            std::cout << "  1 - Date Menu" << std::endl;
            std::cout << "  2 - Time Menu" << std::endl;
            std::cout << "  3 - World Menu" << std::endl;
            std::cout << "  4 - Exit to Main Menu" << std::endl;
            std::cout << std::endl;
            std::cout << "  Enter choice: ";
            break;
        case SCREEN_DATE_MENU:
            std::cout << "DATE MENU" << std::endl;
            std::cout << std::endl;
            std::cout << "  1 - Show Date" << std::endl;
            std::cout << "  2 - Set Amount [" << dateAmount << "]" << std::endl;
            std::cout << "  3 - Set Unit [" << DATE_UNIT[dateUnit] << "]" << std::endl;
            std::cout << "  4 - Advance Date" << std::endl;
            std::cout << "  5 - Go Back" << std::endl;
            std::cout << std::endl;
            std::cout << "  Enter choice: ";
            break;
        case SCREEN_TIME_MENU:
            std::cout << "TIME MENU" << std::endl;
            std::cout << std::endl;
            std::cout << "  1 - Show Time" << std::endl;
            std::cout << "  2 - Set Amount [" << timeAmount << "]" << std::endl;
            std::cout << "  3 - Set Unit [" << TIME_UNIT[timeUnit] << "]" << std::endl;
            std::cout << "  4 - Advance Time" << std::endl;
            std::cout << "  5 - Go Back" << std::endl;
            std::cout << std::endl;
            std::cout << "  Enter choice: ";
            break;
        case SCREEN_WORLD_MENU:
            std::cout << "WORLD MENU" << std::endl;
            std::cout << std::endl;
            std::cout << "  1 - List Entities" << std::endl;
            std::cout << "  2 - Edit entity" << std::endl;
            std::cout << "  3 - Go Back" << std::endl;
            std::cout << std::endl;
            std::cout << "  Enter choice: ";
            break;
        case SCREEN_ENTITY_MENU:
            std::cout << "ENTITY MENU" << std::endl;
            std::cout << std::endl;            
            if(currentEntityId > ENTITY_ID_NONE)
            {
                std::cout << "  1 - Set entity [" << currentEntityId << "]" << std::endl;
                std::cout << "  2 - Set name [" << world->getEntity(currentEntityId)->getName()->c_str() << "]" << std::endl;
                std::cout << "  3 - Set coordinates [" << world->getEntity(currentEntityId)->getCoordinates()->getX() << ", ";
                std::cout << world->getEntity(currentEntityId)->getCoordinates()->getY() << ", ";
                std::cout << world->getEntity(currentEntityId)->getCoordinates()->getZ() << "]" << std::endl;
            }
            else
            {
                std::cout << "  1 - Set entity [NONE]" << std::endl;
                std::cout << "  2 - Set name [NONE]" << std::endl;
                std::cout << "  3 - Set coordinates [NONE]" << std::endl;
            }            
            std::cout << "  4 - Go Back" << std::endl;
            std::cout << std::endl;
            std::cout << "  Enter choice: ";
            break;
        case SCREEN_EXIT_MENU:
            std::cout << "EXIT MENU" << std::endl;
            std::cout << std::endl;
            std::cout << "  1 - Go Back" << std::endl;
            std::cout << "  2 - Confirm Exit" << std::endl;
            std::cout << std::endl;
            std::cout << "  Enter choice: ";
        default:            
            break;
    }    
}

void Ui::showTime()
{
    std::cout << std::endl;
    std::cout << "Time: ";
    
    if(time->getHour() < 10)
    {
        std::cout << "0";
    }
    std::cout << time->getHour() << ":";
    
    if(time->getMinute() < 10)
    {
        std::cout << "0";
    }
    std::cout << time->getMinute() << ":";
    
    if(time->getSecond() < 10)
    {
        std::cout << "0";
    }
    std::cout << time->getSecond() << std::endl;
}

void Ui::update()
{
    showMenu();
    processChoice();
}
