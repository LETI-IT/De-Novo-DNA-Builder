#include "vertexiterator.h"

template<class T>
bool VertexIterator<T>::is_init = false;

template<class T>
void VertexIterator<T>::resetInit()
{
    is_init = false;
}

template<class T>
VertexIterator<T>::VertexIterator()
{

}

template<class T>
VertexIterator<T>::VertexIterator(map<T, vector<T>, less<T>, GraphAllocator<pair<T, vector<T> > > > *digraph_ptr, bool reverse)
{
    if (!reverse)
    {
        it_vtx = digraph_ptr->begin();
//        cout << "begin iter: " << it_vtx->first << endl;
    }
    else
    {
        if (!is_init)
        {
            it_vtx = --digraph_ptr->end();
            T temp = it_vtx->first;
            temp += temp;
            digraph_ptr->operator [](temp).push_back(temp);

            is_init = true;
        }

        it_vtx = digraph_ptr->end();
        --it_vtx;
//        cout << "it_vtx: " << it_vtx->first << endl;
    }

//    cout << "it_vtx point: " << it_vtx->first << endl;

//    ptr = new Vertex<T>(it_vtx->first);

}

template<class T>
Vertex<T>& VertexIterator<T>::operator*() const
{
    Vertex<T> * ptr = new Vertex<T>(it_vtx->first);
    return (*ptr);
}

template<class T>
VertexIterator<T>& VertexIterator<T>::operator++()
{
    it_vtx++;
    return (*this);
}

template<class T>
VertexIterator<T>& VertexIterator<T>::operator--()
{
    it_vtx--;
    return (*this);
}

template<class T>
VertexIterator<T>& VertexIterator<T>::operator++(int) //postinc.
{
    VertexIterator it_aux = *this;
    ++*this;
    return (it_aux);
}

template<class T>
VertexIterator<T>& VertexIterator<T>::operator--(int) //postdec.
{
    VertexIterator it_aux = *this;
    --*this;
    return (it_aux);
}

template<class T>
bool VertexIterator<T>::operator==(const AbstractIterator<T> *it_other) const
{
    VertexIterator * it = dynamic_cast<VertexIterator<T>*>(const_cast<AbstractIterator<T>*>(it_other));
    return this->it_vtx == it->it_vtx;
}

template<class T>
bool VertexIterator<T>::operator!=(const AbstractIterator<T> *it_other) const
{
    VertexIterator * it = dynamic_cast<VertexIterator<T>*>(const_cast<AbstractIterator<T>*>(it_other));
    return this->it_vtx != it->it_vtx;
}

template class VertexIterator<int>;
template class VertexIterator<string>;
