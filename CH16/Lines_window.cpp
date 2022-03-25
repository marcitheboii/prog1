#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
:Window{xy,w,h,title}, 
next_button{Point{x_max()-150,0}, 70, 20, "Next point", cb_next}, 
quit_button{Point{x_max()-70,0}, 70, 20, "Quit", cb_quit}, 
next_x{Point{x_max()-310,0}, 50, 20, "next x:"}, 
next_y{Point{x_max()-210,0}, 50, 20, "next y:"}, 
xy_out{Point{100,0}, 100, 20, "current (x,y):"}, 
color_menu{Point{x_max()-70,30},70,20,Menu::vertical,"color"}, 
lstyle_menu{Point{x_max()-70,30},70,20,Menu::vertical,"lstyle"}, 
menu_button{Point{x_max()-80,30}, 80, 20, "color menu", cb_menu}, 
menu2_button{Point{x_max()-80,50}, 80, 20, "lstyle menu", cb_menu2}
{
attach(next_button);
attach(quit_button);
attach(next_x);
attach(next_y);
attach(xy_out);
xy_out.put("no point");
color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
attach(color_menu);
color_menu.hide();
lstyle_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
lstyle_menu.attach(new Button{Point{0,0},0,0,"dash",cb_dash});
lstyle_menu.attach(new Button{Point{0,0},0,0,"dot",cb_dot});
lstyle_menu.attach(new Button{Point{0,0},0,0,"dashdot",cb_dashdot});
lstyle_menu.attach(new Button{Point{0,0},0,0,"dashdotdot",cb_dashdotdot});
attach(lstyle_menu);
lstyle_menu.hide();
attach(menu_button);
attach(menu2_button);
attach(lines);
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}
    void Lines_window::cb_next(Address, Address pw) { reference_to<Lines_window>(pw).next(); };
    void Lines_window::cb_quit(Address, Address pw) { reference_to<Lines_window>(pw).quit(); };
    void Lines_window::cb_black(Address, Address pw) { reference_to<Lines_window>(pw).black_pressed(); };
    void Lines_window::cb_menu(Address, Address pw) { reference_to<Lines_window>(pw).menu_pressed(); };
    void Lines_window::cb_menu2(Address, Address pw) { reference_to<Lines_window>(pw).menu2_pressed(); };
    void Lines_window::cb_red(Address, Address pw) { reference_to<Lines_window>(pw).red_pressed(); };
    void Lines_window::cb_blue(Address, Address pw) { reference_to<Lines_window>(pw).blue_pressed(); };
    void Lines_window::cb_solid(Address, Address pw) { reference_to<Lines_window>(pw).solid_pressed(); };
    void Lines_window::cb_dash(Address, Address pw) { reference_to<Lines_window>(pw).dash_pressed(); };
    void Lines_window::cb_dot(Address, Address pw) { reference_to<Lines_window>(pw).dot_pressed(); };
    void Lines_window::cb_dashdot(Address, Address pw) { reference_to<Lines_window>(pw).dashdot_pressed(); };
    void Lines_window::cb_dashdotdot(Address, Address pw) { reference_to<Lines_window>(pw).dashdotdot_pressed(); };