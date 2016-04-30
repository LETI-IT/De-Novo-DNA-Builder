#include "digraph.h"

template<class T>
Digraph<T>::Digraph() {}

template<class T>
Digraph<T>::~Digraph() {}

template<class T>
void Digraph<T>::add_link(T v1, T v2)
{
    digraph[v1].push_back(v2);
    digraph[v2];

    cout << "add vertices: " << v1 << ", " << v2 << endl;
}

template<class T>
void Digraph<T>::add_links(istream &stm)
{
    T v1, v2;
    while (stm >> v1 >> v2)
        add_link(v1, v2);
}

template<class T>
bool Digraph<T>::is_linked(T v1, T v2)
{
    vector<T> neighbors = adjacency(v1);
    for (typename vector<T>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
    {
        if (v2 == *it) return true;
    }
    return false;
}

template<class T>
vector<T> Digraph<T>::adjacency(T v)
{
    return digraph[v];
}

template<class T>
bool Digraph<T>::is_reach(T start, T finish)
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


template<class T>
void Digraph<T>::fill_achievable(vector<T> &v, queue<T> &q)
{
    for (typename vector<T>::iterator it = v.begin(); it != v.end(); ++it)
    {
        q.push(*it);
    }
}

template<class T>
AbstractIterator<T>* Digraph<T>::begin(TypeIterator type)
{
    switch(type)
    {
    case VERTEX:
        //cout << "VERTEX ITERATOR" << endl;
        return new VertexIterator<T>(&digraph, false);

    case EDGE:
        //cout << "EDGE ITERATOR" << endl;
        return new EdgeIterator<T>(&digraph, false);
    };

}

template<class T>
AbstractIterator<T>* Digraph<T>::end(TypeIterator type)
{
    switch(type)
    {
    case VERTEX:
        //cout << "VERTEX ITERATOR" << endl;
        return new VertexIterator<T>(&digraph, true);

    case EDGE:
        //cout << "EDGE ITERATOR" << endl;
        return new EdgeIterator<T>(&digraph, true);
    };
}


template class Digraph<int>;


















