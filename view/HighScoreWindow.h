#ifndef HIGHSCOREWINDOW_H
#define HIGHSCOREWINDOW_H

#include "OkCancelWindow.h"

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

public:
    /**
    * Creates a new high score window
    * @precondition none
    * @postcondition the window is created
    */
    HighScoreWindow();

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
