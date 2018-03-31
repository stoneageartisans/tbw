#include "apptime.h"

AppTime::AppTime()
{
    initialize(0, 0, 0);
}

AppTime::AppTime(int SECOND, int MINUTE, int HOUR)
{
    initialize(SECOND, MINUTE, HOUR);
}

AppTime::~AppTime()
{
    // TODO
}

void AppTime::advanceTime(int UNIT_OF_TIME, int AMOUNT)
{
    switch(UNIT_OF_TIME)
    {
        case UNIT_SECONDS:
            second = second + AMOUNT;
            update();
            break;
        case UNIT_MINUTES:
            minute = minute + AMOUNT;
            update();
            break;
        case UNIT_HOURS:
            hour = hour + AMOUNT;
            update();
            break;
        default:
            break;
    }
}

bool AppTime::getIsNewDay()
{
    return isNewDay;
}

int AppTime::getHour()
{
    return hour;
}

int AppTime::getMinute()
{
    return minute;
}

int AppTime::getSecond()
{
    return second;
}

void AppTime::initialize(int SECOND, int MINUTE, int HOUR)
{
    isNewDay = false;
    second = SECOND;
    minute = MINUTE;
    hour = HOUR;
}

void AppTime::setIsNewDay(bool VALUE)
{
    isNewDay = VALUE;
}

void AppTime::update()
{
    // Second (0 to 59)
    if(second >= SECONDS_IN_MINUTE)
    {
        minute ++;
        second = second - SECONDS_IN_MINUTE;
    }
    
    // Minute
    if(minute >= MINUTES_IN_HOUR)
    {
        hour ++;
        minute = minute - SECONDS_IN_MINUTE;
    }
    
    // Hour
    if(hour >= HOURS_IN_DAY)
    {
        isNewDay = true;
        hour = hour - HOURS_IN_DAY;
    }
}
