#ifndef ITERATOR
#define ITERATOR

#include <map>
#include <vector>
#include "abstractcomponent.h"
using namespace std;

template<class T>
class AbstractIterator
{
public:
    AbstractIterator(){}
    virtual ~AbstractIterator(){}

    virtual AbstractComponent<T>& operator*() const = 0;
    virtual AbstractIterator& operator++() = 0;
    virtual AbstractIterator& operator--() = 0;
    virtual AbstractIterator& operator++(int) = 0;
    virtual AbstractIterator& operator--(int) = 0;
    virtual bool operator==(const AbstractIterator<T> *it_other) const = 0;
    virtual bool operator!=(const AbstractIterator<T> *it_other) const = 0;
};

#endif // ITERATOR

