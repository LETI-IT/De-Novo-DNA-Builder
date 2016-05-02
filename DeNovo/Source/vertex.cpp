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

template<class T>
<<<<<<< HEAD
T Vertex<T>::get_value()
{
    return this->v1;
}


=======
T Vertex<T>::getValue() {
    return v1;
}

>>>>>>> 150a35390b55758ecd5213fb85c276f61ee4b15a
template class Vertex<int>;
