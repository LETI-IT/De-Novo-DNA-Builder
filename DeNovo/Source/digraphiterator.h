#ifndef DIGRAPHITERATOR_H
#define DIGRAPHITERATOR_H

#include "abstractiterator.h"

template<typename T>
class DigraphIterator : public AbstractIterator<T>
{
public:
    DigraphIterator();
    ~DigraphIterator();

public:
    T next();
    bool hasNext();
};

#endif // DIGRAPHITERATOR_H
