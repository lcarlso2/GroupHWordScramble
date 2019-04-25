#ifndef INPUTNAMEWINDOW_H
#define INPUTNAMEWINDOW_H
#include "OkCancelWindow.h"
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input.H>
#include <string>
using namespace std;

namespace view
{

/**
* The input name window that allows the user to enter their name for their score after a game
* @author Lucas Carlson and Carson Bedrosian
* @version 4/19/2019
*/
class InputNameWindow : public OkCancelWindow
{

private:

    Fl_Input *input;

public:

    /**
    * Creates a new input name window
    * @precondition none
    * @postcondition the window is created
    */
    InputNameWindow();

    /**
    * Destructs the high score window
    */
    virtual ~InputNameWindow();

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

    /**
    * Returns the name entered in the text box
    * @precondition none
    * @postcondition none
    * @return Returns the name entered in the text box
    */
    string getName();

};

}

#endif // INPUTNAMEWINDOW_H
