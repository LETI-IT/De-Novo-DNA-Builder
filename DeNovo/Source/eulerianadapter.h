#ifndef EULERIANADAPTER_H
#define EULERIANADAPTER_H

#include "abstractdigraph.h"
#include "vector"

/*
 *Check whether input graph is eulerian
 */
template<typename T>
class EulerianAdapter
{
private:
    AbstractDigraph<T>* graph;
    vector<T> eulerianCircuit;
    // Check whether the ghaph is strong connected
    bool isSC();
    void dfsUtil(AbstractDigraph<T> *graph, T verticle, map<T, bool> &visited);
    bool checked;

public:
    EulerianAdapter(AbstractDigraph<T>* graph);
    EulerianAdapter();
    // Check whether the graph has eulerian cycle
    bool isEulerianCycle();
    // Get items in eulerian cycle
    vector<T> getEulerCircuit();

};

#endif // EULERIANADAPTER_H
