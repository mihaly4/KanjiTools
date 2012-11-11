#include <QString>
#include <QtTest>
#include "../common.h"
#include "../db_connection.h"
#include "../connector_wraper.h"

#include "../userdialog.h"
#include "../kanji_module.h"
#include "../logindialog.h"
#include "../kanjitoolswindow.h"
#include "../kanjidialog.h"
#include "../core.h"
#include "../user_account_module.h"
#include "../basetest.h"
#include "../onyoumitest1.h"
#include "../onyoumitest2.h"
#include "../kunyoumitest1.h"
#include "../kunyoumitest2.h"
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QPushButton>
#include <iostream>


class Qt_unit_test_testTest : public QObject
{
    Q_OBJECT

    DB_Connection * m_pConnection;
    
public:
    Qt_unit_test_testTest();
    
private Q_SLOTS:
    void test_db_connection0();
    void test_db_connection1();
    void test_db_connection2();
    void test_db_connection3();
    void test_db_connection4();
    void test_db_connection5();

    void test_userdialog0();

    void test_user_account_module0();

    void test_kanji_module0();

    void test_WholeApplication0();
};

Qt_unit_test_testTest::Qt_unit_test_testTest()
{

}

void Qt_unit_test_testTest::test_db_connection0()
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
        /*std::cout<< "Enter host IP:";
        std::cin >> sets.host;
        std::cout<< "Enter root password:";
        std::cin >> sets.password;*/
        sets.user = "root";

        sets.host = "188.112.150.117" ;
        sets.password = "4202mv" ;
        m_pConnection->SetDBSettings(sets);
    }
}

void Qt_unit_test_testTest::test_db_connection1()
{
    // try connecting with settings
    QVERIFY2(m_pConnection->Connect(), "Connection to database failed.");
}

void Qt_unit_test_testTest::test_db_connection2()
{
    // test again
    QVERIFY2(m_pConnection->IsConnected(), "Connection to database failed.");
}

void Qt_unit_test_testTest::test_db_connection3()
{
    // try save settings
    QVERIFY2(m_pConnection->SaveSettings(), "Connection to database failed.");
    // and kill connection
    delete m_pConnection;
}

void Qt_unit_test_testTest::test_db_connection4()
{
    // create connection now with settings from file
    m_pConnection = new DB_Connection();
    //should connect cuz settings file found
    QVERIFY2(m_pConnection->IsConnected(), "Have settings but somehow now connected? Check your settings!");
}

void Qt_unit_test_testTest::test_db_connection5()
{
    m_pConnection->Connect();
    QVERIFY(m_pConnection->IsConnected());
}



void Qt_unit_test_testTest::test_userdialog0()
{
    int argc =1;
    char * argv[1];
    argv[0]= QDir::currentPath().toAscii().data();
    QApplication a(argc, argv,1);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    UserDialog ud;
    ud.show();
    QLineEdit * le = ud.findChild<QLineEdit*>("lineEdit");
    QDialogButtonBox * bb = ud.findChild<QDialogButtonBox*>("buttonBox");
    QTest::keyClicks(le,"master");
    QPushButton* ab  = bb->button(QDialogButtonBox::Ok);
    QTest::mouseClick(ab,Qt::LeftButton);
    //a.exec();
}

void Qt_unit_test_testTest::test_user_account_module0(){


}

void Qt_unit_test_testTest::test_kanji_module0(){

}

void Qt_unit_test_testTest::test_WholeApplication0(){
/*    int argc;
    char *argv[0];
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    KanjiToolsWindow k;
    k.show();
    k.close();
    QTest::keyClicks(k.m_pLoginDialog->lineEdit="master");
    QTest::keyClicks(k.m_pLoginDialog->lineEdit_2="master");*/
}


QTEST_APPLESS_MAIN(Qt_unit_test_testTest)

#include "tst_qt_unit_test_testtest.moc"
