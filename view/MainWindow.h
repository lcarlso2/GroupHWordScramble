#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>


#include "OkCancelWindow.h"
#include "SettingsWindow.h"
#include "GameWindow.h"
#include "HighScoreWindow.h"

#include <chrono>
#include <thread>
#include <unistd.h>
using namespace std;

#include "WordScrambleController.h"
using namespace controller;



namespace view
{

/**
* The main window class
* @author Lucas Carlson and Carson Bedrosian
* @version 4/12/2019
*/
class MainWindow : public Fl_Window
{


private:
    WordScrambleController controller;


    Fl_Button* startGameButton;
    Fl_Button* highScoresButton;
    Fl_Button* settingsButton;


    static void cbStartGame(Fl_Widget* widget, void* data);
    static void cbHighScore(Fl_Widget* widget, void* data);
    static void cbSettings(Fl_Widget* widget, void* data);
    static void cbSwitchLabel(Fl_Widget* widget, void* data);

    inline void resetButtons(const int numberOfLetters, const int timer);
    inline string getHighScores();



public:
    /**
    * Creates a new main window object
    * @param width the width of the window
    * @param height the height of the window
    * @param title the title of the window
    * @precondition none
    * @postcondition the window is created
    */
    MainWindow(int width, int height, const char* title);

    /**
    * Destructs the main window object
    */
    virtual ~MainWindow();

    inline void switchLabel();

    Fl_Output* titleLabel;

};
}

#endif // MAINWINDOW_H
