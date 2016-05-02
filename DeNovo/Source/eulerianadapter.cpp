#include "eulerianadapter.h"
#include "vertex.h"
#include "abstractiterator.h"

template<class T>
EulerianAdapter<T>::EulerianAdapter() {
    checked = false;
}

template<typename T>
EulerianAdapter<T>::EulerianAdapter(AbstractDigraph<T> *graph)
{
    this->graph = graph;
    checked = false;
}

template<typename T>
bool EulerianAdapter<T>::isEulerianCycle()
{
    //Check if all non-zero degree vertices are connected
    if (isSC() == false)
        return false;

    // Check if in degree and out degree of every vertex is same
    for(AbstractIterator<T> *it = graph->begin(VERTEX); **it != **graph->end(VERTEX); ++*it)
    {
        Vertex<T>& vertex = static_cast<Vertex<T>&>(**it);
        if(graph->in_degree(vertex.get_value()) != graph->out_degree(vertex.get_value()))
            return false;
    }
    return true;
}

template<typename T>
vector<T> EulerianAdapter<T>::getEulerCircuit()
{
    if(isEulerianCycle()){
        return this->eulerianCircuit;
    }
}

template<typename T>
void EulerianAdapter<T>::dfsUtil(AbstractDigraph<T>* graph, T verticle, map<T, bool>& visited)
{
    visited[verticle] = true;
    vector<T> adjVerticles = graph->adjacency(verticle);
    typename vector<T>::iterator it;
    for (it = adjVerticles.begin(); it != adjVerticles.end(); ++it) {
        if(!checked)
            this->eulerianCircuit.push_back(verticle);
        if (!visited[*it])
            dfsUtil(graph, *it, visited);
    }
}

template<typename T>
bool EulerianAdapter<T>::isSC()
{
    map<T, bool> visited;
    for(AbstractIterator<T> *it = graph->begin(VERTEX); **it != **graph->end(VERTEX); ++*it)
    {
       Vertex<T>& vertex = static_cast<Vertex<T>&>(**it);
       visited[vertex.get_value()] = false;
    }

    // Find the first vertex with non-zero degree
    Vertex<T> temp;
    Vertex<T>& nonZeroVert = temp;
    for(AbstractIterator<T> *it = graph->begin(VERTEX); **it != **graph->end(VERTEX); ++*it)
    {
        nonZeroVert = static_cast<Vertex<T>&>(**it);
        if(graph->out_degree(nonZeroVert.get_value()) > 0)
            break;
    }

    dfsUtil(this->graph, nonZeroVert.get_value(), visited);
    this->eulerianCircuit.push_back(nonZeroVert.get_value());
    checked = true;

    for(AbstractIterator<T> *it = graph->begin(VERTEX); **it != **graph->end(VERTEX); ++*it)
    {
        Vertex<T>& vertex = static_cast<Vertex<T>&>(**it);
        if(graph->out_degree(vertex.get_value()) > 0 && visited[vertex.get_value()] == false)
            return false;
    }

    // Create a reversed graph
    AbstractDigraph<T>* gr = this->graph->get_transpose();

    for(AbstractIterator<T> *it = graph->begin(VERTEX); **it != **graph->end(VERTEX); ++*it)
    {
       Vertex<T>& vertex = static_cast<Vertex<T>&>(**it);
       visited[vertex.get_value()] = false;
    }

    dfsUtil(gr, nonZeroVert.get_value(), visited);
    //Delete transposed graph
    delete gr;

    for(AbstractIterator<T> *it = graph->begin(VERTEX); **it != **graph->end(VERTEX); ++*it)
    {
        Vertex<T>& vertex = static_cast<Vertex<T>&>(**it);
        if(graph->out_degree(vertex.get_value()) > 0 && visited[vertex.get_value()] == false)
            return false;
    }

    return true;
}

