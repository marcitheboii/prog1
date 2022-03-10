/*
    g++ Function_graping.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Function_graping `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x) {return 1; }
double slope(double x) {return x/2; }
double square(double x) {return x*x; }
double sloping_cos(double x) {return cos(x)+slope(x); }

int main(){

	int xmax = 600;
	int ymax = 600;

	int xori = xmax / 2;
	int yori = ymax / 2;

	int xscale = 20;
	int yscale = 20;

	Simple_window win {Point{100,100},xmax,ymax,"Function graps"};

	int xlen = 400;
	int ylen = 400;

	Axis x {Axis::x, Point{xori-(xlen/2),yori}, xlen, xlen/xscale, "1 == 20 pixels"};
	Axis y {Axis::y, Point{xori,yori+(ylen/2)}, ylen, ylen/yscale, "1 == 20 pixels"};

	x.set_color(Color::red);
	y.set_color(Color::red);

	Point origo {xori,yori};

	int rmin = -10;
	int rmax = 11;

	int n_points = 400;

	Function con (one, rmin, rmax, origo, n_points, yscale);
	Function slash (slope, rmin, rmax, origo, n_points, yscale);
	Function sqr (square, rmin, rmax, origo, n_points, yscale);
	Function cosn (cos, rmin, rmax, origo, n_points, xscale, yscale);
	Function slop_cos (sloping_cos, rmin, rmax, origo, n_points, xscale, yscale);

	cosn.set_color(Color::blue);

	Text t {Point{100,410}, "x/2"};

	win.attach(x);
    win.attach(y);
    win.attach(con);
    win.attach(slash);
    win.attach(t);
    win.attach(sqr);
    win.attach(cosn);
    win.attach(slop_cos);

   	win.wait_for_button();

	return 0;
}