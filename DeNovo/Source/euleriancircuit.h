#ifndef EULERIANCIRCUIT
#define EULERIANCIRCUIT

#include "igraph.h"

class EulerianCercuit {
    template<class Vertex>
    static AbstractIterator<Vertex> getEulerianCircuitVerticies(IGraph<Vertex> graph);

    template<class Vertex>
    static bool isEulerian(IGraph<Vertex> graph);
};

#endif // EULERIANCIRCUIT

