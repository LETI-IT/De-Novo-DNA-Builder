#ifndef DIGRAPHITERATOR_H
#define DIGRAPHITERATOR_H

#include "abstractiterator.h"
using namespace std;

template<typename T>
class DigraphIterator : public AbstractIterator<T>
{
public:

    //DigraphIterator();
    ~DigraphIterator();

//    DigraphIterator(map<T, vector<T> > &digraph) : AbstractIterator<T>()
//    {
//        map_iter = digraph.begin();
//        vector_iter = map_iter->second.begin();
//    }

    DigraphIterator(map<T, vector<T> > &digraph, bool reverse)
    {
        if (reverse)
        {
            map_iter = digraph.end();
            vector_iter = --map_iter->second.end();
        }
        else
        {
            map_iter = digraph.begin();
            vector_iter = map_iter->second.begin();
        }
    }

//    T& operator*()
//    {
//        return *vector_iter;
//    }

//    T* operator->()
//    {
//        return *vector_iter;
//    }

    T* operator++()
    {
//        if (map_iter == digraph.end()) return map_iter;
        //if (map_iter == digraph.end()) return ++vector_iter;
        if (vector_iter == map_iter->second.end())
        {
            map_iter++;
            vector_iter = map_iter->second.begin();
        }
        vector_iter++;
        return &(*vector_iter);
    }

    T* operator--()
    {
        //if (map_iter == digraph.begin()) return --vector_iter;
        if (vector_iter == map_iter->second.begin())
        {
            map_iter--;
            vector_iter = map_iter->second.end();
        }

        vector_iter--;
        return &(*vector_iter);
        //return --vector_iter;
    }


    bool operator==(const AbstractIterator<T>& other) const
    {
        return vector_iter == other.iterator();
    }

    bool operator!=(const AbstractIterator<T>& other) const
    {
        //return !(*this == other);
        return vector_iter != other.iterator();
    }

//    bool operator==(const AbstractIterator<T>& other) const
//    {
//        return true;
//    }

//    bool operator!=(const AbstractIterator<T>& other) const
//    {
//        return false;
//    }




    ostream& operator<<(ostream& o)
    {
        return o << *vector_iter;
    }


    typedef typename vector<T>::iterator iter;
    iter iterator()
    {
        return vector_iter;
    }


private:
    typename map<T, vector<T> >::iterator map_iter;
    typename vector<T>::iterator vector_iter;
};

#endif // DIGRAPHITERATOR_H
