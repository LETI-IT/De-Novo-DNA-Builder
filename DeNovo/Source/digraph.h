#ifndef DIGRAPH
#define DIGRAPH
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>
#include <memory>

#include "igraph.h"
#include "edgeiterator.h"

using namespace std;

template<typename Vertex>
class Digraph : public IGraph<Vertex>
{
private:
    map<Vertex, vector<Vertex> > digraph;

    void fill_achievable(vector<Vertex> &v, queue<Vertex> &q);

public:
    Digraph();
    ~Digraph();

    void add_link(Vertex v1, Vertex v2);
    void add_links(istream& stm);

    bool is_linked(Vertex v1, Vertex v2);
    vector<Vertex> adjacency(Vertex v);
    bool is_reach(Vertex start, Vertex finish);

    AbstractIterator<Vertex>* begin(TypeIterator);
    AbstractIterator<Vertex>* end(TypeIterator);
};

#endif // DIGRAPH
