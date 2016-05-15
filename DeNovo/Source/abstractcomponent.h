#ifndef ABSTRACTCOMPONENT
#define ABSTRACTCOMPONENT

#include <iostream>
using namespace std;

template<class T>
class AbstractComponent
{
private:
    virtual ostream& do_print(ostream&) const = 0;
    virtual bool do_equals(const AbstractComponent &other) const = 0;

public:
    friend ostream& operator<<(ostream& os, const AbstractComponent& a) { return a.do_print(os); }
    friend bool operator==(const AbstractComponent &a1, const AbstractComponent &a2){return a1.do_equals(a2); }
    friend bool operator!=(const AbstractComponent &a1, const AbstractComponent &a2) {return !a1.do_equals(a2); }
};

#endif // ABSTRACTCOMPONENT

