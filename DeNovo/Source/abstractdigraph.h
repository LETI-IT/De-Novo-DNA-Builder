#ifndef ABSTRACTDIGRAPH_H
#define ABSTRACTDIGRAPH_H
#include "igraph.h"

template<class T, class Allocator = allocator<T> >
/*
 * Base class for all digraphs
 */
class AbstractDigraph:  public IGraph<T, Allocator>
{
public:
    virtual ~AbstractDigraph(){}
    AbstractDigraph() {}
    // degree of input relations
    virtual int in_degree(T v)=0;
    // degree of output degrees
    virtual int out_degree(T v)=0;
    virtual AbstractDigraph<T, Allocator>* get_transpose()=0;
    // there is node with input value or not
    virtual bool hasNode(T v) = 0;
};

#endif // ABSTRACTDIGRAPH_H
