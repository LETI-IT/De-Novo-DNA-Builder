#ifndef IGRAPH
#define IGRAPH
#include <vector>
#include <iostream>
#include <sstream>
#include "abstractiterator.h"
using namespace std;


/**
 * @brief The IGraph class is interface for graph structure
 */
template<class Vertex>
class IGraph
{

public:
    virtual void add_link(Vertex v1, Vertex v2)=0;
    virtual void add_links(istream& stm)=0;

    virtual bool is_linked(Vertex v1, Vertex v2)=0;
    virtual vector<Vertex> adjacency(Vertex v)=0;
    virtual bool is_reach(Vertex start, Vertex finish)=0;

    virtual AbstractIterator<Vertex>* iterator() = 0;

};

#endif // IGRAPH

