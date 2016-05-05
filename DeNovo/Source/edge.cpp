#include "edge.h"

template<class T>
Edge<T>::Edge(){}

template<class T>
Edge<T>::Edge(T v1, T v2) : v1(v1), v2(v2){}

template<class T>
ostream& Edge<T>::do_print(ostream& os) const
{
      os << v1 << ", " << v2;
      return os;
}

template<class T>
bool Edge<T>::do_equals(const AbstractComponent<T>& _other) const
{
    Edge<T>& other = dynamic_cast<Edge<T>&>(const_cast<AbstractComponent<T>&>(_other));
    return (v1 == other.v1 && v2 == other.v2);
}

template class Edge<int>;
