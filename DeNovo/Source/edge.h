#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include "abstractcomponent.h"
using namespace std;

/*
 * Edge item for graph. Allow to create relationship between two nodes
 */
template <class T>
class Edge : public AbstractComponent<T>
{
private:
    T v1, v2;

    ostream& do_print(ostream& os) const;
    bool do_equals(const AbstractComponent<T>& _other) const;

public:
    Edge();
    Edge(T v1, T v2);
};

#endif // EDGE_H
