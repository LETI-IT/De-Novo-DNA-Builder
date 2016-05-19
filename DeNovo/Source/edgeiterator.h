#ifndef EDGEITERATOR_H
#define EDGEITERATOR_H

#include "abstractiterator.h"
#include "edge.h"
#include "graphallocator.h"

/*
 * Allow to iterate over edges
 */
template<class T>
class EdgeIterator : public AbstractIterator<T>
{
private:
    typename map<T, vector<T>, less<T>, GraphAllocator<pair<T, vector<T> > > >::iterator it_vtx; //vertex iterator.
    typename map<T, vector<T>, less<T>, GraphAllocator<pair<T, vector<T> > > >::iterator it_vtx_end; //vertex iterator pointer to end.
    typename vector<T>::iterator it_adj; //adjacency iterator.

    bool is_last_adj();

public:
    EdgeIterator();
    EdgeIterator(map<T, vector<T>, less<T>, GraphAllocator<pair<T, vector<T> > > > *digraph_ptr, bool reverse);

    Edge<T>& operator*() const;
    EdgeIterator& operator++();
    EdgeIterator& operator--();
    EdgeIterator& operator++(int);
    EdgeIterator& operator--(int);
    bool operator==(const AbstractIterator<T> *it_other) const;
    bool operator!=(const AbstractIterator<T> *it_other) const;
};

#endif // EDGEITERATOR_H
