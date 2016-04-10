#include <iostream>
#include "digraph.h"

using namespace std;

int main() {
//    cout << "Hello, World!" << endl;
    digraph d;
    const string str = "1 2  1 7  1 8  "
            "2 3  2 6  2 10  "
            "3 4  3 5  3 11  "
            "6 10  6 12  "
            "8 9  8 12  "
            "9 10  9 11  "
            "11 7  "
            "12 5";
    std::istringstream stm(str);
    d.add_links(stm);

    return 0;
}