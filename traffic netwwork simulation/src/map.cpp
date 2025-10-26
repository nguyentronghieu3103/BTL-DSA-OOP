#include "map.hpp"
#include "coord.hpp"
#include <iostream>
using namespace std;


//ham dung -------------------
map::map(){}

void map::add_node(unique_ptr<node> n){
    nodes.push_back(move(n));
}

void map::add_edge(unique_ptr<edge> e){
	edges.push_back(move(e));
}


//ham phuong thuc -----------------------
void map::show_all() const{
    cout << "\nDanh sach cac node:\n";
    for (const auto& n : nodes){
        n->display();
    }
    
    cout << "\nDanh sach cac edge:\n";
    for (const auto& e : edges){
        e->display();
    }
}

node* map::get_node(int id) const {
	for (const auto& n : nodes){
		if(n->get_id() == id)	return n.get();
	}
	return NULL;
}

void map::add_edge_by_id(string n, int i, int id_src, int id_dest, bool dir){
	node* node_src = get_node(id_src);
	node* node_dest = get_node(id_dest);
	
	if( node_src == nullptr || node_dest == nullptr){
        cout << "Loi: Khong the them Edge " << n << " vi thieu Node sau: ";
        if (node_src == NULL){
            cout << "Node nguon ID " << id_src;
            if (node_dest == NULL) cout << " va ";
        }
        if (node_dest == NULL){
            cout << "Node dich ID " << id_dest;
        }
        cout << ".\n";
		return;
	}
	
	double distance = node_src->get_coord().distance(node_dest->get_coord());
	//dung unique ptr nen new edge auto huy
	unique_ptr<edge> e(new edge(n, i, id_src, id_dest, distance, dir));
	
	edges.push_back(move(e));
}
