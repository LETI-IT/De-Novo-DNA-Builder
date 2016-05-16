#ifndef DEBROJINGRAPHGENERATOR_H
#define DEBROJINGRAPHGENERATOR_H

#include "digraph.h"
#include "debrujngraphexception.h"

/*
 * Allow to generate De Brojin Graph by input stream
 */
class DeBrojinGraphGenerator
{
public:

    /*
     * Generate graph by input stream
     * Method throws exception if stream has incorrect data
     */
    static Digraph<string>* generate(istream& kmers) {
        string kmer;
        Digraph<string>* graph = new Digraph<string>();
        unsigned k;
        kmers >> k;

        while (kmers >> kmer) {
            if (kmer.size() != k) {
                throw DeBrujnGraphException("Wrong kmer size");
            }
            string prefix = kmer.substr(0, k-1);
            string suffix = kmer.substr(1, k-1);

            graph->add_link(prefix, suffix);
        }

        return graph;
    }

};

#endif // DEBROJINGRAPHGENERATOR_H
