#include "GameWindow.h"
#include <iostream>

namespace view
{
GameWindow::GameWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();

    this->numberOfButtonsToShow = this->controller.getNumberOfLetters();

    this->letters = this->controller.getLettersToDisplay(this->numberOfButtonsToShow);

    createAndDisplayLetterSelection(this->letters);

    this->lettersChosenTextBuffer = new Fl_Text_Buffer();
    this->lettersChosenTextDisplay = new Fl_Text_Display(180,175,180,25,"");
    this->lettersChosenTextDisplay->textfont(FL_COURIER);
    this->lettersChosenTextDisplay->buffer(this->lettersChosenTextBuffer);

    timerLabel = new Fl_Output(110,5,40,25,"Seconds left: ");
    timerLabel->callback(cbGameOver, this);

    this->pointsLabel = new Fl_Output(475,5,50,25,"Points: ");
    this->pointsLabel->value("0");

    this->endGameButton = new Fl_Button(225,5,125,25,"End Game");
    this->endGameButton->callback(cbEndgame, this);

    this->shuffleButton = new Fl_Button(50,175,125,25,"Shuffle letters");
    this->shuffleButton->callback(cbShuffleLetters, this);

    this->newLettersButton = new Fl_Button(365,175,125,25,"New letters");
    this->newLettersButton->callback(cbNewLetters, this);

    this->submitWordButton = new Fl_Button(365,145,125,25,"Submit word");
    this->submitWordButton->callback(cbSubmitWord, this);

    this->clearWordButton = new Fl_Button(50,145,125,25,"Clear word");
    this->clearWordButton->callback(cbClearWord, this);

    globalTimer = this->controller.getTimer() * 60 + 1;
    currentTimer = globalTimer;
    Fl::add_timeout(1, Timer_CB);

    this->submitWordButton->hide();

    end();
}

void GameWindow::cbGameOver(Fl_Widget* widget, void* data) {
    GameWindow* window = (GameWindow*)data;
    if (timeUp == true){
        window->hide();
    }
}

void GameWindow::cbEndgame(Fl_Widget* widget, void* data)
{
    GameWindow* window = (GameWindow*)data;
    window->endGame();
}

void GameWindow::endGame()
{
    this->hide();
}


void GameWindow::Timer_CB(void* data)
{
    currentTimer -= 1;
    string time = toTime(currentTimer);
    timerLabel->value(time.c_str());
    if ( currentTimer <= 0 )
    {
        Fl::remove_timeout(Timer_CB, data);
        timeUp = true;
        fl_message("%s", "Game Over");
        timerLabel->do_callback();
    }
    else
    {
        Fl::repeat_timeout(1, Timer_CB, data);
    }
}


void GameWindow::cbShuffleLetters(Fl_Widget* widget, void* data)
{
    GameWindow* window = (GameWindow*)data;
    window->shuffleLetters();
}

void GameWindow::cbNewLetters(Fl_Widget* widget, void* data)
{
    GameWindow* window = (GameWindow*)data;
    window->getNewLetters();
}

void GameWindow::cbSubmitWord(Fl_Widget* widget, void* data)
{
    GameWindow* window = (GameWindow*)data;
    window->submitWord(window->getWordToSubmit());
}

void GameWindow::cbClearWord(Fl_Widget* widget, void* data)
{
    GameWindow* window = (GameWindow*)data;
    window->clearWord();
}

void GameWindow::clearWord()
{
    this->submitWordButton->hide();
    for (int i = 0; i < this->numberOfButtonsToShow; i++)
    {
        this->letterSelectionButton[i]->color(FL_BACKGROUND_COLOR);
        this->letterSelectionButton[i]->redraw();
        this->orderOfButtonsSelected.clear();
    }
    this->lettersChosenTextBuffer->text("");

}

void GameWindow::shuffleLetters()
{
    this->submitWordButton->hide();
    this->letters = this->controller.getShuffledLetters(this->letters);
    this->replaceLettersBeingDisplayed(this->letters);
}

void GameWindow::getNewLetters()
{
    this->submitWordButton->hide();
    this->letters = this->controller.getLettersToDisplay(this->numberOfButtonsToShow);
    this->replaceLettersBeingDisplayed(this->letters);
}

void GameWindow::submitWord(const string& word)
{
    string currentPoints = this->pointsLabel->value();
    int totalPoints = this->controller.getPointsForWord(word, stoi(currentPoints));
    string points = to_string(totalPoints);
    this->pointsLabel->value(points.c_str());
}

void GameWindow::replaceLettersBeingDisplayed(vector<string> newLetters)
{
    this->clearWord();
    for (int i = 0; i < this->numberOfButtonsToShow; i++)
    {
        delete this->lettersBeingDisplayed[i];
        this->lettersBeingDisplayed[i] = new string(newLetters[i]);
        this->letterSelectionButton[i]->label(this->lettersBeingDisplayed[i]->c_str());
    }
}

void GameWindow::createAndDisplayLetterSelection(vector<string> letters)
{
    for (int i = 0; i < this->numberOfButtonsToShow; i++)
    {
        this->lettersBeingDisplayed[i] = new string(letters[i]);
        if (this->numberOfButtonsToShow == MINIMUM_NUMBER_OF_BUTTONS)
        {
            this->letterSelectionButton[i] = new Fl_Button(i*85+75, 215, 50, 25, this->lettersBeingDisplayed[i]->c_str());
        }
        else if (this->numberOfButtonsToShow == DEFAULT_NUMBER_OF_BUTTONS)
        {
            this->letterSelectionButton[i] = new Fl_Button(i*68+75, 215, 50, 25, this->lettersBeingDisplayed[i]->c_str());
        }
        else
        {
            this->letterSelectionButton[i] = new Fl_Button(i*57+75, 215, 50, 25, this->lettersBeingDisplayed[i]->c_str());
        }
        this->letterSelectionButton[i]->callback(cbLetterSelected, this);
    }
}

void GameWindow::deleteLetterButtons()
{
    this->orderOfButtonsSelected.clear();

    for (int i = 0; i < this->numberOfButtonsToShow; i++)
    {
        this->letterSelectionButton[i]->hide();
        delete this->letterSelectionButton[i];
        delete this->lettersBeingDisplayed[i];
    }
}

void GameWindow::cbLetterSelected(Fl_Widget* widget, void* data)
{
    GameWindow* window = (GameWindow*)data;
    window->letterSelected(widget);
}

void GameWindow::letterSelected(Fl_Widget* widget)
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

void GameWindow::displayLettersSelected()
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

string GameWindow::getWordToSubmit()
{
    return this->lettersChosenTextBuffer->text();
}

int GameWindow::getScore()
{
    return stoi(this->pointsLabel->value());
}

GameWindow::~GameWindow()
{
    Fl::remove_timeout(Timer_CB);
    delete this->shuffleButton;
    delete this->newLettersButton;
    delete this->submitWordButton;
    delete this->clearWordButton;
    delete this->endGameButton;

    this->deleteLetterButtons();

    this->lettersChosenTextDisplay->buffer(0);
    delete this->lettersChosenTextBuffer;
    delete this->lettersChosenTextDisplay;

    delete timerLabel;
    delete this->pointsLabel;
}

}
