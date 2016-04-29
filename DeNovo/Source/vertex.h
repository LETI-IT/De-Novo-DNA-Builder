#ifndef VERTEX_H
#define VERTEX_H

#include "abstractcomponent.h"

template<class T>
class Vertex : public AbstractComponent<T>
{
private:
    T v1;

    ostream& do_print(ostream& os) const;
    bool do_equals(const AbstractComponent<T>& _other) const;

public:
    Vertex();
    Vertex(T v1);
};

#endif // VERTEX_H
