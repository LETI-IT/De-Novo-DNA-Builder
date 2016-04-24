#include "digraph.h"
#include "digraphiterator.h"

template<typename Vertex>
Digraph<Vertex>::Digraph() {}

template<typename Vertex>
Digraph<Vertex>::~Digraph() {}

template<typename Vertex>
void Digraph<Vertex>::add_link(Vertex v1, Vertex v2)
{
    digraph[v1].push_back(v2);
    digraph[v2];

    cout << "add vertices: " << v1 << ", " << v2 << endl;
}

template<typename Vertex>
void Digraph<Vertex>::add_links(istream &stm)
{
    Vertex v1, v2;
    while (stm >> v1 >> v2)
        add_link(v1, v2);
}

template<typename Vertex>
bool Digraph<Vertex>::is_linked(Vertex v1, Vertex v2)
{
    return false;
}

template<typename Vertex>
vector<Vertex> Digraph<Vertex>::adjacency(Vertex v)
{
    return std::vector<Vertex>();
}

template<typename Vertex>
bool Digraph<Vertex>::is_reach(Vertex start, Vertex finish)
{
    return false;
}

template<typename Vertex>
const AbstractIterator<Vertex>& Digraph<Vertex>::iterator()
{
    AbstractIterator<Vertex> * it = new DigraphIterator<Vertex>();
    return *it;
}

template class Digraph<int>;


















