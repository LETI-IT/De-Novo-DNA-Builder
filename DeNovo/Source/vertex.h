#ifndef VERTEX_H
#define VERTEX_H

#include "abstractcomponent.h"

/*
 * Item of digraph which contains value
 */
template<class T>
class Vertex : public AbstractComponent<T>
{
protected:
    T v1;
private:
    ostream& do_print(ostream& os) const;
    bool do_equals(const AbstractComponent<T>& _other) const;

public:
    Vertex();
    Vertex(T v1);
    T getValue();
};

#endif // VERTEX_H
