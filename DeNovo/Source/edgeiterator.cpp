#include "edgeiterator.h"

template<class T>
EdgeIterator<T>::EdgeIterator()
{

}

template<class T>
EdgeIterator<T>::EdgeIterator(map<T, vector<T>, less<T>, GraphAllocator<pair<T, vector<T> > > > *digraph_ptr, bool reverse)
{

    if (!reverse)
    {
        it_vtx = digraph_ptr->begin();
        it_adj = it_vtx->second.begin();
//        cout << "====== begin.iter point =========" << endl;
    }
    else
    {
        it_vtx = digraph_ptr->end();
        do
        {
            it_vtx--;
            it_adj = it_vtx->second.end();
        } while (it_vtx->second.empty() && it_vtx != digraph_ptr->begin());

//        cout << "====== end.iter point =========" << endl;
//        cout << "point to vertex: " << it_vtx->first << endl;
    }

    it_vtx_end = digraph_ptr->end();
    do
    {
        it_vtx_end--;
    } while (it_vtx_end->second.empty() && it_vtx_end != digraph_ptr->begin());


//    cout << "it_vtx point:     [" << &(*it_vtx) << "]" << endl;
//    cout << "it_vtx_end point: [" << &(*it_vtx_end) << "]" << endl;
//    cout << "it_adj point:     [" << &(*it_adj) << "]" << endl;
}

template<class T>
Edge<T>& EdgeIterator<T>::operator*() const
{
    Edge<T> * ptr = new Edge<T>(it_vtx->first, *it_adj);
    return (*ptr);
    //return (*ptr);
}

template<class T>
EdgeIterator<T>& EdgeIterator<T>::operator++()
{
    if (is_last_adj())
    {
        if (it_vtx == it_vtx_end)
        {
            it_adj++;
            return *this;
        }

        do{
            it_vtx++;
            it_adj = it_vtx->second.begin();
        } while (it_vtx->second.empty() && it_vtx != it_vtx_end);
    }
    else
        it_adj++;

    return *this;
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
    EdgeIterator * it = dynamic_cast<EdgeIterator<T>*>(const_cast<AbstractIterator<T>*>(it_other));
    return this->it_adj == it->it_adj;
}

template<class T>
bool EdgeIterator<T>::operator!=(const AbstractIterator<T> *it_other) const
{
    EdgeIterator * it = dynamic_cast<EdgeIterator<T>*>(const_cast<AbstractIterator<T>*>(it_other));
    typename vector<T>::iterator it_adj_oth = it->it_adj;
//    cout << "This iter point: [" << &(*it_adj) << "], other iter point: [" << &(*it_adj_oth) << "]" << endl;
//    cout << "vertex :" << it_vtx->first << ", 1-adj:" << *it_adj << endl;
    bool res = this->it_adj != it->it_adj;
    return res;
}

template<class T>
bool EdgeIterator<T>::is_last_adj()
{
    typename vector<T>::iterator it_adj_aux = it_adj + 1;
    if (it_adj_aux == it_vtx->second.end()) return true;
    return false;
}


template class EdgeIterator<int>;
template class EdgeIterator<string>;
