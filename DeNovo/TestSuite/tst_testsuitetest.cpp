#include <QString>
#include <QtTest>
#include "mocfactory.h"
#include "debrojingraphgenerator.h"
#include <algorithm>
#include "euleriancircuit.h"
#include "manipulator.h"
#include <QDebug>

class TestSuiteTest : public QObject
{
    Q_OBJECT

public:
    TestSuiteTest();

private:
    /**
     * @brief test_mode
     * 0 - mocking
     * 1 - real
     */
    int test_mode;

private Q_SLOTS:
    void testCase1();
    void test_check_add_link();
    void test_adjacency();
    void test_reacheble();
    void test_in_degree();
    void test_out_degree();
    void test_int_vertex();
    void test_transpose();

    void graphTestLinkage();
    void graphTestAdjacency();
    void graphTestReachability();
    void graphTestForeach();

    void graphShoultBeCreated();
    void graphShouldCheckExistingElementsRight();
    void generatorTest();

    void eulerianCircleTest();
    void manipulatorTest();
};

TestSuiteTest::TestSuiteTest()
{
    /**
      change it when real will be done
      **/
    test_mode=1;
}

void TestSuiteTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void TestSuiteTest::test_check_add_link()
{
    AbstractDigraph<test_vertex_type>* testGraph = TestGraphFactory::newInstance<test_vertex_type>(test_mode);
    testGraph->add_link(0,1);
    QCOMPARE(testGraph->is_linked(0,1),true);
}

void TestSuiteTest::test_adjacency()
{
    AbstractDigraph<test_vertex_type>* testGraph = TestGraphFactory::newInstance<test_vertex_type>(test_mode);
    testGraph->add_link(0,1);
    testGraph->add_link(1,2);
    testGraph->add_link(1,3);

    vector<test_vertex_type> actual = testGraph->adjacency(1);
    std::cout<<std::endl;
    vector<test_vertex_type> expect;
    expect.push_back(2);
    expect.push_back(3);
    QCOMPARE(actual,expect);
}

void TestSuiteTest::test_reacheble()
{
    AbstractDigraph<test_vertex_type>* testGraph = TestGraphFactory::newInstance<test_vertex_type>(test_mode);
    testGraph->add_link(1,2);
    testGraph->add_link(2,3);
    QCOMPARE(testGraph->is_reach(1,3),true);
}

void TestSuiteTest::test_in_degree()
{
     AbstractDigraph<test_vertex_type>* testGraph = TestGraphFactory::newInstance<test_vertex_type>(test_mode);
     testGraph->add_link(0,1);
     testGraph->add_link(1,2);
     testGraph->add_link(1,3);
     testGraph->add_link(1,4);
     testGraph->add_link(1,5);
     testGraph->add_link(5,1);
     QCOMPARE(testGraph->in_degree(1),2);
}

void TestSuiteTest::test_out_degree()
{
    cout << "##### " << __FUNCTION__ << " #####" << endl;

     AbstractDigraph<test_vertex_type>* testGraph = TestGraphFactory::newInstance<test_vertex_type>(test_mode);
     testGraph->add_link(0,1);
     testGraph->add_link(1,2);
     testGraph->add_link(1,3);
     testGraph->add_link(1,4);
     testGraph->add_link(1,5);
     testGraph->add_link(5,1);
     QCOMPARE(testGraph->out_degree(1),4);

     int expectedCnt = 6, actualCnt = 0;
     IGraph<string> *g = new Digraph<string>();
     g->add_link("0","1");
     g->add_link("1","2");
     g->add_link("1","3");
     g->add_link("1","4");
     g->add_link("1","5");
     g->add_link("5","1");
     for(AbstractIterator<string> *it = g->begin(VERTEX); **it != **g->end(VERTEX); ++*it) {
         Vertex<string>& el = dynamic_cast<Vertex<string>&>(const_cast<AbstractComponent<string>&>(**it));
         qDebug() << QString::fromStdString(el.getValue());
         actualCnt++;
     }

     QCOMPARE(actualCnt, expectedCnt);
}

void TestSuiteTest::test_int_vertex()
{
    cout << "##### " << __FUNCTION__ << " #####" << endl;

     IGraph<int> *g = new Digraph<int>();
     g->add_link(0,1);
     g->add_link(1,2);
     g->add_link(1,3);
     g->add_link(1,4);
     g->add_link(1,5);
     g->add_link(5,1);
     for(AbstractIterator<int> *it = g->begin(VERTEX); **it != **g->end(VERTEX); ++*it) {
         cout << framing::frame << **it << endl;
     }
}

void TestSuiteTest::test_transpose()
{

}

