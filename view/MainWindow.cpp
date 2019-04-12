#include "MainWindow.h"

#include <iostream>
namespace view
{
MainWindow::MainWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();


    vector<string> letters = this->controller.getLettersToDisplay();

    createAndDisplayLetterSelection(letters);

    this->lettersChosenTextBuffer = new Fl_Text_Buffer();
    this->lettersChosenTextDisplay = new Fl_Text_Display(180, 270, 180, 25, "");
    this->lettersChosenTextDisplay->textfont(FL_COURIER);
    this->lettersChosenTextDisplay->buffer(lettersChosenTextBuffer);


    end();
}

MainWindow::~MainWindow()
{
    this->deleteButtons();
    this->lettersChosenTextDisplay->buffer(0);
    delete this->lettersChosenTextBuffer;
    delete this->lettersChosenTextDisplay;
}

void MainWindow::createAndDisplayLetterSelection(vector<string> letters)
{
    for (int i = 0; i < DEFAULT_NUMBER_OF_BUTTONS; i++)
    {
        this->lettersBeingDisplayed[i] = new string(letters[i]);
        this->letterSelectionRadioButton[i] = new Fl_Round_Button(i*85+45, 300, 50, 25, this->lettersBeingDisplayed[i]->c_str());
        this->letterSelectionRadioButton[i]->callback(cbLetterSelected, this);
    }
}

void MainWindow::deleteButtons()
{
    for (int i = 0; i < DEFAULT_NUMBER_OF_BUTTONS; i++)
    {
        delete this->letterSelectionRadioButton[i];
        delete this->lettersBeingDisplayed[i];
    }
}

void MainWindow::cbLetterSelected(Fl_Widget* widget, void* data)
{
    MainWindow* window = (MainWindow*)data;
    window->letterSelected(widget);
}

void MainWindow::letterSelected(Fl_Widget* widget)
{
    bool widgetAlreadyAdded = false;
    for(size_t buttonIndex = 0; buttonIndex < this->orderOfButtonsSelected.size(); buttonIndex++)
    {
        if (this->orderOfButtonsSelected[buttonIndex] == widget)
        {
            widgetAlreadyAdded = true;
            this->orderOfButtonsSelected.erase(this->orderOfButtonsSelected.begin() + buttonIndex);
        }
    }
    if (!widgetAlreadyAdded)
    {
        this->orderOfButtonsSelected.push_back(widget);
    }
    this->displayLettersSelected();
}

void MainWindow::displayLettersSelected()
{
    string wordToDisplay = "";
    for(auto& button : this->orderOfButtonsSelected)
    {
        if (button->active())
        {
            wordToDisplay += button->label();
        }
    }
    this->lettersChosenTextBuffer->text(wordToDisplay.c_str());

}




}
