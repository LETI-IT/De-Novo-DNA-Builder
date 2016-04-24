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
    vector<Vertex> neighbors = adjacency(v1);
    for (typename vector<Vertex>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
    {
        if (v2 == *it) return true;
    }
    return false;
}

template<typename Vertex>
vector<Vertex> Digraph<Vertex>::adjacency(Vertex v)
{
    return digraph[v];
}

template<typename Vertex>
bool Digraph<Vertex>::is_reach(Vertex start, Vertex finish)
{
    if (start == finish) return true;

    vector<Vertex> neighbors = adjacency(start);
    queue<Vertex> achievable;

    fill_achievable(neighbors, achievable);

    while (!achievable.empty())
    {
        Vertex v = achievable.front();
        achievable.pop();
        if (finish == v) return true;
        else
        {
            vector<Vertex> neighbors = adjacency(v);
            fill_achievable(neighbors, achievable);
        }
    }
    return false;
}

template<typename Vertex>
const AbstractIterator<Vertex>& Digraph<Vertex>::iterator()
{
    AbstractIterator<Vertex> * it = new DigraphIterator<Vertex>();
    return *it;
}

template<typename Vertex>
void Digraph<Vertex>::fill_achievable(vector<Vertex> &v, queue<Vertex> &q)
{
    for (typename vector<Vertex>::iterator it = v.begin(); it != v.end(); ++it)
    {
        q.push(*it);
    }
}

template class Digraph<int>;


















