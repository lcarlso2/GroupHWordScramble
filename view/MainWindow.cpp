#include "MainWindow.h"

#include <iostream>
namespace view
{
MainWindow::MainWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();

    this->numberOfButtonsToShow = this->controller.getNumberOfLetters();

    this->letters = this->controller.getLettersToDisplay(this->numberOfButtonsToShow);

    createAndDisplayLetterSelection(this->letters);

    this->lettersChosenTextBuffer = new Fl_Text_Buffer();
    this->lettersChosenTextDisplay = new Fl_Text_Display(180,175,180,25,"");
    this->lettersChosenTextDisplay->textfont(FL_COURIER);
    this->lettersChosenTextDisplay->buffer(this->lettersChosenTextBuffer);

    this->timerLabel = new Fl_Output(130,15,5,5, "Time left");

    this->pointsLabel = new Fl_Output(250,5,25,25,"");
    this->pointsLabel->value("0");

    timerTextBuffer = new Fl_Text_Buffer();
    this->timerTextDisplay = new Fl_Text_Display(5,5,50,25,"");
    this->timerTextDisplay->textfont(FL_COURIER);
    this->timerTextDisplay->buffer(timerTextBuffer);
    this->timerTextDisplay->callback(cbStartGame, this);

    string timerDisplay = to_string(this->controller.getTimer());
    timerTextBuffer->text(timerDisplay.c_str());

    this->shuffleButton = new Fl_Button(50,175,125,25,"Shuffle letters");
    this->shuffleButton->callback(cbShuffleLetters, this);

    this->newLettersButton = new Fl_Button(365,175,125,25,"New letters");
    this->newLettersButton->callback(cbNewLetters, this);

    this->submitWordButton = new Fl_Button(365,145,125,25,"Submit word");
    this->submitWordButton->callback(cbSubmitWord, this);

    this->settingsButton = new Fl_Button(400,10,125,25,"Settings");
    this->settingsButton->callback(cbSettings, this);

    this->clearWordButton = new Fl_Button(50,145,125,25,"Clear word");
    this->clearWordButton->callback(cbClearWord, this);

    this->startGame = new Fl_Button(25,50,100,25, "Start game");
    this->startGame->callback(cbStartGame, this);


    this->submitWordButton->hide();

    end();
}

void MainWindow::Timer_CB(void* data) {
    int count = globalTimer;
    count -= 1;
    printf("Timer! #%d\n", count);
    string countString = to_string(count);
    timerTextBuffer->text(countString.c_str());
    if ( count <= 0 ) {
        // After 10 timer ticks, turn timer off
        Fl::remove_timeout(Timer_CB, data);
        printf("Timer turned off.\n");
    } else {
        // less than 10 timer ticks? Keep running
        //window->setTimer(count, window);
        Fl::repeat_timeout(1, Timer_CB, data);
    }
}

void MainWindow::cbStartGame(Fl_Widget* widget, void* data) {
    MainWindow* window = (MainWindow*) data;
    globalTimer = 5;
    Fl::add_timeout(1, Timer_CB);
   // window->setTimer();
}


void MainWindow::setTimer() {
    cout << "HERE?" << endl;
    string value = to_string(globalTimer);
    cout << value << "    TIME " << endl;
    //cout << (window == nullptr) << endl;
   // window->timerLabel->value(value.c_str());
    //this->timerTextBuffer->text(value.c_str());
  // this->timerLabel->value(value.c_str());
 // cout << (this->lettersChosenTextBuffer == nullptr) << " IS THIS NULL " << endl;
 // this->lettersChosenTextBuffer->text(value.c_str());
 //cout << this->numberOfButtonsToShow << "    TEST THIS" << endl;
//    window->setTime(time);
    cout << "DOES IT" << endl;
}


MainWindow::~MainWindow()
{
    delete this->shuffleButton;
    delete this->newLettersButton;
    delete this->submitWordButton;
    delete this->settingsButton;
    delete this->clearWordButton;

    this->deleteLetterButtons();

    this->lettersChosenTextDisplay->buffer(0);
    delete this->lettersChosenTextBuffer;
    delete this->lettersChosenTextDisplay;

    this->timerTextDisplay->buffer(0);
    delete timerTextBuffer;
    delete this->timerTextDisplay;
    delete this->timerLabel;
    delete this->pointsLabel;

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

void MainWindow::cbSettings(Fl_Widget* widget, void* data)
{
    MainWindow* window = (MainWindow*)data;
    SettingsWindow settingsWindow;

    settingsWindow.set_modal();
    settingsWindow.show();

    while (settingsWindow.shown())
    {
        Fl::wait();
    }

    if (settingsWindow.getWindowResult() == OkCancelWindow::WindowResult::OK)
    {
        window->resetButtons(settingsWindow.getSelectedNumberOfLetters(), settingsWindow.getSelectedTimer());
    }

}

void MainWindow::resetButtons(const int letterCount, const int timer)
{
    this->controller.writeSettingsToFile(letterCount, timer);
    this->deleteLetterButtons();
    this->numberOfButtonsToShow = letterCount;
    this->begin();
    this->letters = this->controller.getLettersToDisplay(this->numberOfButtonsToShow);
    this->createAndDisplayLetterSelection(this->letters);
    string timerDisplay = to_string(timer);
    timerTextBuffer->text(timerDisplay.c_str());
    this->end();
}

void MainWindow::cbClearWord(Fl_Widget* widget, void* data)
{
    MainWindow* window = (MainWindow*)data;
    window->clearWord();
}

void MainWindow::clearWord()
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

void MainWindow::shuffleLetters()
{
    this->submitWordButton->hide();
    this->letters = this->controller.getShuffledLetters(this->letters);
    this->replaceLettersBeingDisplayed(this->letters);

}

void MainWindow::getNewLetters()
{
    this->submitWordButton->hide();
    this->letters = this->controller.getLettersToDisplay(this->numberOfButtonsToShow);
    this->replaceLettersBeingDisplayed(this->letters);
}

void MainWindow::submitWord(const string& word)
{
    int points = this->controller.getPointsForWord(word.length());

    string currentPoints = this->pointsLabel->value();

    int totalPoints = points + stoi(currentPoints);

    string totalPointsAsString = to_string(totalPoints);

    this->pointsLabel->value(totalPointsAsString.c_str());

}

void MainWindow::replaceLettersBeingDisplayed(vector<string> newLetters)
{
    this->clearWord();
    for (int i = 0; i < this->numberOfButtonsToShow; i++)
    {
        delete this->lettersBeingDisplayed[i];
        this->lettersBeingDisplayed[i] = new string(newLetters[i]);
        this->letterSelectionButton[i]->label(this->lettersBeingDisplayed[i]->c_str());
    }
}

void MainWindow::createAndDisplayLetterSelection(vector<string> letters)
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

void MainWindow::deleteLetterButtons()
{
    this->orderOfButtonsSelected.clear();

    for (int i = 0; i < this->numberOfButtonsToShow; i++)
    {
        this->letterSelectionButton[i]->hide();
        delete this->letterSelectionButton[i];
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
