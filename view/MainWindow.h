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

#include "Controller.h"
using namespace controller;

namespace view
{

/**
* The main window class
* @author Lucas Carlson and Carson Bedrosian
* @version 4/12/2019
*/
class MainWindow : public Fl_Window
{

private:
    static const int DEFAULT_NUMBER_OF_BUTTONS = 6;
    vector<string> letters;

    string* lettersBeingDisplayed[DEFAULT_NUMBER_OF_BUTTONS];

    vector<Fl_Widget*> orderOfButtonsSelected;

    Controller controller;

    Fl_Button* shuffleButton;
    Fl_Button* newLettersButton;
    Fl_Button* submitWordButton;

    Fl_Round_Button* letterSelectionRadioButton[DEFAULT_NUMBER_OF_BUTTONS];

    Fl_Text_Buffer *lettersChosenTextBuffer;
    Fl_Text_Display *lettersChosenTextDisplay;

    void displayLettersSelected();

    void createAndDisplayLetterSelection(vector<string> letters);

    void deleteRadioButtons();

    void replaceLettersBeingDisplayed(vector<string> newLetters);

    static void cbLetterSelected(Fl_Widget* widget, void* data);
    static void cbShuffleLetters(Fl_Widget* widget, void* data);
    static void cbNewLetters(Fl_Widget* widget, void* data);
    static void cbSubmitWord(Fl_Widget* widget, void* data);

    inline void shuffleLetters();
    inline void getNewLetters();
    inline void letterSelected(Fl_Widget* widget);
    inline void submitWord(const string& word);

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
