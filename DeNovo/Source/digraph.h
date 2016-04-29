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
#include "vertexiterator.h"

using namespace std;

template<typename T>
class Digraph : public IGraph<T>
{
private:
    map<T, vector<T> > digraph;

    void fill_achievable(vector<T> &v, queue<T> &q);

public:
    Digraph();
    ~Digraph();

    void add_link(T v1, T v2);
    void add_links(istream& stm);

    bool is_linked(T v1, T v2);
    vector<T> adjacency(T v);
    bool is_reach(T start, T finish);

    AbstractIterator<T>* begin(TypeIterator);
    AbstractIterator<T>* end(TypeIterator);
};

#endif // DIGRAPH
