#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Window {
Lines_window(Point xy, int w, int h, const string& title);
private:
// data:
Open_polyline lines;
// widgets:
Button next_button; // add (next_x,next_y) to lines
Button quit_button; // end program
In_box next_x;
In_box next_y;
Out_box xy_out;
Menu color_menu;
Menu lstyle_menu;
Button menu_button;
Button menu2_button;
void change(Color c) { lines.set_color(c); }
void changelstyle(Line_style ls) { lines.set_style(ls); }
void hide_menu() { color_menu.hide(); menu_button.show(); menu2_button.show(); }// actions invoked by callbacks:
void hide2_menu() { lstyle_menu.hide(); menu_button.show(); menu2_button.show(); }
void red_pressed() { change(Color::red); hide_menu(); }
void blue_pressed() { change(Color::blue); hide_menu(); }
void black_pressed() { change(Color::black); hide_menu(); }
void menu_pressed() { menu_button.hide(); menu2_button.hide(); color_menu.show(); }
void solid_pressed() { changelstyle(Line_style::solid); hide2_menu(); }
void dash_pressed() { changelstyle(Line_style::dash); hide2_menu(); }
void dot_pressed() { changelstyle(Line_style::dot); hide2_menu(); }
void dashdot_pressed() { changelstyle(Line_style::dashdot); hide2_menu(); }
void dashdotdot_pressed() { changelstyle(Line_style::dashdotdot); hide2_menu(); }
void menu2_pressed() { menu_button.hide(); menu2_button.hide(); lstyle_menu.show(); }
void next();
void quit();
// callback functions:
static void cb_red(Address, Address);
static void cb_blue(Address, Address);
static void cb_black(Address, Address);
static void cb_menu(Address, Address);
static void cb_solid(Address, Address);
static void cb_dash(Address, Address);
static void cb_dot(Address, Address);
static void cb_dashdot(Address, Address);
static void cb_dashdotdot(Address, Address);
static void cb_menu2(Address, Address);
static void cb_next(Address, Address);
static void cb_quit(Address, Address);
};
