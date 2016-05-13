#ifndef DEBROJINGRAPHGENERATOR_H
#define DEBROJINGRAPHGENERATOR_H

#include "digraph.h"

class DeBrojinGraphGenerator
{
public:

    static Digraph<string>* generate(istream& kmers) {
        Digraph<string>* graph = new Digraph<string>();
        return graph;
    }

};

#endif // DEBROJINGRAPHGENERATOR_H
