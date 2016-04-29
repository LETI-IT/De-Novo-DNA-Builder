#include "vertex.h"

template<class T>
Vertex<T>::Vertex(){}

template<class T>
Vertex<T>::Vertex(T v1) : v1(v1){}

template<class T>
ostream& Vertex<T>::do_print(ostream& os) const
{
      os << "{" << v1 << "}";
      return os;
}

template<class T>
bool Vertex<T>::do_equals(const AbstractComponent<T>& _other) const
{
    Vertex<T>& other = dynamic_cast<Vertex<T>&>(const_cast<AbstractComponent<T>&>(_other));
    return (v1 == other.v1);
}

template class Vertex<int>;
