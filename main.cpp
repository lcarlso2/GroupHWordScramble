#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <iostream>
using namespace std;

#include "MainWindow.h"
using namespace view;

#include "Utils.h"

int main (int argc, char ** argv)
{
    MainWindow mainWindow(400, 300, "Word Scramble by Carson Bedrosian and Lucas Carlson");
    mainWindow.show();

    string abc = "ABC";
    permute(3, abc);

    int exitCode = Fl::run();
    return exitCode;
}
