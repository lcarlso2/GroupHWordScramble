#ifndef OKCANCELWINDOW_H
#define OKCANCELWINDOW_H

#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>

namespace view
{

//
// Abstract class that can be used for any window that needs Ok and Cancel buttons on it.
//
class OkCancelWindow : public Fl_Window
{
public:
    enum WindowResult {OK, CANCEL, NONE};

private:
    Fl_Button* okButton;
    Fl_Button* cancelButton;

    WindowResult buttonInvoked;

public:
    //
    // Constructs a ok/cancel window creating and initializing all the widgets taht will be displayed
    //
    // @precondition width > 0 AND height > 0
    // @postcondition none
    //
    // @param width The width of the window
    // @param height The height of the window
    // @param title The title to display for the window
    //
    OkCancelWindow(int width, int height, const char* title);

    //
    // Destructor that cleans up all allocated resources for the window
    //
    virtual ~OkCancelWindow();

    //
    // Sets the (x,y) location of the OK button
    //
    // @precondition none
    // @postcondition none
    //
    void setOKLocation(int x, int y);

    //
    // Sets the (x,y) location of the Cancel button
    //
    // @precondition none
    // @postcondition none
    //
    void setCancelLocation(int x, int y);

    //
    // The handler when OK is invoked
    //
    // @precondition widget != 0 AND data != 0
    // @postcondition getWindowResult() == OkCancelWindow::OK
    //
    static void cbOk(Fl_Widget* widget, void* data);
    virtual void okHandler() = 0;

    //
    // The handler when Cancel is invoked
    //
    // @precondition widget != 0 AND data != 0
    // @postcondition getWindowResult() == OkCancelWindow::CANCEL
    //
    static void cbCancel(Fl_Widget* widget, void* data);
    virtual void cancelHandler() = 0;

    //
    // Sets the WindowResult which indicates how the window was closed via OK or Cancel button or X'd out.
    //
    // @precondition none
    // @postcondition none
    //
    // @param result The window result
    //
    OkCancelWindow::WindowResult setWindowResult(OkCancelWindow::WindowResult result);

    //
    // Gets the sort window result which indicates how the window was closed via OK or Cancel button or X'd out.
    //
    // @precondition none
    // @postcondition none
    //
    // @return The window result of how the window was closed
    //
    OkCancelWindow::WindowResult getWindowResult();
};

}

#endif // OKCANCELWINDOW_H
