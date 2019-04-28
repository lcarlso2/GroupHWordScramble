#ifndef HIGHSCOREWINDOW_H
#define HIGHSCOREWINDOW_H
#include "OkCancelWindow.h"
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Window.H>
#include <Fl/fl_draw.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Window.H>

#include <string>
#include <map>
using namespace std;

#include "WordScrambleController.h"
using namespace controller;


namespace view
{
const int NUMBER_OF_BUTTONS_FOR_CHOICES = 4;
const int NUMBER_OF_BUTTONS_FOR_SORTS = 2;
const string DISPLAY_CHOICES[] =  {"5", "10", "50", "All"};
const string SORT_CHOICES[] = {"Sort By Score", "Sort By Score And Time"};
const int DEFAULT_DISPLAY_CHOICE = 5;
const int INDEX_OF_ALL = 3;
const int DISPLAY_ALL_FLAG = 0;
const map<int, int> DISPLAY_CHOICE_VALUES = {{5, 0}, {10, 1}, {50, 2}, {0, 3}};
const map<string, int> SORT_CHOICE_VALUES = {{"Sort By Score", 0}, {"Sort By Score And Time", 1}};
const string DEFAULT_SORT_CHOICE = "Sort By Score";

/**
* The high score window class that takes cares of displaying and added high scores
* @author Lucas Carlson and Carson Bedrosian
* @version 4/19/2019
*/
class HighScoreWindow  : public Fl_Window
{
private:

    WordScrambleController controller;
    Fl_Text_Buffer* highScoresTextBuffer;
    Fl_Text_Display* highScoresTextDisplay;

    Fl_Button* backButton;
    Fl_Button* clearButton;
    Fl_Group* displayChoiceRadioGroup;
    Fl_Round_Button* displayChoiceRadioGroupButtons[NUMBER_OF_BUTTONS_FOR_CHOICES];

    Fl_Group* sortChoiceRadioGroup;
    Fl_Round_Button* sortChoiceRadioGroupButtons[NUMBER_OF_BUTTONS_FOR_SORTS];


    int selectedDisplayChoice;
    string selectedSortChoice;
    bool wasClearClicked;

    static void cbDisplayChoiceChanged(Fl_Widget* widget, void* data);
    static void cbSortChoiceChanged(Fl_Widget* widget, void* data);
    static void cbBack(Fl_Widget* widget, void* data);
    static void cbClear(Fl_Widget* widget, void* data);

    inline void setDisplayChoice(const string& value);
    void setDisplayChoiceRadioButton();
    inline void setSortChoice(const string& value);
    void setSortChoiceRadioButton();

    inline void backHandler();
    inline void clearHandler();

    inline void updateDisplay();
    inline void updateSort();


    void createButtonsForDisplayChoice();

    void createButtonsForSortChoice();

public:

    /**
    * Creates a new high score window
    * @precondition none
    * @postcondition the window is created
    * @param controller The controller being passed in
    */
    HighScoreWindow(WordScrambleController controller);

    /**
    * Destructs the high score window
    */
    virtual ~HighScoreWindow();

    /**
    * Returns if the clear button was clicked
    * @precondition none
    * @postcondition none
    * @return Returns true if clear was clicked and false if not
    */
    bool getWasClearClicked();

};

}

#endif // HIGHSCOREWINDOW_H
