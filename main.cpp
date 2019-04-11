#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <iostream>
using namespace std;

int main (int argc, char ** argv)
{
  Fl_Window *window;
  Fl_Box *box;

  window = new Fl_Window (300, 180);
  box = new Fl_Box (20, 40, 260, 100, "Hello World!");

  box->box (FL_UP_BOX);
  box->labelsize (36);
  box->labelfont (FL_BOLD+FL_ITALIC);
  box->labeltype (FL_SHADOW_LABEL);
  window->end ();
  window->show (argc, argv);

  cout << "TEST broken" << endl;

  return(Fl::run());
}
