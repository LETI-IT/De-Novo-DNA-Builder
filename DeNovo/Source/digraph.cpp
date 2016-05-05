#include "digraph.h"

template<class T, class Allocator>
Digraph<T, Allocator>::Digraph() {}

template<class T, class Allocator>
Digraph<T, Allocator>::~Digraph() {}

template<class T, class Allocator>
void Digraph<T, Allocator>::add_link(T v1, T v2)
{
    digraph[v1].push_back(v2);
    digraph[v2];
    if(in_deg.find(v2) == in_deg.end()) {
         in_deg[v2]=1;
    }
    else {
        in_deg[v2]++;
    }

    if(out_deg.find(v1) == out_deg.end()) {
        out_deg[v1]=1;
    }
    else {
        out_deg[v1]++;
    }

    cout << "add vertices: " << v1 << ", " << v2 << endl;
}

template<class T, class Allocator>
void Digraph<T, Allocator>::add_links(istream &stm)
{
    T v1, v2;
    while (stm >> v1 >> v2)
        add_link(v1, v2);
}

template<class T, class Allocator>
bool Digraph<T, Allocator>::is_linked(T v1, T v2)
{
    vector<T> neighbors = adjacency(v1);
    for (typename vector<T>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
    {
        if (v2 == *it) return true;
    }
    return false;
}

template<class T, class Allocator>
vector<T> Digraph<T, Allocator>::adjacency(T v)
{
    return digraph[v];
}

template<class T, class Allocator>
int Digraph<T, Allocator>::in_degree(T v)
{
    return in_deg[v];
}

template<class T, class Allocator>
int Digraph<T, Allocator>::out_degree(T v)
{
    return out_deg[v];
}

template<class T, class Allocator>
AbstractDigraph<T, Allocator> *Digraph<T, Allocator>::get_transpose()
{
    AbstractDigraph<T, Allocator>* tr_graph = new Digraph<T, Allocator>();
    for(AbstractIterator<T> *v = begin(VERTEX); **v != **end(VERTEX); ++*v)
    {
        Vertex<T>& verticle = static_cast<Vertex<T>&>(**v);
        vector<T> adjVerticles = adjacency(verticle.getValue());
        typename vector<T>::iterator it;
        for (it = adjVerticles.begin(); it != adjVerticles.end(); ++it) {
            tr_graph->add_link(*it, verticle.getValue());
        }
    }

    return tr_graph;
}


template<class T, class Allocator>
bool Digraph<T, Allocator>::is_reach(T start, T finish)
{
    if (start == finish) return true;

    vector<T> neighbors = adjacency(start);
    queue<T> achievable;

    fill_achievable(neighbors, achievable);

    while (!achievable.empty())
    {
        T v = achievable.front();
        achievable.pop();
        if (finish == v) return true;
        else
        {
            vector<T> neighbors = adjacency(v);
            fill_achievable(neighbors, achievable);
        }
    }
    return false;
}


template<class T, class Allocator>
void Digraph<T, Allocator>::fill_achievable(vector<T> &v, queue<T> &q)
{
    for (typename vector<T>::iterator it = v.begin(); it != v.end(); ++it)
    {
        q.push(*it);
    }
}

template<class T, class Allocator>
AbstractIterator<T>* Digraph<T, Allocator>::begin(TypeIterator type)
{
    switch(type)
    {
    case VERTEX:
        return new VertexIterator<T>(&digraph, false);

    case EDGE:
        return new EdgeIterator<T>(&digraph, false);
    };

}

template<class T, class Allocator>
AbstractIterator<T>* Digraph<T, Allocator>::end(TypeIterator type)
{
    switch(type)
    {
    case VERTEX:
        return new VertexIterator<T>(&digraph, true);

    case EDGE:
        return new EdgeIterator<T>(&digraph, true);
    };
}


template class Digraph<int>;


















