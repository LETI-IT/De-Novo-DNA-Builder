#ifndef MOCFACTORY
#define MOCFACTORY
#include "../Source/igraph.h"

class MocGraph:public IGraph
{
public:
    virtual void add_link(vertex_type v1, vertex_type v2){
    }

    virtual void add_links(istream& stm) {
    }

    virtual bool is_linked(vertex_type v1, vertex_type v2) {
        return true;
    }

    virtual vector<vertex_type> adjacency(vertex_type v) {
        vector<vertex_type> vect;
        vect.push_back(0);
        vect.push_back(2);
        vect.push_back(3);
        return vect;
    }

    virtual bool is_reach(vertex_type start, vertex_type finish) {
        return true;
    }
};

class GraphFactory
{
private:
    GraphFactory(){};

public:
    ~GraphFactory(){};

    static IGraph* newInstance(int graphType=0) {
        if(graphType==0)
            return new MocGraph(); //the test graph
        else
            return NULL; // the real graph
    }
};

#endif // MOCFACTORY
