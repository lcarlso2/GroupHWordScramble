#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "OkCancelWindow.h"
#include "SettingsWindow.h"

#include "WordScrambleController.h"
using namespace controller;

namespace view
{
    const int DEFAULT_NUMBER_OF_BUTTONS = 6;
    const int MAX_NUMBER_OF_BUTTONS = 7;
    const int MINIMUM_NUMBER_OF_LETTERS_REQUIRED = 3;
    const int MINIMUM_NUMBER_OF_BUTTONS = 5;

/**
* The main window class
* @author Lucas Carlson and Carson Bedrosian
* @version 4/12/2019
*/
class MainWindow : public Fl_Window
{


private:

    string* lettersBeingDisplayed[MAX_NUMBER_OF_BUTTONS];

    vector<Fl_Widget*> orderOfButtonsSelected;

    WordScrambleController controller;
    int numberOfButtonsToShow;
    vector<string> letters;

    Fl_Button* shuffleButton;
    Fl_Button* newLettersButton;
    Fl_Button* submitWordButton;
    Fl_Button* settingsButton;
    Fl_Button* clearWordButton;
    Fl_Button* letterSelectionButton[MAX_NUMBER_OF_BUTTONS];

    Fl_Output* timerLabel;
    Fl_Output* pointsLabel;

    Fl_Text_Buffer* lettersChosenTextBuffer;
    Fl_Text_Display* lettersChosenTextDisplay;

    Fl_Text_Buffer* timerTextBuffer;
    Fl_Text_Display* timerTextDisplay;

    void displayLettersSelected();
    void createAndDisplayLetterSelection(vector<string> letters);
    void deleteLetterButtons();
    void replaceLettersBeingDisplayed(vector<string> newLetters);

    static void cbLetterSelected(Fl_Widget* widget, void* data);
    static void cbShuffleLetters(Fl_Widget* widget, void* data);
    static void cbNewLetters(Fl_Widget* widget, void* data);
    static void cbSubmitWord(Fl_Widget* widget, void* data);
    static void cbSettings(Fl_Widget* widget, void* data);
    static void cbClearWord(Fl_Widget* widget, void* data);

    inline void shuffleLetters();
    inline void getNewLetters();
    inline void letterSelected(Fl_Widget* widget);
    inline void submitWord(const string& word);
    inline void clearWord();
    inline void resetButtons(const int letterCount, const int timer);

    void displayTimeRemaining(const int time);

public:
    /**
    * Creates a new main window object
    * @param width the width of the window
    * @param height the height of the window
    * @param title the title of the window
    * @precondition none
    * @postcondition the window is created
    */
    MainWindow(int width, int height, const char* title);

    /**
    * Destructs the main window object
    */
    virtual ~MainWindow();

    /**
    *Gets the word to submit
    *@precondition none
    *@return the word to submit
    */
    string getWordToSubmit();

};
}

#endif // MAINWINDOW_H
