#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>

namespace view {
class MainWindow : public Fl_Window
{

    private:
        static const int DEFAULT_NUMBER_OF_BUTTONS = 6;

        Fl_Output *sortingOutputLabel;
        Fl_Group *letterSelectionButtonGroup;


        Fl_Button* letterSelectionButtonGroupButton[DEFAULT_NUMBER_OF_BUTTONS];

    public:
        MainWindow();

        virtual ~MainWindow();

};
}

#endif // MAINWINDOW_H
