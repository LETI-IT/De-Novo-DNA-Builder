#include "digraphiterator.h"

template<typename T>
DigraphIterator<T>::DigraphIterator()
{

}

template<typename T>
DigraphIterator<T>::~DigraphIterator()
{

}

template<typename T>
T DigraphIterator<T>::next()
{
    T t;
    return t;
}

template<typename T>
bool DigraphIterator<T>::hasNext()
{
    return false;
}

template class DigraphIterator<int>;
