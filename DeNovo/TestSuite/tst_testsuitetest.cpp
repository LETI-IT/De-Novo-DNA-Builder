#include <QString>
#include <QtTest>
#include "mocfactory.h"
#include "debrojingraphgenerator.h"

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
    void test_transpose();

    void graphShoultBeCreated();
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
     AbstractDigraph<test_vertex_type>* testGraph = TestGraphFactory::newInstance<test_vertex_type>(test_mode);
     testGraph->add_link(0,1);
     testGraph->add_link(1,2);
     testGraph->add_link(1,3);
     testGraph->add_link(1,4);
     testGraph->add_link(1,5);
     testGraph->add_link(5,1);
     QCOMPARE(testGraph->out_degree(1),4);
}

void TestSuiteTest::test_transpose()
{

}

void TestSuiteTest::graphShoultBeCreated()
{
    const string str = "1 4 1 3 ";
    std::istringstream stm(str);
    Digraph<string>* graph = DeBrojinGraphGenerator::generate(stm);
    QCOMPARE((graph != NULL), true);
}

QTEST_APPLESS_MAIN(TestSuiteTest)

#include "tst_testsuitetest.moc"
