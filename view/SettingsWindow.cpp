#include "SettingsWindow.h"

namespace view
{

SettingsWindow::SettingsWindow() : OkCancelWindow(330, 215, "Settings window")
{
    begin();


    this->timerLabel = new Fl_Output(210, 25, 0, 0, "Timer in minutes:");
    this->letterCountLabel = new Fl_Output(180, 90, 0, 0, "Letter count:");
    createButtonsForTimer();
    createButtonsForLetters();

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

void SettingsWindow::draw(){
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


    int timer = this->controller.getTimer();
    this->timerRadioGroupButton[(timer-OFFSET_TO_SELECTED_TIMER)]->set();
    this->selectedTimer = timer;

}

void SettingsWindow::createButtonsForLetters()
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

    int numberOfLetters = this->controller.getNumberOfLetters();
    this->letterRadioGroupButton[(numberOfLetters-OFFSET_TO_SELECTED_LETTER_COUNT)]->set();
    this->selectedNumberOfLetters = numberOfLetters;
}

int SettingsWindow::getSelectedTimer()
{
    return this->selectedTimer;
}

int SettingsWindow::getSelectedNumberOfLetters()
{
    return this->selectedNumberOfLetters;
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
    this->selectedTimer = stoi(value);
}


void SettingsWindow::setLetterCount(const string& value)
{
    this->selectedNumberOfLetters = stoi(value);
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
