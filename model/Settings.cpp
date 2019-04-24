#include "Settings.h"

namespace model
{

Settings::Settings()
{

}

Settings::Settings(const int timerCount, const int buttonCount)
{
    this->timerCount = timerCount;
    this->buttonCount = buttonCount;
}

Settings::~Settings()
{
    //dtor
}

int Settings::getTimerCount()
{
    return this->timerCount;
}

int Settings::getButtonCount()
{
    return this->buttonCount;
}

void Settings::setTimerCount(const int timerCount)
{
    this->timerCount = timerCount;
}

void Settings::setButtonCount(const int buttonCount)
{
    this->buttonCount = buttonCount;
}

}
