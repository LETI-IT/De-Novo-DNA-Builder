#include "eulerianadapter.h"
#include "vertex.h"
#include "vertexiterator.h"

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
    for(AbstractIterator<T> *it = graph->begin(VERTEX); *it != &*graph->end(VERTEX); ++*it)
    {
        Vertex<T>& vertex = static_cast<Vertex<T>&>(**it);
        if(graph->in_degree(vertex.getValue()) != graph->out_degree(vertex.getValue()))
            return false;
    }
    return true;
}

template<typename T>
vector<T> EulerianAdapter<T>::getEulerCircuit()
{
    if(isEulerianCycle()){
        return this->eulerianCircuit;
    } else
        return vector<T>();
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
    for(AbstractIterator<T> *it = graph->begin(VERTEX); *it != &*graph->end(VERTEX); ++*it)
    {
       Vertex<T>& vertex = static_cast<Vertex<T>&>(**it);
       visited[vertex.getValue()] = false;
    }

    // Find the first vertex with non-zero degree
    Vertex<T> temp;
    Vertex<T>& nonZeroVert = temp;
    for(AbstractIterator<T> *it = graph->begin(VERTEX); *it != &*graph->end(VERTEX); ++*it)
    {
        nonZeroVert = static_cast<Vertex<T>&>(**it);
        if(graph->out_degree(nonZeroVert.getValue()) > 0)
            break;
    }

    dfsUtil(this->graph, nonZeroVert.getValue(), visited);
    this->eulerianCircuit.push_back(nonZeroVert.getValue());
    checked = true;

    for(AbstractIterator<T> *it = graph->begin(VERTEX); *it != &*graph->end(VERTEX); ++*it)
    {
        Vertex<T>& vertex = static_cast<Vertex<T>&>(**it);
        if(graph->out_degree(vertex.getValue()) > 0 && visited[vertex.getValue()] == false)
            return false;
    }

    // Create a reversed graph
    AbstractDigraph<T>* gr = this->graph->get_transpose();
    for(AbstractIterator<T> *it = graph->begin(VERTEX); *it != &*graph->end(VERTEX); ++*it)
    {
       Vertex<T>& vertex = static_cast<Vertex<T>&>(**it);
       visited[vertex.getValue()] = false;
    }

    dfsUtil(gr, nonZeroVert.getValue(), visited);
    //Delete transposed graph
    delete gr;
    for(AbstractIterator<T> *it = graph->begin(VERTEX); *it != &*graph->end(VERTEX); ++*it)
    {
        Vertex<T>& vertex = static_cast<Vertex<T>&>(**it);
        if(graph->out_degree(vertex.getValue()) > 0 && visited[vertex.getValue()] == false)
            return false;
    }

    return true;
}

