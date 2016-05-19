#ifndef DEBRUJNGRAPHEXCEPTION_H
#define DEBRUJNGRAPHEXCEPTION_H

#include <exception>
#include <string>

/*
 * This exception is thrown by De Bruin Graph
 */
class DeBrujnGraphException : public std::exception
{
    const char * msg;
public:
    DeBrujnGraphException() {};
    DeBrujnGraphException(char const* msg) {
        this->msg = msg;
    }

    const char * what () const throw () {
        return msg;
    }
};

#endif // DEBRUJNGRAPHEXCEPTION_H
