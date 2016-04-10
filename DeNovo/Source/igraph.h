#ifndef IGRAPH
#define IGRAPH
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

typedef int vertex_type;

/**
 * @brief The IGraph class is interface for graph structure
 */
class IGraph
{
public:
    virtual void add_link(vertex_type v1, vertex_type v2)=0;
    virtual void add_links(istream& stm)=0;

    virtual bool is_linked(vertex_type v1, vertex_type v2)=0;
    virtual vector<vertex_type> adjacency(vertex_type v)=0;
    virtual bool is_reach(vertex_type start, vertex_type finish)=0;

};

#endif // IGRAPH

