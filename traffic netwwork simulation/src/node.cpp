#include "node.hpp"
#include <iostream>
using namespace std;
using namespace map_types;

// Ham dung ----------------
node::node() : name(""), id(0), pos(0, 0){}

node::node(string n, int i, double x_pos, double y_pos)
    : name(n), id(i), pos(x_pos, y_pos){}

//get set ------------------
string node::get_name() const{ return name; }
int node::get_id() const{ return id; }
coord node::get_coord() const { return pos;}
double node::get_x() const{ return pos.x; }
double node::get_y() const{ return pos.y; }

//phuong thuc------------------------
void node::display() const{
    cout << "Node [" << id << "] " << name
         << " (" << pos.x << ", " << pos.y << ")\n";
}

//===================================================
//                    LOP KE THUA 
//===================================================

//=------------------- location ---------------------=
//ham dung ---------------------
location::location(string n, int i, double x_pos, double y_pos, int pop, lo_type t)
    : node(n, i, x_pos, y_pos), population(pop), type(t){}

//phuong thuc --------------------
void location::display() const{
	node::display();
	cout << " - Location type: " << to_string(type) << endl; 
    cout << " - Population: " << population << endl;
}

