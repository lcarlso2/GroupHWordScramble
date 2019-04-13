#include "MainWindow.h"

#include <iostream>
namespace view
{
MainWindow::MainWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();

    this->numberOfButtonsToShow = 7;

    this->letters = this->controller.getLettersToDisplay(this->numberOfButtonsToShow);

    createAndDisplayLetterSelection(this->letters);

    this->lettersChosenTextBuffer = new Fl_Text_Buffer();
    this->lettersChosenTextDisplay = new Fl_Text_Display(180,175,180,25,"");
    this->lettersChosenTextDisplay->textfont(FL_COURIER);
    this->lettersChosenTextDisplay->buffer(lettersChosenTextBuffer);

    this->shuffleButton = new Fl_Button(50,175,125,25,"Shuffle letters");
    this->shuffleButton->callback(cbShuffleLetters, this);

    this->newLettersButton = new Fl_Button(365,175,125,25,"New letters");
    this->newLettersButton->callback(cbNewLetters, this);

    this->submitWordButton = new Fl_Button(207,145,125,25,"Submit word");
    this->submitWordButton->callback(cbSubmitWord, this);

    this->submitWordButton->hide();

    end();
}

MainWindow::~MainWindow()
{
    this->deleteRadioButtons();
    this->lettersChosenTextDisplay->buffer(0);
    delete this->lettersChosenTextBuffer;
    delete this->lettersChosenTextDisplay;
    delete this->shuffleButton;
    delete this->newLettersButton;
    delete this->submitWordButton;
}

void MainWindow::cbShuffleLetters(Fl_Widget* widget, void* data)
{
    MainWindow* window = (MainWindow*)data;
    window->shuffleLetters();

}

void MainWindow::cbNewLetters(Fl_Widget* widget, void* data)
{
    MainWindow* window = (MainWindow*)data;
    window->getNewLetters();
}

void MainWindow::cbSubmitWord(Fl_Widget* widget, void* data)
{
    MainWindow* window = (MainWindow*)data;
    window->submitWord(window->getWordToSubmit());
}

void MainWindow::shuffleLetters()
{
    this->letters = this->controller.getShuffledLetters(this->letters);
    this->replaceLettersBeingDisplayed(this->letters);

}

void MainWindow::getNewLetters()
{
    this->letters = this->controller.getLettersToDisplay(this->numberOfButtonsToShow);
    this->replaceLettersBeingDisplayed(this->letters);
}

void MainWindow::submitWord(const string& word)
{

}

void MainWindow::replaceLettersBeingDisplayed(vector<string> newLetters)
{
    for (int i = 0; i < this->numberOfButtonsToShow; i++)
    {
        this->orderOfButtonsSelected.clear();
        this->letterSelectionRadioButton[i]->value(0);
        this->lettersChosenTextBuffer->text("");
        this->letterSelectionRadioButton[i]->color(FL_BACKGROUND_COLOR);
        delete this->lettersBeingDisplayed[i];
        this->lettersBeingDisplayed[i] = new string(newLetters[i]);
        this->letterSelectionRadioButton[i]->label(this->lettersBeingDisplayed[i]->c_str());
    }

}

void MainWindow::createAndDisplayLetterSelection(vector<string> letters)
{
    for (int i = 0; i < this->numberOfButtonsToShow; i++)
    {
        this->lettersBeingDisplayed[i] = new string(letters[i]);
        if (this->numberOfButtonsToShow == MINIMUM_NUMBER_OF_BUTTONS)
        {
            this->letterSelectionRadioButton[i] = new Fl_Button(i*85+75, 215, 50, 25, this->lettersBeingDisplayed[i]->c_str());
        }
        else if (this->numberOfButtonsToShow == DEFAULT_NUMBER_OF_BUTTONS)
        {
            this->letterSelectionRadioButton[i] = new Fl_Button(i*68+75, 215, 50, 25, this->lettersBeingDisplayed[i]->c_str());
        }
        else
        {
            this->letterSelectionRadioButton[i] = new Fl_Button(i*57+75, 215, 50, 25, this->lettersBeingDisplayed[i]->c_str());
        }
        this->letterSelectionRadioButton[i]->callback(cbLetterSelected, this);
    }
}

void MainWindow::deleteRadioButtons()
{
    for (int i = 0; i < this->numberOfButtonsToShow; i++)
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
            widget->color(FL_BACKGROUND_COLOR);
            this->orderOfButtonsSelected.erase(this->orderOfButtonsSelected.begin() + buttonIndex);
        }
    }
    if (!widgetAlreadyAdded)
    {
        Fl_Color color = labelcolor();
        widget->color(fl_inactive(color));
        this->orderOfButtonsSelected.push_back(widget);
    }
    this->displayLettersSelected();
}

void MainWindow::displayLettersSelected()
{
    string wordToDisplay = "";
    for(auto& button : this->orderOfButtonsSelected)
    {

        wordToDisplay += button->label();
    }
    this->lettersChosenTextBuffer->text(wordToDisplay.c_str());
    if(wordToDisplay.length() >= MINIMUM_NUMBER_OF_LETTERS_REQUIRED)
    {
        this->submitWordButton->show();
    }
    else
    {
        this->submitWordButton->hide();
    }

}

string MainWindow::getWordToSubmit()
{
    this->lettersChosenTextBuffer->text();
}




}
