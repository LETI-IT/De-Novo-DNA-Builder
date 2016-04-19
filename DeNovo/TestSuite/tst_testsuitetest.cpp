#include <QString>
#include <QtTest>
#include "mocfactory.h"

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
};

TestSuiteTest::TestSuiteTest()
{
    /**
      change it when real will be done
      **/
    test_mode=0;
}

void TestSuiteTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void TestSuiteTest::test_check_add_link()
{
    IGraph<vertex_type>* testGraph = GraphFactory::newInstance(test_mode);
    testGraph->add_link(0,1);
    QCOMPARE(testGraph->is_linked(0,1),true);
}

void TestSuiteTest::test_adjacency()
{
    IGraph<vertex_type>* testGraph = GraphFactory::newInstance(test_mode);
    testGraph->add_link(0,1);
    testGraph->add_link(1,2);
    testGraph->add_link(1,3);

    vector<vertex_type> actual = testGraph->adjacency(test_mode);
    vector<vertex_type> expect;
    expect.push_back(0);
    expect.push_back(2);
    expect.push_back(3);
    QCOMPARE(actual,expect);
}

void TestSuiteTest::test_reacheble()
{
    IGraph<vertex_type>* testGraph = GraphFactory::newInstance(test_mode);
    testGraph->add_link(1,2);
    testGraph->add_link(2,3);
    QCOMPARE(testGraph->is_reach(1,3),true);
}


QTEST_APPLESS_MAIN(TestSuiteTest)

#include "tst_testsuitetest.moc"
