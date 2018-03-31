#include "application.h"

Application::Application()
{
    initialize();
}

Application::~Application()
{
    delete ui;
    delete date;
    delete event;
    delete time;    
    delete world;
    delete database;
}

void Application::clearEvent()
{
    event->clear();
}

void Application::exit()
{
    running = false;
}

void Application::initialize()
{
    database = new Database();
    date = new AppDate();    
    time = new AppTime();    
    world = new World(database->getEntities());
    event = new Event();
    ui = new Ui(date, time, world, event);
    running = true;
    //log(LOG_TEST_DATES);
}

void Application::log(int LOG_TYPE)
{
    std::ofstream outputFile = std::ofstream("tbw_log.txt");
    
    switch(LOG_TYPE)
    {
        case LOG_TEST_DATES: // temporary test
            for(int i = 1; i < 1500; i++)
            {                
                outputFile << i << " > ";
                outputFile << "year: " << date->getYear() << ", ";
                outputFile << "dayOfYear: " << date->getDayOfYear() << ", ";
                outputFile << "dayOfMonth: " << date->getDayOfMonth() << ", ";
                outputFile << "dayOfWeek: " << DAY_NAME[date->getDayOfWeek()] << ", ";
                outputFile << "weekOfYear: " << date->getWeekOfYear() << ", ";
                outputFile << "weekOfMonth: " << date->getWeekOfMonth() << ", ";
                outputFile << "monthOfYear: " << MONTH_NAME[date->getMonthOfYear()] << ", ";
                outputFile << "season: " << SEASON_NAME[date->getSeason()] << ", ";
                outputFile << std::endl;
                date->advanceDate(UNIT_DAYS, 1);
            }
            std::cout << std::endl;
            break;
        default:
            break;
    }
    
    outputFile.close();
}

void Application::processEvent()
{    
    switch(event->getId())
    {
        case EVENT_NONE:
            break;
        case EVENT_START:
            clearEvent();
            break;
        case EVENT_EXIT:
            exit();
            break;
        case EVENT_ADVANCE_DATE:
            date->advanceDate(
                event->getProperties()->getValue(KEY_UNIT_OF_DATE),
                event->getProperties()->getValue(KEY_AMOUNT)                
            );
            clearEvent();
            break;
        case EVENT_ADVANCE_TIME:
            time->advanceTime(
                event->getProperties()->getValue(KEY_UNIT_OF_TIME),
                event->getProperties()->getValue(KEY_AMOUNT)
            );            
            if(time->getIsNewDay() == true)
            {
                event->setId(EVENT_ADVANCE_DATE);
                event->getProperties()->setProperty(KEY_UNIT_OF_DATE, UNIT_DAYS);
                event->getProperties()->setProperty(KEY_AMOUNT, 1);
                time->setIsNewDay(false);
            }
            else
            {
                clearEvent();
            }
            break;
    }
}

void Application::run()
{
    while(running)
    {
        update();
    }
}

void Application::update()
{
    if(event->getId() == EVENT_NONE)
    {
        ui->update();
    }
    
    processEvent();
}
