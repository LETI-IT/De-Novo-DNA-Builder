#ifndef MOCKITERATOR_HPP
#define MOCKITERATOR_HPP

#include "../Source/abstractiterator.h"

template<typename T>
class MockIterator : public AbstractIterator<T> {


    // AbstractIterator interface
public:
    virtual T next() {
        return NULL;
    }

    virtual bool hasNext() {
        return false;
    }
};


#endif // MOCKITERATOR_HPP

