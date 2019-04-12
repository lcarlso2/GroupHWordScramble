#include "MainWindow.h"

#include <iostream>
namespace view
{
MainWindow::MainWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();

    this->letters = this->controller.getLettersToDisplay(DEFAULT_NUMBER_OF_BUTTONS);

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
    this->letters = this->controller.getLettersToDisplay(DEFAULT_NUMBER_OF_BUTTONS);
    this->replaceLettersBeingDisplayed(this->letters);
}

void MainWindow::submitWord(const string& word)
{

}

void MainWindow::replaceLettersBeingDisplayed(vector<string> newLetters)
{
    for (int i = 0; i < DEFAULT_NUMBER_OF_BUTTONS; i++)
    {
        this->orderOfButtonsSelected.clear();
        this->letterSelectionRadioButton[i]->value(0);
        this->lettersChosenTextBuffer->text("");
        delete this->lettersBeingDisplayed[i];
        this->lettersBeingDisplayed[i] = new string(newLetters[i]);
        this->letterSelectionRadioButton[i]->label(this->lettersBeingDisplayed[i]->c_str());
    }

}

void MainWindow::createAndDisplayLetterSelection(vector<string> letters)
{
    for (int i = 0; i < DEFAULT_NUMBER_OF_BUTTONS; i++)
    {
        this->lettersBeingDisplayed[i] = new string(letters[i]);
        this->letterSelectionRadioButton[i] = new Fl_Round_Button(i*85+45, 215, 50, 25, this->lettersBeingDisplayed[i]->c_str());
        this->letterSelectionRadioButton[i]->callback(cbLetterSelected, this);
    }
}

void MainWindow::deleteRadioButtons()
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
    if(wordToDisplay.length() >= 3)
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
