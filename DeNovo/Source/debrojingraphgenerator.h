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

        string* items = new string[2];
        int index = 0;
        VertexIterator<string>::resetInit();
        for(AbstractIterator<string> *it = graph->begin(VERTEX); **it != **graph->end(VERTEX); ++*it)
        {
            Vertex<string>& vertex = static_cast<Vertex<string>&>(**it);
            if(graph->in_degree(vertex.getValue()) != graph->out_degree(vertex.getValue())) {
                if (index >= 2)
                   throw DeBrujnGraphException("Wrong input data");

                items[index] = vertex.getValue();
                index++;
            }
        }

        if (index != 2)
           throw DeBrujnGraphException("Wrong input data.");
        else if (graph->in_degree(items[0]) > graph->out_degree(items[0]))
           graph->add_link(items[0], items[1]);
        else
           graph->add_link(items[1], items[0]);
        return graph;
    }

};

#endif // DEBROJINGRAPHGENERATOR_H
