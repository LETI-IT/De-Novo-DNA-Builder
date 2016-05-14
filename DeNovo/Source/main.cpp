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




    //for test: manipulator.


    AbstractDigraph<string> *p_digraph2 = new Digraph<string>();


    return a.exec();
}
