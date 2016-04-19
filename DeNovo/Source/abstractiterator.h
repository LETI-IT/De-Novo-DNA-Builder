#ifndef ITERATOR
#define ITERATOR

template<typename T> class AbstractIterator {
public:
    virtual T next() = 0;
    virtual bool hasNext() = 0;
};

#endif // ITERATOR

