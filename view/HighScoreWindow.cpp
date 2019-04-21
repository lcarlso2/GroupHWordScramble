#include "HighScoreWindow.h"

namespace view
{
HighScoreWindow::HighScoreWindow() : OkCancelWindow(330, 215, "High Scores")
{
    begin();

    this->highScoresTextBuffer = new Fl_Text_Buffer();
    this->highScoresTextDisplay = new Fl_Text_Display(5,5,320,160, "");
    this->highScoresTextDisplay->textfont(FL_COURIER);
    this->highScoresTextDisplay->buffer(this->highScoresTextBuffer);

    this->setOKLocation(90, 170);
    this->setCancelLocation(170, 170);

    string output = this->controller.getFormattedHighScores();
    this->highScoresTextBuffer->text(output.c_str());
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
