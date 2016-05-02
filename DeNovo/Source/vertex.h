#ifndef VERTEX_H
#define VERTEX_H

#include "abstractcomponent.h"

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
<<<<<<< HEAD
    T get_value();
=======

    T getValue();
>>>>>>> 150a35390b55758ecd5213fb85c276f61ee4b15a
};

#endif // VERTEX_H
