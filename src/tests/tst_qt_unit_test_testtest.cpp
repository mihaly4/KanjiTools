#include <QString>
#include <QtTest>
#include "../common.h"
#include "../db_connection.h"
#include <iostream>

class Qt_unit_test_testTest : public QObject
{
    Q_OBJECT

    DB_Connection * m_pConnection;
    
public:
    Qt_unit_test_testTest();
    
private Q_SLOTS:
    void testCase0();
    void testCase1();
    void testCase2();
    void testCase3();
    void testCase4();
};

Qt_unit_test_testTest::Qt_unit_test_testTest()
{

}

void Qt_unit_test_testTest::testCase0()
{
    //removing settings file
    QFile::remove("dbsettings.cfg");
    //creating connection
    m_pConnection = new DB_Connection();
    //should not connect cuz no settings file found
    QVERIFY2(!m_pConnection->IsConnected(), "Have no settings but somehow connected? WTF?.");
    //enter connection settings
    if(!m_pConnection->IsConnected())
    {
        db_settings_t sets;
        std::cout<< "Enter host IP:";
        std::cin >> sets.host;
        std::cout<< "Enter root password:";
        std::cin >> sets.password;
        sets.user = "root";
        m_pConnection->SetDBSettings(sets);
    }
}

void Qt_unit_test_testTest::testCase1()
{
    // try connecting with settings
    QVERIFY2(m_pConnection->Connect(), "Connection to database failed.");
}

void Qt_unit_test_testTest::testCase2()
{
    // test again
    QVERIFY2(m_pConnection->IsConnected(), "Connection to database failed.");
}

void Qt_unit_test_testTest::testCase3()
{
    // try save settings
    QVERIFY2(m_pConnection->SaveSettings(), "Connection to database failed.");
    // and kill connection
    delete m_pConnection;
}

void Qt_unit_test_testTest::testCase4()
{
    // create connection now with settings from file
    m_pConnection = new DB_Connection();
    //should connect cuz settings file found
    QVERIFY2(m_pConnection->IsConnected(), "Have settings but somehow now connected? Check your settings!");
}

QTEST_APPLESS_MAIN(Qt_unit_test_testTest)

#include "tst_qt_unit_test_testtest.moc"
