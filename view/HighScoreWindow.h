#ifndef HIGHSCOREWINDOW_H
#define HIGHSCOREWINDOW_H
#include "OkCancelWindow.h"
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>

#include "WordScrambleController.h"
using namespace controller;


namespace view
{

/**
* The high score window class that takes cares of displaying and added high scores
* @author Lucas Carlson and Carson Bedrosian
* @version 4/19/2019
*/
class HighScoreWindow  : public OkCancelWindow
{
private:

    WordScrambleController controller;
    Fl_Text_Buffer* highScoresTextBuffer;
    Fl_Text_Display* highScoresTextDisplay;

public:
    /**
    * Creates a new high score window
    * @precondition none
    * @postcondition the window is created
    * @param scoreDisplay The formatted output of scores to display
    */
    HighScoreWindow(const string& scoreDisplay);

    /**
    * Destructs the high score window
    */
    virtual ~HighScoreWindow();

    /**
    * Handles the ok click event
    * @precondition none
    * @postcondition the event is handled
    */
    void okHandler();

    /**
    * Handles the cancel click event
    * @precondition none
    * @postcondition the event is handled
    */
    void cancelHandler();

};

}

#endif // HIGHSCOREWINDOW_H
