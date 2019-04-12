#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <iostream>
using namespace std;

#include "MainWindow.h"
using namespace view;

int main (int argc, char ** argv)
{


    MainWindow mainWindow(540, 250, "Word Scramble by Carson Bedrosian and Lucas Carlson");
    mainWindow.show();
    int exitCode = Fl::run();
    return exitCode;

}
