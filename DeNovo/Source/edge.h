#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include "abstractcomponent.h"
using namespace std;

template <class T>
class Edge : public AbstractComponent<T>
{
private:
    T v1, v2;

    ostream& do_print(std::ostream& os) const
    {
          os << "{" << v1 << ", " << v2 << "}";
          return os;
    }

    bool do_equals(const AbstractComponent<T>* _other) const
    {
        Edge<T> * other = dynamic_cast<Edge<T>*>(const_cast<AbstractComponent<T>*>(_other));
        return (v1 == other->v1 && v2 == other->v2);
    }

public:
    Edge(){}
    Edge(T v1, T v2) : v1(v1), v2(v2){}

//    friend ostream& operator<<(ostream& os, const Edge& e)
//    {
//        os << "{" << e.v1 << ", " << e.v2 << "}";
//        return os;
//    }
//    friend bool operator==(const Edge &e1, const Edge &e2)
//    {
//        return (e1.v1 == e2.v1 && e1.v2 == e2.v2);
//    }

//    friend bool operator!=(const Edge &e1, const Edge &e2)
//    {
//        return (e1.v1 != e2.v1 || e1.v2 != e2.v2);
//    }

};

#endif // EDGE_H
