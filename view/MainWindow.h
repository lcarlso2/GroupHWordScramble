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
using namespace std;

namespace view {
class MainWindow : public Fl_Window
{

    private:
        static const int DEFAULT_NUMBER_OF_BUTTONS = 6;

        Fl_Output *sortingOutputLabel;
        Fl_Group *letterSelectionButtonGroup;


        Fl_Round_Button* letterSelectionRadioButton[DEFAULT_NUMBER_OF_BUTTONS];

        Fl_Text_Buffer *lettersChosenTextBuffer;
        Fl_Text_Display *lettersChosenTextDisplay;

        static void cbLetterSelected(Fl_Widget* widget, void* data);
        inline void letterSelected();

        void displayLettersSelected();


        void createAndDisplayLetterSelection();

    public:
        MainWindow(int width, int height, const char* title);

        virtual ~MainWindow();

};
}

#endif // MAINWINDOW_H
