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

namespace view
{

class SettingsWindow : public OkCancelWindow
{

private:
    static const int NUMBER_OF_BUTTONS_FOR_TIMER = 3;

    static const int NUMBER_OF_BUTTONS_FOR_LETTER_COUNT = 3;

    string* timerLabels[NUMBER_OF_BUTTONS_FOR_TIMER];

    string* letterCountLabels[NUMBER_OF_BUTTONS_FOR_LETTER_COUNT];

    Fl_Output* timerLabel;

    Fl_Output* letterCountLabel;

    Fl_Group* timerRadioGroup;

    Fl_Group* letterRadioGroup;

    Fl_Round_Button* timerRadioGroupButton[NUMBER_OF_BUTTONS_FOR_TIMER];

    Fl_Round_Button* letterRadioGroupButton[NUMBER_OF_BUTTONS_FOR_LETTER_COUNT];

    int selectedTime;

    int selectedNumberOfLetters;

    void createButtonsForTimer();

    void createButtonsForLetters();

    static void cbTimerChanged(Fl_Widget* widget, void* data);

    static void cbLetterCountChanged(Fl_Widget* widget, void* data);

    inline void setTimer(const string& value);

    inline void setLetterCount(const string& value);

    void draw();



public:
    SettingsWindow();

    virtual ~SettingsWindow();

    int getSelectedTime();

    int getSelectedNumberOfLetter();

    void okHandler();

    void cancelHandler();

};

}

#endif // SETTINGSWINDOW_H
