#include "InputNameWindow.h"
namespace view
{


InputNameWindow::InputNameWindow() : OkCancelWindow(330, 175, "Enter your name for the score board")
{
    begin();
    input = new Fl_Input(100, 50, 125, 30, "Enter Name:");
    this->setOKLocation(90, 125);
    this->setCancelLocation(170, 125);
    end();
}

InputNameWindow::~InputNameWindow()
{
    //dtor
}


void InputNameWindow::okHandler()
{
    this->hide();

}

void InputNameWindow::cancelHandler()
{
    this->input->value("");
    this->hide();
}

string InputNameWindow::getName()
{
    return this->input->value();
}

}
