#ifndef EULERIANCIRCUIT
#define EULERIANCIRCUIT

#include "eulerianadapter.cpp"

class EulerianCercuit {
public:
    template<class T>
    static vector<T> getEulerianCircuitVerticies(AbstractDigraph<T>* graph)
    {
        EulerianAdapter<T> euAdapter(graph);
        if(EulerianCercuit::isEulerian(graph))
            return euAdapter.getEulerCircuit();
        else
            return vector<T>();
    }

    template<class T>
    static bool isEulerian(AbstractDigraph<T>* graph)
    {
        EulerianAdapter<T> euAdapter(graph);
        return euAdapter.isEulerianCycle();
    }
};

#endif // EULERIANCIRCUIT

