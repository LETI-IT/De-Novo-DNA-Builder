#include "mainwindow.h"
#include "digraph.h"
#include "digraphiterator.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    IGraph<int> *p_digraph = new Digraph<int>();
    const string str = "1 2  1 7  1 8  "
                "2 3  2 6  2 10  "
                "3 4  3 5  3 11  "
                "6 10  6 12  "
                "8 9  8 12  "
                "9 10  9 11  "
                "11 7  "
                "12 5";
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

    return a.exec();
}
