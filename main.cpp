#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include "Utils.h"
#include <iostream>

#include "MainWindow.h"
using namespace view;


int main (int argc, char ** argv)
{
    MainWindow mainWindow(400, 300, "Word Scramble by Carson Bedrosian and Lucas Carlson");
    mainWindow.show();
    string abc = "ABC";
    combinationEasy(abc);
    int exitCode = Fl::run();
    return exitCode;
}
