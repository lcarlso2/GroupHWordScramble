#ifndef SETTINGS_H
#define SETTINGS_H

namespace model
{

class Settings
{
private:
    int timerCount;

    int buttonCount;

public:

    Settings();

    Settings(const int timerCount, const int buttonCount);

    virtual ~Settings();

    int getTimerCount();

    int getButtonCount();

    void setTimerCount(const int timerCount);

    void setButtonCount(const int buttonCount);


};

}

#endif // SETTINGS_H
