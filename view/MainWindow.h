#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "Controller.h"
using namespace controller;

namespace view {
class MainWindow : public Fl_Window
{

    private:
        static const int DEFAULT_NUMBER_OF_BUTTONS = 6;
        vector<string> letters;

        string* lettersBeingDisplayed[DEFAULT_NUMBER_OF_BUTTONS];

        Fl_Round_Button* letterSelectionRadioButton[DEFAULT_NUMBER_OF_BUTTONS];

        Fl_Text_Buffer *lettersChosenTextBuffer;
        Fl_Text_Display *lettersChosenTextDisplay;

        static void cbLetterSelected(Fl_Widget* widget, void* data);
        inline void letterSelected(Fl_Widget* widget);

        void displayLettersSelected();

        void createAndDisplayLetterSelection(vector<string> letters);

        void deleteButtons();

        void replaceLettersBeingDisplayed(vector<string> newLetters);

        vector<Fl_Widget*> orderOfButtonsSelected;

        Controller controller;

        Fl_Button* shuffleButton;
        Fl_Button* newLettersButton;

        static void cbShuffleLetters(Fl_Widget* widget, void* data);
        static void cbNewLetters(Fl_Widget* widget, void* data);

        inline void shuffleLetters();
        inline void getNewLetters();

    public:
        MainWindow(int width, int height, const char* title);

        virtual ~MainWindow();

};
}

#endif // MAINWINDOW_H
