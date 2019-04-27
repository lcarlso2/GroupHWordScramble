#include "SettingsWindow.h"

namespace view
{

SettingsWindow::SettingsWindow(const int timerCount, const int buttonCount) : OkCancelWindow(330, 215, "Settings window")
{
    this->selectedTimerCount = timerCount;
    this->selectedButtonCount = buttonCount;
    begin();

    this->timerLabel = new Fl_Output(210, 25, 0, 0, "Timer in minutes:");
    this->letterCountLabel = new Fl_Output(180, 90, 0, 0, "Letter count:");
    this->createButtonsForTimer();
    this->createButtonsForButtonCount();

    this->setOKLocation(90, 170);
    this->setCancelLocation(170, 170);

    end();
}

SettingsWindow::~SettingsWindow()
{
    for (int i = 0; i < NUMBER_OF_BUTTONS_FOR_TIMER; i++)
    {
        delete this->timerRadioGroupButton[i];
        delete this->timerLabels[i];
        delete this->letterRadioGroupButton[i];
        delete this->letterCountLabels[i];
    }

    delete this->timerRadioGroup;
    delete this->letterRadioGroup;
    delete this->timerLabel;
    delete this->letterCountLabel;
}

void SettingsWindow::draw()
{
    Fl_Window::draw();
    fl_frame("AAAA", 85, 35, 150, 35);

    fl_frame2("AAAA", 85, 100, 150, 35);
}

void SettingsWindow::createButtonsForTimer()
{

    const int X_RADIO_GROUP = 95;
    const int Y_RADIO_GROUP = 45;
    const int WIDTH_RADIO_GROUP = 200;
    const int HEIGHT_RADIO_GROUP = 100;

    this->timerRadioGroup = new Fl_Group(X_RADIO_GROUP, Y_RADIO_GROUP, WIDTH_RADIO_GROUP, HEIGHT_RADIO_GROUP);
    this->timerRadioGroup->begin();
    for (int i = 0; i < NUMBER_OF_BUTTONS_FOR_TIMER; i++)
    {
        string label = to_string(i + OFFSET_TO_SELECTED_TIMER);
        this->timerLabels[i] = new string(label);
        this->timerRadioGroupButton[i] = new Fl_Round_Button(X_RADIO_GROUP + i*50, 35, 25, 25, this->timerLabels[i]->c_str());
        this->timerRadioGroupButton[i]->type(FL_RADIO_BUTTON);
        this->timerRadioGroupButton[i]->callback(cbTimerChanged, this);

    }

    this->timerRadioGroup->end();

    int timer = this->selectedTimerCount;
    this->timerRadioGroupButton[(timer-OFFSET_TO_SELECTED_TIMER)]->set();

}

void SettingsWindow::createButtonsForButtonCount()
{

    const int X_RADIO_GROUP = 95;
    const int Y_RADIO_GROUP = 45;
    const int WIDTH_RADIO_GROUP = 200;
    const int HEIGHT_RADIO_GROUP = 100;

    this->letterRadioGroup = new Fl_Group(X_RADIO_GROUP, Y_RADIO_GROUP, WIDTH_RADIO_GROUP, HEIGHT_RADIO_GROUP);
    this->letterRadioGroup->begin();
    for (int i = 0; i < NUMBER_OF_BUTTONS_FOR_LETTER_COUNT; i++)
    {
        string label = to_string(i + OFFSET_TO_SELECTED_LETTER_COUNT);
        this->letterCountLabels[i] = new string(label);
        this->letterRadioGroupButton[i] = new Fl_Round_Button(X_RADIO_GROUP + i*50, 100, 25, 25, this->letterCountLabels[i]->c_str());
        this->letterRadioGroupButton[i]->type(FL_RADIO_BUTTON);
        this->letterRadioGroupButton[i]->callback(cbLetterCountChanged, this);
    }

    this->letterRadioGroup->end();

    int buttonCount = this->selectedButtonCount;
    this->letterRadioGroupButton[(buttonCount-OFFSET_TO_SELECTED_LETTER_COUNT)]->set();
}

int SettingsWindow::getSelectedTimerCount()
{
    return this->selectedTimerCount;
}

int SettingsWindow::getSelectedButtonCount()
{
    return this->selectedButtonCount;
}


void SettingsWindow::cbTimerChanged(Fl_Widget* widget, void* data)
{
    SettingsWindow* window = (SettingsWindow*)data;
    window->setTimer(widget->label());
}

void SettingsWindow::cbLetterCountChanged(Fl_Widget* widget, void* data)
{
    SettingsWindow* window = (SettingsWindow*)data;
    window->setLetterCount(widget->label());
}

void SettingsWindow::setTimer(const string& value)
{
    this->selectedTimerCount = stoi(value);
}


void SettingsWindow::setLetterCount(const string& value)
{
    this->selectedButtonCount = stoi(value);
}

void SettingsWindow::okHandler()
{
    this->hide();

}

void SettingsWindow::cancelHandler()
{
    this->hide();
}


}
