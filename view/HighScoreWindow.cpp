#include "HighScoreWindow.h"

namespace view
{
HighScoreWindow::HighScoreWindow(const string& scoreDisplay, WordScrambleController controller) : Fl_Window(575, 375, "High Scores")
{
    this->selectedDisplayChoice = DEFAULT_DISPLAY_CHOICE;
    this->selectedSortChoice = DEFAULT_SORT_CHOICE;
    this->controller = controller;

    begin();
    this->highScoresTextBuffer = new Fl_Text_Buffer();
    this->highScoresTextDisplay = new Fl_Text_Display(15,30,500,300, "");
    this->highScoresTextDisplay->textfont(FL_COURIER);
    this->highScoresTextDisplay->buffer(this->highScoresTextBuffer);
    this->backButton = new Fl_Button(0, 0, 100, 30, "Back");
    this->backButton->callback(cbBack, this);
    this->setBackLocation(210, 335);
    this->createButtonsForDisplayChoice();
    this->createButtonsForSortChoice();
    this->highScoresTextBuffer->text(scoreDisplay.c_str());
    end();
}

HighScoreWindow::~HighScoreWindow()
{
    for (int i = 0; i < NUMBER_OF_BUTTONS_FOR_CHOICES; i++)
    {
        delete this->displayChoiceRadioGroupButtons[i];
    }
    for (int i = 0; i < NUMBER_OF_BUTTONS_FOR_SORTS; i++)
    {
        delete this->sortChoiceRadioGroupButtons[i];
    }

    delete this->displayChoiceRadioGroup;
    delete this->sortChoiceRadioGroup;
    delete this->backButton;
    this->highScoresTextDisplay->buffer(0);
    delete this->highScoresTextBuffer;
    delete this->highScoresTextDisplay;
}

void HighScoreWindow::backHandler()
{
    this->hide();

}

void HighScoreWindow::cbBack(Fl_Widget* widget, void* data)
{
    HighScoreWindow* window = (HighScoreWindow*)data;
    window->backHandler();
}

void HighScoreWindow::setBackLocation(int x, int y)
{
    this->backButton->position(x, y);
}


void HighScoreWindow::createButtonsForDisplayChoice()
{
    const int X_RADIO_GROUP = 525;
    const int Y_RADIO_GROUP = 40;
    const int WIDTH_RADIO_GROUP = 200;
    const int HEIGHT_RADIO_GROUP = 300;
    this->displayChoiceRadioGroup = new Fl_Group(X_RADIO_GROUP, Y_RADIO_GROUP, WIDTH_RADIO_GROUP, HEIGHT_RADIO_GROUP);

    this->displayChoiceRadioGroup->begin();

    for (int i = 0; i < NUMBER_OF_BUTTONS_FOR_CHOICES; i++)
    {
        string label = DISPLAY_CHOICES[i];
        this->displayChoiceRadioGroupButtons[i] = new Fl_Round_Button(X_RADIO_GROUP, 30 + i*30, 25, 25, label.c_str());
        this->displayChoiceRadioGroupButtons[i]->type(FL_RADIO_BUTTON);
        this->displayChoiceRadioGroupButtons[i]->callback(cbDisplayChoiceChanged, this);
    }
    this->displayChoiceRadioGroup->end();
    this->setDisplayChoiceRadioButton();

}

void HighScoreWindow::createButtonsForSortChoice()
{
    const int X_RADIO_GROUP = 15;
    const int Y_RADIO_GROUP = 10;
    const int WIDTH_RADIO_GROUP = 300;
    const int HEIGHT_RADIO_GROUP = 100;
    this->sortChoiceRadioGroup = new Fl_Group(X_RADIO_GROUP, Y_RADIO_GROUP, WIDTH_RADIO_GROUP, HEIGHT_RADIO_GROUP);

    this->sortChoiceRadioGroup->begin();

    for (int i = 0; i < NUMBER_OF_BUTTONS_FOR_SORTS; i++)
    {
        string label = SORT_CHOICES[i];
        this->sortChoiceRadioGroupButtons[i] = new Fl_Round_Button(15 + i*200, 10, 25, 25, label.c_str());
        this->sortChoiceRadioGroupButtons[i]->type(FL_RADIO_BUTTON);
        this->sortChoiceRadioGroupButtons[i]->callback(cbSortChoiceChanged, this);
    }

    this->sortChoiceRadioGroup->end();
    this->setSortChoiceRadioButton();
}


void HighScoreWindow::cbDisplayChoiceChanged(Fl_Widget* widget, void* data)
{
    HighScoreWindow* window = (HighScoreWindow*)data;
    window->setDisplayChoice(widget->label());
    window->updateDisplay();
}

void HighScoreWindow::cbSortChoiceChanged(Fl_Widget* widget, void* data)
{
    HighScoreWindow* window = (HighScoreWindow*)data;
    window->setSortChoice(widget->label());
    window->updateSort();
    window->updateDisplay();

}

void HighScoreWindow::updateSort()
{
    if(this->selectedSortChoice == DEFAULT_SORT_CHOICE)
    {
        this->controller.sortScoreBoardByScore();
    }
    else
    {
        this->controller.sortScoreBoardByScoreAndTime();
    }
}

void HighScoreWindow::setDisplayChoice(const string& value)
{
    if(value == DISPLAY_CHOICES[INDEX_OF_ALL])
    {
        this->selectedDisplayChoice = DISPLAY_ALL_FLAG;
    }
    else
    {
        this->selectedDisplayChoice = stoi(value);
    }
}

void HighScoreWindow::setSortChoice(const string& value)
{
    this->selectedSortChoice = value;
}

void HighScoreWindow::setSortChoiceRadioButton()
{
    string sortChoice = this->selectedSortChoice;
    int indexForRadioButton = SORT_CHOICE_VALUES.find(sortChoice)->second;
    this->sortChoiceRadioGroupButtons[indexForRadioButton]->set();
}

void HighScoreWindow::setDisplayChoiceRadioButton()
{
    int displayChoice = this->selectedDisplayChoice;
    int indexForRadioButton = DISPLAY_CHOICE_VALUES.find(displayChoice)->second;
    this->displayChoiceRadioGroupButtons[indexForRadioButton]->set();
}

void HighScoreWindow::updateDisplay()
{
    string output = this->controller.getHighScores(this->selectedDisplayChoice);
    this->highScoresTextBuffer->text(output.c_str());
}


}
