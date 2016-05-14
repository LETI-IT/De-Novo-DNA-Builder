#include "mainwindow.h"
#include "digraph.h"
#include "digraphiterator.h"
#include "euleriancircuit.h"
#include "manipulator.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    AbstractDigraph<int> *p_digraph = new Digraph<int>();
    const string str = "1 4 1 3 "
                       "2 1 "
                       "3 2 "
                       "4 5 "
                       "5 1 ";
    std::istringstream stm(str);
    p_digraph->add_links(stm);



//for test: iterable edges.
    cout << "foreach edge" << endl;
    for(AbstractIterator<int> *it = p_digraph->begin(EDGE); **it != **p_digraph->end(EDGE); ++*it)
    {
        cout << framing::frame << **it << endl;
    }


//for test: iterable vertexes.
//    cout << "foreach vertex" << endl;
//    for(AbstractIterator<int> *it = p_digraph->begin(VERTEX); **it != **p_digraph->end(VERTEX); ++*it)
//    {
//        cout << **it << endl;
//    }

    //test eulerian graph
    vector<int> euCycle = EulerianCercuit::getEulerianCircuitVerticies(p_digraph);
    cout << "Eulerian cycle: ";
    for (typename vector<int>::iterator it = euCycle.begin(); it != euCycle.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    //for test: manipulator.
//    cout << framing::frame << "hello" << endl;
//    cout << framing::frame << 6 << endl;
//    Vertex<int> v(5);
//    cout << framing::frame << v << endl;

    AbstractDigraph<string> *p_digraph2 = new Digraph<string>();


    return a.exec();
}
