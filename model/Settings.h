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

    /**
    * Creates a new settings object
    * @precondition none
    * @postcondition a new settings object is created
    */
    Settings();

    /**
    * Creates a new settings object wit the specified parameters
    * @param timerCount the count of the timer
    * @param buttonCount the count of the buttons
    * @precondition none
    * @postcondition a new settings object is created
    */
    Settings(const int timerCount, const int buttonCount);

    /**
    * Destructs the settings object
    */
    virtual ~Settings();

    /**
    * Gets the timer count
    * @precondition none
    * @return the timer count
    */
    int getTimerCount();

    /**
    * Gets the button count
    * @precondition none
    * @return the button count
    */
    int getButtonCount();

    /**
    * sets the timer count
    * @param timerCount the count of the timer
    * @precondition none
    * @postcondition the timer count is set
    */
    void setTimerCount(const int timerCount);

    /**
    * sets the button count
    * @param buttonCount the count of the buttons
    * @precondition none
    * @postcondition the button count is set
    */
    void setButtonCount(const int buttonCount);


};

}

#endif // SETTINGS_H
