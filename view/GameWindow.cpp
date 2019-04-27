#include "GameWindow.h"
#include <iostream>

namespace view
{
GameWindow::GameWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();
    this->controller.initializeGameLogic();
    this->numberOfButtonsToShow = this->controller.getButtonCount();
    this->controller.initializeRound(this->numberOfButtonsToShow);
    this->letters = this->controller.getLettersToDisplay();

    this->initializeButtons();
    this->initializeLabels();
    this->initializeTextDisplays();
    timerLabel->value(STARTING_TIMER_LABEL.c_str());
    this->startTimer();
    this->submitWordButton->hide();
    shouldUserEnterName = false;
    end();
}

void GameWindow::startTimer()
{
    globalTimer = this->controller.getTimerCount() * SECONDS + SECOND;
    Fl::add_timeout(SECOND, Timer_CB);
}

void GameWindow::initializeButtons()
{
    createAndDisplayLetterSelection(this->letters);

    this->endGameButton = new Fl_Button(210,145,125,25,"End Game");
    this->endGameButton->callback(cbEndgame, this);

    this->shuffleButton = new Fl_Button(50,175,125,25,"Shuffle letters");
    this->shuffleButton->callback(cbShuffleLetters, this);

    this->submitWordButton = new Fl_Button(210,250,125,25,"Submit word");
    this->submitWordButton->callback(cbSubmitWord, this);

    this->clearWordButton = new Fl_Button(365,175,125,25,"Clear word");
    this->clearWordButton->callback(cbClearWord, this);
}

void GameWindow::initializeLabels()
{
    timerLabel = new Fl_Output(110,5,40,25,"Seconds left: ");
    timerLabel->callback(cbGameOver, this);

    this->scoreLabel = new Fl_Output(475,5,50,25,"Points: ");
    this->scoreLabel->value("0");

    this->wordsLeftLabel = new Fl_Output(275,5,50,25,"Words left:");

    this->setWordsLeftLabel();
}

void GameWindow::initializeTextDisplays()
{
    this->guessedWordsTextBuffer = new Fl_Text_Buffer();
    this->guessedWordsTextDisplay = new Fl_Text_Display(20,50,500,90, "");
    this->guessedWordsTextDisplay->textfont(FL_COURIER);
    this->guessedWordsTextDisplay->buffer(this->guessedWordsTextBuffer);
    this->guessedWordsTextBuffer->text(this->controller.getWordsToDisplay().c_str());

    this->lettersChosenTextBuffer = new Fl_Text_Buffer();
    this->lettersChosenTextDisplay = new Fl_Text_Display(180,175,180,25,"");
    this->lettersChosenTextDisplay->textfont(FL_COURIER);
    this->lettersChosenTextDisplay->buffer(this->lettersChosenTextBuffer);

}

void GameWindow::setWordsLeftLabel()
{
    if (this->controller.checkForNoRemainingWords())
    {
        shouldUserEnterName = true;
        fl_message("%s", "You won!");
        this->endGame();
    }
    else
    {
        string wordsLeft = this->controller.getWordsRemainingCountFormatted();
        this->wordsLeftLabel->value(wordsLeft.c_str());
    }
}

void GameWindow::cbGameOver(Fl_Widget* widget, void* data)
{
    GameWindow* window = (GameWindow*)data;
    if (timeUp == true)
    {
        shouldUserEnterName = true;
        fl_message("%s", "Game Over");
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
    Fl::remove_timeout(Timer_CB);
    this->hide();
}


void GameWindow::Timer_CB(void* data)
{
    globalTimer -= SECOND;
    string time = toTime(globalTimer);
    timerLabel->value(time.c_str());
    if (globalTimer <= NO_TIME_LEFT )
    {
        Fl::remove_timeout(Timer_CB, data);
        timeUp = true;
        timerLabel->do_callback();
    }
    else
    {
        if (globalTimer < TIME_ALMOST_UP)
        {
            timerLabel->color(FL_RED);
        }
        Fl::repeat_timeout(SECOND, Timer_CB, data);
    }
}


void GameWindow::cbShuffleLetters(Fl_Widget* widget, void* data)
{
    GameWindow* window = (GameWindow*)data;
    window->shuffleLetters();
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
    this->orderOfButtonsSelected.clear();
    this->shuffleButton->show();
    this->submitWordButton->hide();
    for (int i = 0; i < this->numberOfButtonsToShow; i++)
    {
        this->letterSelectionButton[i]->color(FL_BACKGROUND_COLOR);
        this->letterSelectionButton[i]->redraw();
    }
    this->lettersChosenTextBuffer->text("");

}

void GameWindow::shuffleLetters()
{
    this->submitWordButton->hide();
    this->letters = this->controller.getShuffledLetters(this->letters);
    this->replaceLettersBeingDisplayed(this->letters);
}


void GameWindow::submitWord(const string& word)
{
    if (this->controller.checkThatWordWasNotAlreadyGuessed(word))
    {
        fl_message("%s", "Word already guessed!");
    }
    else if (this->controller.checkThatWordIsBonusWord(word))
    {
        fl_message("%s", "Bonus word!");
        this->guessedWordsTextBuffer->text(this->controller.getWordsToDisplay().c_str());
        this->controller.addScoreForWord(word);
        string points = to_string(this->controller.getTotalScore());
        this->scoreLabel->value(points.c_str());
    }
    else if (this->controller.checkWord(word))
    {
        this->setWordsLeftLabel();
        this->guessedWordsTextBuffer->text(this->controller.getWordsToDisplay().c_str());
        this->controller.addScoreForWord(word);
        string points = to_string(this->controller.getTotalScore());
        this->scoreLabel->value(points.c_str());
    }
    else
    {
        fl_message("%s", "Invalid word! You lose ten points!");
        this->controller.decrementScore();
        string points = to_string(this->controller.getTotalScore());
        this->scoreLabel->value(points.c_str());
    }
    this->clearWord();
    this->shuffleButton->show();
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

    this->determineIfShuffleButtonNeedsToBeShown();
}

void GameWindow::determineIfShuffleButtonNeedsToBeShown()
{
    if (!this->orderOfButtonsSelected.empty())
    {
        this->shuffleButton->hide();
    }
    else
    {
        this->shuffleButton->show();
    }
}

void GameWindow::displayLettersSelected()
{
    string wordToDisplay = "";
    for(auto& button : this->orderOfButtonsSelected)
    {
        wordToDisplay += button->label();
    }

    this->lettersChosenTextBuffer->text(wordToDisplay.c_str());

    this->determineIfSubmitButtonNeedsToBeShown(wordToDisplay);
}

void GameWindow::determineIfSubmitButtonNeedsToBeShown(const string& wordToDisplay)
{
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
    return stoi(this->scoreLabel->value());
}

string GameWindow::getTimer()
{
    return timerLabel->value();
}

bool GameWindow::getShouldUserEnterName()
{
    return shouldUserEnterName;
}

GameWindow::~GameWindow()
{
    Fl::remove_timeout(Timer_CB);
    delete this->shuffleButton;
    delete this->submitWordButton;
    delete this->clearWordButton;
    delete this->endGameButton;

    this->deleteLetterButtons();

    this->lettersChosenTextDisplay->buffer(0);
    delete this->lettersChosenTextBuffer;
    delete this->lettersChosenTextDisplay;

    delete timerLabel;
    delete this->scoreLabel;
    delete this->wordsLeftLabel;

    this->guessedWordsTextDisplay->buffer(0);
    delete this->guessedWordsTextBuffer;
    delete this->guessedWordsTextDisplay;
}

}
