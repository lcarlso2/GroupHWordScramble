#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include "Utils.h"
#include <iostream>
#include <string>
using namespace std;
#include "MainWindow.h"
using namespace view;


int main (int argc, char ** argv)
{
    MainWindow mainWindow(400, 300, "Word Scramble by Carson Bedrosian and Lucas Carlson");
    mainWindow.show();
   // string abc = "ABC";
    //combinationEasy(abc);
    //char set1[] = {'a', 'a' ,'c'};

    string test = "AAD";
   // cout << (test.find('a') != string::npos) << endl;
    //cout <<  "TEST" << endl;
   // cout << set1 << endl;
    //cout << "end" << endl;
    printAllKLength(test.c_str(), 3, 3);
    int exitCode = Fl::run();
    return exitCode;
}
