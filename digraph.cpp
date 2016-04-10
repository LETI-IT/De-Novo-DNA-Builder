//
// Created by Alexander on 10.04.2016.
//

#include "digraph.h"

digraph::digraph() { }

digraph::~digraph() { }

void digraph::add_link(vertex_type v1, vertex_type v2)
{
    _digraph[v1].push_back(v2);
    _digraph[v2];

    cout << "add vertices: " << v1 << ", " << v2 << endl;
}

void digraph::add_links(istream &stm)
{
    vertex_type v1, v2;
    while (stm >> v1 >> v2)
        add_link(v1, v2);
}

bool digraph::is_linked(vertex_type v1, vertex_type v2) {
    return false;
}

vector<vertex_type> digraph::adjacency(vertex_type v) {
    return std::vector<vertex_type>();
}

bool digraph::is_reach(vertex_type start, vertex_type finish) {
    return false;
}

















