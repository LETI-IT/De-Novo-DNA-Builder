#ifndef EULERIANCIRCUIT
#define EULERIANCIRCUIT

#include "eulerianadapter.cpp"

// Helpful class that has static method for finding eulerian cycle
class EulerianCercuit {
public:
    // Get items in eulerian cycle
    template<class T>
    static vector<T> getEulerianCircuitVerticies(AbstractDigraph<T>* graph)
    {
        EulerianAdapter<T> euAdapter(graph);
        if(EulerianCercuit::isEulerian(graph))
            return euAdapter.getEulerCircuit();
        else
            return vector<T>();
    }

    // Check whether the graph has eulerian cycle
    template<class T>
    static bool isEulerian(AbstractDigraph<T>* graph)
    {
        EulerianAdapter<T> euAdapter(graph);
        return euAdapter.isEulerianCycle();
    }
};

#endif // EULERIANCIRCUIT

