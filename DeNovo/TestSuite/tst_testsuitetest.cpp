#include <QString>
#include <QtTest>
#include "mocfactory.h"

class TestSuiteTest : public QObject
{
    Q_OBJECT

public:
    TestSuiteTest();

private Q_SLOTS:
    void testCase1();
    void test_check_add_link();
    void test_adjacency();
    void test_reacheble();
};

TestSuiteTest::TestSuiteTest()
{
}

void TestSuiteTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void TestSuiteTest::test_check_add_link()
{
    IGraph* testGraph = GraphFactory::newInstance(0);
    testGraph->add_link(0,1);
    QCOMPARE(testGraph->is_linked(0,1),true);
}

void TestSuiteTest::test_adjacency()
{
    IGraph* testGraph = GraphFactory::newInstance(0);
    testGraph->add_link(0,1);
    testGraph->add_link(1,2);
    testGraph->add_link(1,3);

    vector<vertex_type> actual = testGraph->adjacency(1);
    vector<vertex_type> expect;
    expect.push_back(0);
    expect.push_back(2);
    expect.push_back(3);
    QCOMPARE(actual,expect);
}

void TestSuiteTest::test_reacheble()
{
    IGraph* testGraph = GraphFactory::newInstance(0);
    testGraph->add_link(1,2);
    testGraph->add_link(2,3);
    QCOMPARE(testGraph->is_reach(1,3),true);
}


QTEST_APPLESS_MAIN(TestSuiteTest)

#include "tst_testsuitetest.moc"
