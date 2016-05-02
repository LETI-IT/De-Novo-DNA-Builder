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

using namespace std;

template<typename T>
class Digraph : public AbstractDigraph<T>
{
private:
    map<T, vector<T> > digraph;
    map<T, int> in_deg;
    map<T, int> out_deg;

    void fill_achievable(vector<T> &v, queue<T> &q);

public:
    Digraph();
    ~Digraph();

    void add_link(T v1, T v2);
    void add_links(istream& stm);

    bool is_linked(T v1, T v2);
    vector<T> adjacency(T v);
    bool is_reach(T start, T finish);

    int in_degree(T v);
    int out_degree(T v);
    AbstractDigraph<T>* get_transpose();

    AbstractIterator<T>* begin(TypeIterator);
    AbstractIterator<T>* end(TypeIterator);
};

#endif // DIGRAPH
