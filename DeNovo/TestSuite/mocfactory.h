#ifndef MOCFACTORY
#define MOCFACTORY
#include "digraph.h"

#define test_vertex_type int

template<class T, class Allocator = allocator<T> >
class MocGraph : public AbstractDigraph<T, Allocator>
{
private:
    int degree_in;
    int degree_out;

public:
    MocGraph() {
        degree_in = 2;
        degree_out = 4;
    }
    ~MocGraph() {}

    void add_link(T v1, T v2){
    }

    void add_links(istream& stm) {
    }

    bool is_linked(T v1, T v2) {
        return true;
    }

    vector<T> adjacency(T v) {
        vector<T> vect;
        vect.push_back(0);
        vect.push_back(2);
        vect.push_back(3);
        return vect;
    }

    bool is_reach(T start, T finish) {
        return true;
    }


    AbstractIterator<T>* begin(TypeIterator) {
        return NULL;
    }

    AbstractIterator<T>* end(TypeIterator) {
        return NULL;
    }

    int in_degree(T v) {
        return degree_in;
    }

    int out_degree(T v) {
        return degree_out;
    }

    AbstractDigraph<T, Allocator>* get_transpose(){
        return NULL;
    }
};


class TestGraphFactory
{
private:
    TestGraphFactory(){};

public:
    ~TestGraphFactory(){};

    template<class T, class Allocator = allocator<T> >
    static AbstractDigraph<T, Allocator>* newInstance(int graphType=0)
    {
        if(graphType==0)
            return new MocGraph<T, Allocator>(); //the test graph
        else
            return new Digraph<T, Allocator>(); // the real graph
    }
};

#endif // MOCFACTORY
