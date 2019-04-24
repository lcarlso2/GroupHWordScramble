#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "OkCancelWindow.h"
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Window.H>
#include <Fl/fl_draw.H>

#include <string>
using namespace std;

#include "WordScrambleController.h"
using namespace controller;

namespace view
{
const int NUMBER_OF_BUTTONS_FOR_TIMER = 3;
const int NUMBER_OF_BUTTONS_FOR_LETTER_COUNT = 3;
const int OFFSET_TO_SELECTED_TIMER = 1;
const int OFFSET_TO_SELECTED_LETTER_COUNT = 5;

/**
* The settings window that controls selecting the settings of the game
* @author Lucas Carlson and Carson Bedrosian
* @version 4/16/2019
*/
class SettingsWindow : public OkCancelWindow
{

private:
    string* timerLabels[NUMBER_OF_BUTTONS_FOR_TIMER];

    string* letterCountLabels[NUMBER_OF_BUTTONS_FOR_LETTER_COUNT];

    Fl_Output* timerLabel;

    Fl_Output* letterCountLabel;

    Fl_Group* timerRadioGroup;

    Fl_Group* letterRadioGroup;

    Fl_Round_Button* timerRadioGroupButton[NUMBER_OF_BUTTONS_FOR_TIMER];

    Fl_Round_Button* letterRadioGroupButton[NUMBER_OF_BUTTONS_FOR_LETTER_COUNT];

    int selectedTimerCount;

    int selectedButtonCount;

    void createButtonsForTimer();

    void createButtonsForButtonCount();

    static void cbTimerChanged(Fl_Widget* widget, void* data);

    static void cbLetterCountChanged(Fl_Widget* widget, void* data);

    inline void setTimer(const string& value);

    inline void setLetterCount(const string& value);

    void draw();

public:
    /**
    * Creates a new settings window
    * @param timerCount the current timer count
    * @param buttonCount the current button count
    * @precondition none
    * @postcondition a new settings window is created
    */
    SettingsWindow(const int timerCount, const int buttonCount);

    /**
    * Destructs the settings window
    */
    virtual ~SettingsWindow();

    /**
    * Gets the selected timer
    * @precondition none
    * @return the selected timer
    */
        int getSelectedTimerCount();

    /**
    * Gets the selected number of buttons
    * @precondition none
    * @return the selected number of buttons
    */
    int getSelectedButtonCount();

    /**
    * Handles the ok click event
    * @precondition none
    * @postcondition the event is handled
        */
    void okHandler();

    /**
    * Handles the cancel click event
    * @precondition none
    * @postcondition the event is handled
    */
    void cancelHandler();

};

}

#endif // SETTINGSWINDOW_H
