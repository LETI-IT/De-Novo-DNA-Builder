#ifndef VERTEXITERATOR_H
#define VERTEXITERATOR_H

#include "abstractiterator.h"
#include "vertex.h"
#include "graphallocator.h"

/*
 * Allow to iterate over vertexes
 */
template<class T>
class VertexIterator : public AbstractIterator<T>
{
private:
    typename map<T, vector<T>, less<T>, GraphAllocator<pair<T, vector<T> > > >::iterator it_vtx; //vertex iterator.

public:
    VertexIterator();
    VertexIterator(map<T, vector<T>, less<T>, GraphAllocator<pair<T, vector<T> > > > *digraph_ptr, bool reverse);

    Vertex<T>& operator*() const;
    VertexIterator& operator++();
    VertexIterator& operator--();
    VertexIterator& operator++(int);
    VertexIterator& operator--(int);
    bool operator==(const AbstractIterator<T> *it_other) const;
    bool operator!=(const AbstractIterator<T> *it_other) const;
};

#endif // VERTEXITERATOR_H
