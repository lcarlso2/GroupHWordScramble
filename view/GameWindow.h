#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Timer.H>
#include <Fl/fl_ask.H>

#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <time.h>
using namespace std;

#include "OkCancelWindow.h"
#include "SettingsWindow.h"

#include "Utils.h"
#include "WordScrambleController.h"
using namespace controller;

namespace view
{

const string STARTING_TIMER_LABEL = "0:00";
const int DEFAULT_NUMBER_OF_BUTTONS = 6;
const int MAX_NUMBER_OF_BUTTONS = 7;
const int MINIMUM_NUMBER_OF_LETTERS_REQUIRED = 3;
const int MINIMUM_NUMBER_OF_BUTTONS = 5;
const int SECONDS = 60;
const int SECOND = 1;
const int TIME_ALMOST_UP = 10;
const int NO_TIME_LEFT = 0;
const int DEFAULT_SCORE = 0;
static int globalTimer;
static bool timeUp = false;
static bool shouldUserEnterName = false;

static Fl_Output* timerLabel;

/**
* The game window class responsible for running the word scramble game
* @author Lucas Carlson and Carson Bedrosian
* @version 4/19/2019
*/
class GameWindow : public Fl_Window
{

private:
    WordScrambleController controller;

    string* lettersBeingDisplayed[MAX_NUMBER_OF_BUTTONS];

    vector<Fl_Widget*> orderOfButtonsSelected;

    int numberOfButtonsToShow;
    vector<string> letters;

    Fl_Button* shuffleButton;
    Fl_Button* submitWordButton;
    Fl_Button* clearWordButton;
    Fl_Button* letterSelectionButton[MAX_NUMBER_OF_BUTTONS];
    Fl_Button* endGameButton;

    Fl_Output* scoreLabel;

    Fl_Output* wordsLeftLabel;

    Fl_Text_Buffer* guessedWordsTextBuffer;
    Fl_Text_Display* guessedWordsTextDisplay;

    Fl_Text_Buffer* lettersChosenTextBuffer;
    Fl_Text_Display* lettersChosenTextDisplay;

    static void cbLetterSelected(Fl_Widget* widget, void* data);
    static void cbShuffleLetters(Fl_Widget* widget, void* data);
    static void cbSubmitWord(Fl_Widget* widget, void* data);
    static void cbClearWord(Fl_Widget* widget, void* data);
    static void cbEndgame(Fl_Widget* widget, void* data);

    static void cbGameOver(Fl_Widget* widget, void* data);

    static void Timer_CB(void* data);

    inline void shuffleLetters();
    inline void letterSelected(Fl_Widget* widget);
    inline void submitWord(const string& word);
    inline void clearWord();
    inline void endGame();

    void determineIfShuffleButtonNeedsToBeShown();
    void determineIfSubmitButtonNeedsToBeShown(const string& wordToDisplay);

    void displayLettersSelected();
    void createAndDisplayLetterSelection(vector<string> letters);
    void deleteLetterButtons();
    void replaceLettersBeingDisplayed(vector<string> newLetters);
    void setWordsLeftLabel();
    void initializeButtons();
    void initializeLabels();
    void initializeTextDisplays();
    void startTimer();

public:
    /**
    * Constructs a new game window
    * @param width the width of the window
    * @param height the height of the window
    * @param title the title of the window
    * @precondition none
    * @postcondition the window is created
    */
    GameWindow(int width, int height, const char* title);

    /**
    * destructs the game window
    */
    virtual ~GameWindow();

    /**
    *Gets the word to submit
    *@precondition none
    *@return the word to submit
    */
    string getWordToSubmit();

    /**
    * Gets the points the player scored
    * @precondition none
    * @return the number of points the player scored
    */
    int getScore();

    /**
    * Gets current value of the timer
    * @precondition none
    * @postcondition none
    * @return Returns the current value of the timer
    */
    string getTimer();

    /**
    * Returns true if user should enter name and false if not
    * @precondition none
    * @postcondition none
    * @return Returns true if user should enter name and false if not
    */
    bool getShouldUserEnterName();
};

}

#endif // GAMEWINDOW_H
