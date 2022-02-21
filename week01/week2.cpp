/*
    g++ week2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o week2 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

    int xgrid = 100;
    int ygrid = 100;

    int xgridborder = 800;
    int ygridborder = 800;

    Lines grid;
    for(int x=xgrid; x<=xgridborder; x+=xgrid)
    	grid.add(Point{x,0},Point{x,xgridborder});
    for(int y=ygrid; y<=ygridborder; y+=ygrid)
    	grid.add(Point{0,y},Point{ygridborder,y});

    win.attach(grid);

    Vector_ref<Rectangle> rec;

    for(int p=0;p<xgridborder; p+=100) {
    	rec.push_back(new Rectangle{Point(p,p),100,100});
    	rec[rec.size()-1].set_fill_color(Color::red);
    	win.attach(rec[rec.size()-1]);

    }

    Image pic1 {Point{300,0},"popeye.jpg"};
    Image pic2 {Point{500,300},"popeye.jpg"};
    Image pic3 {Point{100,500},"popeye.jpg"};

    win.attach(pic1);
    win.attach(pic2);
    win.attach(pic3);

    while(true){
    	for(int i=0;i<=700;i+=100){
    		for(int j=0;j<=700;j+=100){
    			Image pac {Point{j,i},"pacman.jpg"};
    			win.attach(pac);
    			win.wait_for_button();

    		}
    	}
    break;
    }

}