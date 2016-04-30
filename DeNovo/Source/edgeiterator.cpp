#include "edgeiterator.h"

template<class T>
EdgeIterator<T>::EdgeIterator()
{

}

template<class T>
EdgeIterator<T>::EdgeIterator(map<T, vector<T> > *digraph_ptr, bool reverse)
{
    if (!reverse)
    {
        it_vtx = digraph_ptr->begin();
        it_adj = it_vtx->second.begin();
    }
    else
    {
        it_vtx = digraph_ptr->end();
        it_vtx--;
        it_adj = it_vtx->second.end();
    }

    it_vtx_end = digraph_ptr->end();
    ptr = new Edge<T>(it_vtx->first, *it_adj);
}

template<class T>
Edge<T>& EdgeIterator<T>::operator*() const
{
    return (*ptr);
}

template<class T>
EdgeIterator<T>& EdgeIterator<T>::operator++()
{
    if (is_last_adj())
    {
        do //skip empty backets.
        {
            it_vtx++;
        } while (it_vtx->second.empty());

        if (it_vtx != it_vtx_end)
            it_adj = it_vtx->second.begin();
        else
            it_adj++;
    }
    else
        it_adj++;

    ptr = new Edge<T>(it_vtx->first, *it_adj);

    return (*this);
}

template<class T>
EdgeIterator<T>& EdgeIterator<T>::operator--()
{
    if (it_adj == it_vtx->second.begin())
    {
        it_vtx--;
        it_adj = it_vtx->second.end();
    }

    it_adj--;
    ptr = new Edge<T>(it_vtx->first, *it_adj);

    return (*this);
}

template<class T>
EdgeIterator<T>& EdgeIterator<T>::operator++(int) //postinc.
{
    EdgeIterator it_aux = *this;
    ++*this;
    return (it_aux);
}

template<class T>
EdgeIterator<T>& EdgeIterator<T>::operator--(int) //postdec.
{
    EdgeIterator it_aux = *this;
    --*this;
    return (it_aux);
}

template<class T>
bool EdgeIterator<T>::operator==(const AbstractIterator<T> *it_other) const
{
//    return (*ptr == *it_other.ptr);
//    EdgeIterator * it = dynamic_cast<EdgeIterator<T>*>(const_cast<AbstractComponent<T>*>(it_other));
//    return (*ptr == it->get_ptr());

    return (this->get_ptr() == it_other->get_ptr());
}

template<class T>
bool EdgeIterator<T>::operator!=(const AbstractIterator<T> *it_other) const
{
//    return (*ptr != *it_other.ptr);
    return (this->get_ptr() != it_other->get_ptr());
}

template<class T>
bool EdgeIterator<T>::is_last_adj()
{
    typename vector<T>::iterator it_adj_aux = it_adj + 1;
    if (it_adj_aux == it_vtx->second.end()) return true;
    return false;
}

template<class T>
AbstractComponent<T>* EdgeIterator<T>::get_ptr() const
{
    return ptr;
}


template class EdgeIterator<int>;
