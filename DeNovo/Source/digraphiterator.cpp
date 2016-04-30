#include "digraphiterator.h"

//template<typename T>
//DigraphIterator<T>::DigraphIterator() : AbstractIterator<T>()
//{

//}

//template<typename T>
//DigraphIterator<T>::DigraphIterator(map<T, vector<T> > &digraph_)
//{
//    digraph = digraph_;
//}

template<typename T>
DigraphIterator<T>::~DigraphIterator()
{

}

//template<typename T>
//T DigraphIterator<T>::next()
//{
//    T t;
//    return t;
//}

//template<typename T>
//bool DigraphIterator<T>::hasNext()
//{
//    return false;
//}

template class DigraphIterator<int>;
