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
    GameWindow gameWindow(540, 300, "Word Scramble");

    gameWindow.set_modal();
    gameWindow.show();

    while (gameWindow.shown())
    {
        Fl::wait();
    }

    int score = gameWindow.getScore();
    string timerValue = gameWindow.getTimer();
    int time = timeToInt(timerValue);

    if(gameWindow.getShouldUserEnterName())
    {
        string name = window->showInputNameWindow();
        window->addNewScore(name, score, time);
    }
}

void MainWindow::cbHighScore(Fl_Widget* widget, void* data)
{
    MainWindow* window = (MainWindow*)data;
    string scores = window->getHighScores();
    WordScrambleController controller = window->getCopyOfController();
    HighScoreWindow scoreWindow(scores, controller);
    scoreWindow.set_modal();
    scoreWindow.show();

    while (scoreWindow.shown())
    {
        Fl::wait();
    }
}

WordScrambleController MainWindow::getCopyOfController()
{
    return this->controller;
}

string MainWindow::showInputNameWindow()
{
    InputNameWindow nameWindow;
    nameWindow.set_modal();
    nameWindow.show();

    while (nameWindow.shown())
    {
        Fl::wait();
    }
    string name = nameWindow.getName();
    return name;
}

string MainWindow::getHighScores()
{
    return this->controller.getHighScores(DEFAULT_NUMBER_OF_SCORES);
}

void MainWindow::cbSettings(Fl_Widget* widget, void* data)
{
    MainWindow* window = (MainWindow*)data;
    SettingsWindow settingsWindow(window->getTimerCount(), window->getButtonCount());

    settingsWindow.set_modal();
    settingsWindow.show();

    while (settingsWindow.shown())
    {
        Fl::wait();
    }

    if (settingsWindow.getWindowResult() == OkCancelWindow::WindowResult::OK)
    {
        window->updateSettings(settingsWindow.getSelectedButtonCount(), settingsWindow.getSelectedTimerCount());
    }
}

void MainWindow::updateSettings(const int buttonCount, const int timer)
{
    this->controller.setButtonCount(buttonCount);
    this->controller.setTimerCount(timer);
    this->controller.writeSettingsToFile();
}

int MainWindow::getTimerCount()
{
    return this->controller.getTimerCount();
}

int MainWindow::getButtonCount()
{
    this->controller.getButtonCount();
}

inline void MainWindow::addNewScore(const string& name, int score, int time)
{
    int allottedTime = this->controller.calculateAllottedTime(time);
    this->controller.addNewScore(name, score, allottedTime);
    this->controller.writeScoresToFile();
}

MainWindow::~MainWindow()
{
    delete this->startGameButton;
    delete this->highScoresButton;
    delete this->settingsButton;
    delete this->titleLabel;
}

}
