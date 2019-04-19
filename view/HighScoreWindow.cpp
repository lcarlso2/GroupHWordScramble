#include "HighScoreWindow.h"

namespace view
{
HighScoreWindow::HighScoreWindow() : OkCancelWindow(330, 215, "High Scores")
{
    //ctor
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
