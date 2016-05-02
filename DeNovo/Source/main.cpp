#include "mainwindow.h"
#include "digraph.h"
#include "digraphiterator.h"
#include "euleriancircuit.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    AbstractDigraph<int> *p_digraph = new Digraph<int>();
    const string str = "1 4 1 3 "
                       "2 1 "
                       "3 2 "
                       "4 5 "
                       "5 1 ";
    std::istringstream stm(str);
    p_digraph->add_links(stm);


//for test: linked vertex.
//    bool check1 = p_digraph->is_linked(1, 8); // is linked.
//    bool check2 = p_digraph->is_linked(1, 9); // isn't linked.
//    cout << "result ckecked: " << check1 << ", " << check2 << endl;


//for test: adjacency vertex.
//    vector<int> neighs = p_digraph->adjacency(1);
//     cout << "adjacency: ";
//    for (vector<int>::iterator it = neighs.begin(); it != neighs.end(); ++it)
//       cout << *it << " ";
//    cout << endl;


    //for test: reached vertex.
//    bool check3 = p_digraph->is_reach(1, 10);
//    cout << "reached: " << check3 << endl;


//for test: iterable edges.
    cout << "foreach edge" << endl;
    for(AbstractIterator<int> *it = p_digraph->begin(EDGE); **it != **p_digraph->end(EDGE); ++*it)
    {
        cout << **it << endl;
    }


//for test: iterable vertexes.
    cout << "foreach vertex" << endl;
    for(AbstractIterator<int> *it = p_digraph->begin(VERTEX); **it != **p_digraph->end(VERTEX); ++*it)
    {
        cout << **it << endl;
    }

    //test eulerian graph
    vector<int> euCycle = EulerianCercuit::getEulerianCircuitVerticies(p_digraph);
    cout << "Eulerian cycle: ";
    for (typename vector<int>::iterator it = euCycle.begin(); it != euCycle.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    return a.exec();
}
