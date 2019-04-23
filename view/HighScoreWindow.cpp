#include "HighScoreWindow.h"

namespace view
{
HighScoreWindow::HighScoreWindow(const string& scoreDisplay) : OkCancelWindow(330, 215, "High Scores")
{
    begin();

    this->highScoresTextBuffer = new Fl_Text_Buffer();
    this->highScoresTextDisplay = new Fl_Text_Display(5,5,320,160, "");
    this->highScoresTextDisplay->textfont(FL_COURIER);
    this->highScoresTextDisplay->buffer(this->highScoresTextBuffer);

    this->setOKLocation(90, 170);
    this->setCancelLocation(170, 170);

    this->highScoresTextBuffer->text(scoreDisplay.c_str());
    end();
}

HighScoreWindow::~HighScoreWindow()
{
    //dtor
}

void HighScoreWindow::okHandler()
{
    this->hide();

}

void HighScoreWindow::cancelHandler()
{
    this->hide();
}

}
