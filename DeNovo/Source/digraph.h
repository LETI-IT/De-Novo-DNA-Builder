#ifndef DIGRAPH
#define DIGRAPH
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>
#include <memory>

#include "abstractdigraph.h"
#include "edgeiterator.h"
#include "vertexiterator.h"
#include "graphallocator.h"

using namespace std;

/*
 * Implementation of digraph
 */
template<class T, class Allocator = allocator<T> >
class Digraph : public AbstractDigraph<T, Allocator>
{
private:
    map<T, vector<T>, less<T>, GraphAllocator<pair<T, vector<T> > > >   digraph;
    map<T, int> in_deg;
    map<T, int> out_deg;

    void fill_achievable(vector<T> &v, queue<T> &q);

public:
    Digraph();
    ~Digraph();
    // Add link between two values
    void add_link(T v1, T v2);
    // Read all values from stream and add links between them
    void add_links(istream& stm);

    // Check whether two values are linked
    bool is_linked(T v1, T v2);

    // Get list of adjacencies for input value
    vector<T> adjacency(T v);

    // Check whether finish value is reached from start value
    bool is_reach(T start, T finish);

    int in_degree(T v);
    int out_degree(T v);
    AbstractDigraph<T, Allocator>* get_transpose();

    AbstractIterator<T>* begin(TypeIterator);
    AbstractIterator<T>* end(TypeIterator);

    bool hasNode(T v);
};

#endif // DIGRAPH
