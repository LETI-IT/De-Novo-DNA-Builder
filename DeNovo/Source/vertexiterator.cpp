#include "vertexiterator.h"

template<class T>
bool VertexIterator<T>::is_init = false;

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
        cout << "begin iter: " << it_vtx->first << endl;
    }
    else
    {
        if (!is_init)
        {
            T temp = digraph_ptr->end()->first;
//            temp++;
            temp += temp;
            digraph_ptr->operator [](temp).push_back(0);
            is_init = true;
        }
        it_vtx = digraph_ptr->end();
    }

    ptr = new Vertex<T>(it_vtx->first);
}

template<class T>
Vertex<T>& VertexIterator<T>::operator*() const
{
    return (*ptr);
}

template<class T>
VertexIterator<T>& VertexIterator<T>::operator++()
{
    it_vtx++;
    ptr = new Vertex<T>(it_vtx->first);

    return (*this);
}

template<class T>
VertexIterator<T>& VertexIterator<T>::operator--()
{
    it_vtx--;
    ptr = new Vertex<T>(it_vtx->first);

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
    return (this->get_ptr() == it_other->get_ptr());
}

template<class T>
bool VertexIterator<T>::operator!=(const AbstractIterator<T> *it_other) const
{
    return (this->get_ptr() != it_other->get_ptr());
}


template<class T>
AbstractComponent<T>* VertexIterator<T>::get_ptr() const
{
    return ptr;
}


template class VertexIterator<int>;
template class VertexIterator<string>;
