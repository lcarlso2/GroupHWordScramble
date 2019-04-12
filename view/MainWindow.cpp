#include "MainWindow.h"


namespace view
{
MainWindow::MainWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();

    createAndDisplayLetterSelection();

    this->lettersChosenTextBuffer = new Fl_Text_Buffer();
    this->lettersChosenTextDisplay = new Fl_Text_Display(180, 270, 180, 25, "");
    this->lettersChosenTextDisplay->textfont(FL_COURIER);
    this->lettersChosenTextDisplay->buffer(lettersChosenTextBuffer);

   this->controller.getLettersToDisplay();


    end();
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < DEFAULT_NUMBER_OF_BUTTONS; i ++)
    {
        delete this->letterSelectionRadioButton[i];
    }
    this->lettersChosenTextDisplay->buffer(0);
    delete this->lettersChosenTextBuffer;
    delete this->lettersChosenTextDisplay;
}

void MainWindow::createAndDisplayLetterSelection()
{
    for (int i = 0; i < DEFAULT_NUMBER_OF_BUTTONS; i ++)
    {
        this->letterSelectionRadioButton[i] = new Fl_Round_Button(i*85+45, 300, 50, 25, "A");
        this->letterSelectionRadioButton[i]->callback(cbLetterSelected, this);
    }
}

void MainWindow::cbLetterSelected(Fl_Widget* widget, void* data)
{
    MainWindow* window = (MainWindow*)data;
    window->letterSelected();
}

void MainWindow::letterSelected()
{
    this->displayLettersSelected();
}

void MainWindow::displayLettersSelected()
{
    string wordToDisplay = "";
    for (int i = 0; i < DEFAULT_NUMBER_OF_BUTTONS; i ++)
    {
        if (this->letterSelectionRadioButton[i]->value())
        {
            wordToDisplay += this->letterSelectionRadioButton[i]->label();
        }
    }
    this->lettersChosenTextBuffer->text(wordToDisplay.c_str());

}




}
