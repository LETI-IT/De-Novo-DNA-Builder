#ifndef EULERIANCIRCUIT
#define EULERIANCIRCUIT

#include "eulerianadapter.cpp"

class EulerianCercuit {
public:
    template<class T>
    static vector<T> getEulerianCircuitVerticies(AbstractDigraph<T>* graph)
    {
        EulerianAdapter<T> euAdapter(graph);
        return euAdapter.getEulerCircuit();
    }

    template<class T>
    static bool isEulerian(AbstractDigraph<T>* graph)
    {
        EulerianAdapter<T> euAdapter(graph);
        return euAdapter.isEulerianCycle();
    }
};

#endif // EULERIANCIRCUIT

