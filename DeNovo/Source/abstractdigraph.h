#ifndef ABSTRACTDIGRAPH_H
#define ABSTRACTDIGRAPH_H
#include "igraph.h"

template<class T>
class AbstractDigraph:  public IGraph<T>
{
public:
    virtual ~AbstractDigraph(){}
    AbstractDigraph() {}
    virtual int in_degree(T v)=0;
    virtual int out_degree(T v)=0;
    virtual AbstractDigraph<T>* get_transpose()=0;
};

#endif // ABSTRACTDIGRAPH_H
