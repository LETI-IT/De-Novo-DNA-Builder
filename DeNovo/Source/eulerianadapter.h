#ifndef EULERIANADAPTER_H
#define EULERIANADAPTER_H

#include "abstractdigraph.h"
#include "vector"

template<typename T>
class EulerianAdapter
{
private:
    AbstractDigraph<T>* graph;
    vector<T> eulerianCircuit;
    bool isSC();
    void dfsUtil(AbstractDigraph<T> *graph, T verticle, map<T, bool> &visited);
    bool checked;

public:
    EulerianAdapter(AbstractDigraph<T>* graph);
    EulerianAdapter();
    bool isEulerianCycle();
    vector<T> getEulerCircuit();

};

#endif // EULERIANADAPTER_H
