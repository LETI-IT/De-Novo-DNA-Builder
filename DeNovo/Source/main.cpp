#include "mainwindow.h"
#include "digraph.h"
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

    return a.exec();
}
