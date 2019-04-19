#include "MainWindow.h"

#include <iostream>
namespace view
{
MainWindow::MainWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();

    this->startGameButton = new Fl_Button(125,100,125,25, "Start game");
    this->startGameButton->callback(cbStartGame, this);

    this->highScoresButton = new Fl_Button(125,150,125,25,"High Scores");
    this->highScoresButton->callback(cbHighScore, this);

    this->settingsButton = new Fl_Button(125,200,125,25,"Settings");
    this->settingsButton->callback(cbSettings, this);

    this->titleLabel = new Fl_Output(245,50,0,0, "Word Scramble");

    end();
}


void MainWindow::cbStartGame(Fl_Widget* widget, void* data)
{
    MainWindow* window = (MainWindow*)data;
    GameWindow gameWindow(540, 250, "Word Scramble");

    gameWindow.set_modal();
    gameWindow.show();

    while (gameWindow.shown())
    {
        Fl::wait();
    }
    int score = gameWindow.getScore();
}

void MainWindow::cbHighScore(Fl_Widget* widget, void* data)
{
    MainWindow* window = (MainWindow*)data;
    HighScoreWindow scoreWindow;

    scoreWindow.set_modal();
    scoreWindow.show();

    while (scoreWindow.shown())
    {
        Fl::wait();
    }
}

void MainWindow::cbSettings(Fl_Widget* widget, void* data)
{
    MainWindow* window = (MainWindow*)data;
    SettingsWindow settingsWindow;

    settingsWindow.set_modal();
    settingsWindow.show();

    while (settingsWindow.shown())
    {
        Fl::wait();
    }

    if (settingsWindow.getWindowResult() == OkCancelWindow::WindowResult::OK)
    {
        window->resetButtons(settingsWindow.getSelectedNumberOfLetters(), settingsWindow.getSelectedTimer());
    }

}

void MainWindow::resetButtons(const int numberOfLetters, const int timer)
{
    this->controller.writeSettingsToFile(numberOfLetters, timer);
}



MainWindow::~MainWindow()
{
    delete this->startGameButton;
    delete this->highScoresButton;
    delete this->settingsButton;
    delete this->titleLabel;
}

}