void TestSuiteTest::graphTestLinkage() {
    AbstractDigraph<int> *p_digraph = new Digraph<int>();
    const string str = "1 4 1 3 "
                       "2 1 "
                       "3 2 "
                       "4 5 "
                       "5 1 ";
    std::istringstream stm(str);
    p_digraph->add_links(stm);


    //for test: linked vertex.
    QCOMPARE(p_digraph->is_linked(1, 3), true); // is linked.
    QCOMPARE(p_digraph->is_linked(5, 2), false); // isn't linked.
}

void TestSuiteTest::graphTestAdjacency() {
    AbstractDigraph<int> *p_digraph = new Digraph<int>();
    std::istringstream stm("1 4 1 3 ");
    p_digraph->add_links(stm);

    //for test: adjacency vertex.
    vector<int> neighs = p_digraph->adjacency(1);
    vector<int>::iterator it = neighs.begin();

    QCOMPARE((*it), 4);
    it++;
    QCOMPARE((*it), 3);
}

void TestSuiteTest::graphTestReachability()
{
    AbstractDigraph<int> *p_digraph = new Digraph<int>();
    std::istringstream stm("1 4 4 3 ");
    p_digraph->add_links(stm);

    //for test: reached vertex.
    QCOMPARE(p_digraph->is_reach(1, 3), true);
}

void TestSuiteTest::graphTestForeach() {
    AbstractDigraph<int> *p_digraph = new Digraph<int>();
    std::istringstream stm("1 4 4 3 ");
    p_digraph->add_links(stm);

    //TODO: fix
//    cout << "foreach edge" << endl;
//    for(AbstractIterator<int> *it = p_digraph->begin(EDGE); **it != **p_digraph->end(EDGE); ++*it)
//    {
//        cout << framing::frame << **it << endl;
//    }

//    //for test: iterable vertexes.
//    cout << "foreach vertex" << endl;
//    for(AbstractIterator<int> *it = p_digraph->begin(VERTEX); **it != **p_digraph->end(VERTEX); ++*it)
//    {
//        cout << **it << endl;
//    }
}

void TestSuiteTest::graphShoultBeCreated()
{
    const string str = "1 4 1 3 ";
    std::istringstream stm(str);
    Digraph<string>* graph = DeBrojinGraphGenerator::generate(stm);
    QCOMPARE((graph != NULL), true);
}

void TestSuiteTest::graphShouldCheckExistingElementsRight() {
    Digraph<string>* graph = new Digraph<string>();
    graph->add_link("AA", "BB");

    QCOMPARE((graph->hasNode("AA")), true);
    QCOMPARE((graph->hasNode("BB")), true);
    QCOMPARE((graph->hasNode("CC")), false);
}

bool isExistsInVector(vector<string>& vec, string val) {
    return find(vec.begin(), vec.end(), val) != vec.end();
}

void TestSuiteTest::generatorTest() {
    const string str = "3"
                       "BBA "
                       "BAA "
                       "AAA "
                       "AAB "
                       "ABB "
                       "BBA ";
    std::istringstream stm(str);
    Digraph<string>* graph = DeBrojinGraphGenerator::generate(stm);

    vector<string> adj = graph->adjacency("AA");
    QCOMPARE((isExistsInVector(adj, "AB")), true);
    QCOMPARE((isExistsInVector(adj, "AA")), true);

    adj = graph->adjacency("BB");
    QCOMPARE((isExistsInVector(adj, "BA")), true);

    adj = graph->adjacency("BA");
    QCOMPARE((isExistsInVector(adj, "AA")), true);

    adj = graph->adjacency("AB");
    QCOMPARE((isExistsInVector(adj, "BA")), false);
    QCOMPARE((isExistsInVector(adj, "BB")), true);
}

void TestSuiteTest::eulerianCircleTest() {
    AbstractDigraph<int> *p_digraph = new Digraph<int>();
    std::istringstream stm("1 4 4 3 3 1");
    p_digraph->add_links(stm);

    vector<int> euCycle = EulerianCercuit::getEulerianCircuitVerticies(p_digraph);
    QCOMPARE(euCycle.at(0), 1);
    QCOMPARE(euCycle.at(1), 4);
    QCOMPARE(euCycle.at(2), 3);
    QCOMPARE(euCycle.at(3), 1);
}

void TestSuiteTest::manipulatorTest() {
    //TODO:
//    Vertex<int> v(5);
//    std::istringstream stm();
//    stm << framing::frame << v << endl;
//    QCOMPARE(stm.str(), "{5}");
}


QTEST_APPLESS_MAIN(TestSuiteTest)

#include "tst_testsuitetest.moc"
