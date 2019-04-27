#include "OkCancelWindow.h"

namespace view
{


OkCancelWindow::OkCancelWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    this->buttonInvoked = WindowResult::NONE;

    begin();

    this->okButton = new Fl_Button(0, 0, 70, 30, "Ok");
    this->okButton->callback(cbOk, this);

    this->cancelButton = new Fl_Button(0, 0, 70, 30, "Cancel");
    this->cancelButton->callback(cbCancel, this);

    end();

}


void OkCancelWindow::cbOk(Fl_Widget* widget, void* data)
{
    OkCancelWindow* window = (OkCancelWindow*)data;
    window->setWindowResult(OkCancelWindow::OK);
    window->okHandler();
}


void OkCancelWindow::cbCancel(Fl_Widget* widget, void* data)
{
    OkCancelWindow* window = (OkCancelWindow*)data;
    window->setWindowResult(OkCancelWindow::CANCEL);
    window->cancelHandler();
}


void OkCancelWindow::setOKLocation(int x, int y)
{
    this->okButton->position(x, y);
}


void OkCancelWindow::setCancelLocation(int x, int y)
{
    this->cancelButton->position(x, y);
}


OkCancelWindow::WindowResult OkCancelWindow::setWindowResult(OkCancelWindow::WindowResult result)
{
    this->buttonInvoked = result;
}



OkCancelWindow::WindowResult OkCancelWindow::getWindowResult()
{
    return this->buttonInvoked;
}


OkCancelWindow::~OkCancelWindow()
{
    delete this->okButton;
    delete this->cancelButton;
}

}
