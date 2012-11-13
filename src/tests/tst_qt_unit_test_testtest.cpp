#include <QString>
#include <QtTest>
#include <iostream>
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
#include <QtGui/QDialog>
#include <QRadioButton>
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
    void test_userdialog1();

    void test_logindialog0();
    void test_logindialog1();

//   void test_user_account_module0(); //--
//    void test_user_account_module1(); //--

//    void test_kanjidialog0(); //--

    void test_kanji_module0();//--

    void test_WholeApplication0();//--
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
        std::cout<< "Enter host IP:";
        std::cin >> sets.host;
        std::cout<< "Enter root password:";
        std::cin >> sets.password;
        sets.user = "root";

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
    QTest::keyClicks(le,"testname1");

    le = ud.findChild<QLineEdit*>("lineEdit_2");
    QTest::keyClicks(le,"testsurname1");

    le = ud.findChild<QLineEdit*>("lineEdit_3");
    QTest::keyClicks(le,"testlogin1");

    le = ud.findChild<QLineEdit*>("lineEdit_4");
    QTest::keyClicks(le,"testpass1");

    QRadioButton * rb = ud.findChild<QRadioButton*>("radioButton_2");
    QTest::mouseClick(rb,Qt::LeftButton);

    QDialogButtonBox * bb = ud.findChild<QDialogButtonBox*>("buttonBox");
    QPushButton * ab  = bb->button(QDialogButtonBox::Ok);
    QTest::mouseClick(ab,Qt::LeftButton);

    user_t u = ud.GetUser() ;

    QVERIFY2(u.name=="testname1","User name does not match.") ;
    QVERIFY2(u.surename=="testsurname1", "User surename does not match.");
    QVERIFY2(u.login=="testlogin1", "User login does not match.");
    QVERIFY2(u.password=="testpass1", "User password does not match.");
    QVERIFY2(u.account_type==2, "Account type does not match.");
    //a.exec();
}

void Qt_unit_test_testTest::test_userdialog1(){
    int argc =1;
    char * argv[1];
    argv[0]= QDir::currentPath().toAscii().data();
    QApplication a(argc, argv,1);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    UserDialog ud;
    ud.show();
    QLineEdit * le = ud.findChild<QLineEdit*>("lineEdit");
    QTest::keyClicks(le,"testname1");

    le = ud.findChild<QLineEdit*>("lineEdit_2");
    QTest::keyClicks(le,"testsurname1");

    le = ud.findChild<QLineEdit*>("lineEdit_3");
    QTest::keyClicks(le,"testlogin1");

    le = ud.findChild<QLineEdit*>("lineEdit_4");
    QTest::keyClicks(le,"testpass1");

    QRadioButton * rb = ud.findChild<QRadioButton*>("radioButton_2");
    QTest::mouseClick(rb,Qt::LeftButton);

    /*
    QDialogButtonBox * bb = ud.findChild<QDialogButtonBox*>("buttonBox");
    QPushButton * ab  = bb->button(QDialogButtonBox::Cancel);
    QTest::mouseClick(ab,Qt::LeftButton);*/

    user_t u = ud.GetUser() ;
    QVERIFY2(u.name=="testname1", "User name does not match.") ;
    QVERIFY2(u.surename=="testsurname1", "User surename does not match.");
    QVERIFY2(u.login=="testlogin1", "User login does not match.");
    QVERIFY2(u.password=="testpass1", "User password does not match.");
    QVERIFY2(u.account_type==2, "Account type does not match.");
    // This testcase doesn't check whether user has to be added or not
}



void Qt_unit_test_testTest::test_logindialog0(){
    int argc =1;
    char * argv[1];
    argv[0]= QDir::currentPath().toAscii().data();
    QApplication a(argc, argv,1);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    LoginDialog ld;
    ld.show();
    QLineEdit * le = ld.findChild<QLineEdit*>("lineEdit");

    QTest::keyClicks(le," ");
    QVERIFY2(ld.GetLoginName()==QString(" "), "Login name does not match.");

    QTest::keyClicks(le,"testLogin1");
    QVERIFY2(ld.GetLoginName()==QString(" testLogin1"), "Login name does not match.");
}

void Qt_unit_test_testTest::test_logindialog1(){
    int argc =1;
    char * argv[1];
    argv[0]= QDir::currentPath().toAscii().data();
    QApplication a(argc, argv,1);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    LoginDialog ld;
    ld.show();
    QLineEdit * le = ld.findChild<QLineEdit*>("lineEdit_2");

    QTest::keyClicks(le," ");
    QVERIFY2(ld.GetPassword()==QString(" "), "Password does not match.");

    QTest::keyClicks(le,"testPass1");
    QVERIFY2(ld.GetPassword()==QString(" testPass1"), "Password does not match.");
}

/*void Qt_unit_test_testTest::test_user_account_module0(){
    Core * core = new Core();
    UserAccountModule uam(core);
    user_t u;
    u.id = "987456";
    u.login = "testLogin1";
    u.password = "testPass1";
    u.name = "testName1";
    u.surename = "testSurname1";
    u.account_type = 1;
    uam.AddUser(u);
    delete core;
    Sleep(5000);
}

void Qt_unit_test_testTest::test_user_account_module1(){
    int argc =1;
    char * argv[1];
    argv[0]= QDir::currentPath().toAscii().data();
    QApplication a(argc, argv,1);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    Core * core = new Core();
    UserDialog ud;
    ud.SetCore(core);
    ud.show();

    UserAccountModule uam(core);
    user_t u;
    u.id = "987456";
    u.login = "testLogin2";
    u.password = "testPass2";
    u.name = "testName2";
    u.surename = "testSurname2";
    u.account_type = 2;
    uam.UpdateUser(u);


    Sleep(5000);
    ud.SetUser(u.id);
    Sleep(5000);
    delete core;

    QLineEdit * le = ud.findChild<QLineEdit*>("lineEdit");
    std::cout << endl << endl << le->text().toStdString() << endl << endl;
    QVERIFY2(le->text().toStdString()==u.name, "User name does not match.");

    le = ud.findChild<QLineEdit*>("lineEdit_2");
    QVERIFY2(le->text().toStdString()==u.surename, "User surname does not match.");

    le = ud.findChild<QLineEdit*>("lineEdit_3");
    QVERIFY2(le->text().toStdString()==u.login, "User login does not match.");

    le = ud.findChild<QLineEdit*>("lineEdit_4");
    QVERIFY2(le->text().toStdString()==u.password, "User password does not match.");

}*/


/*void Qt_unit_test_testTest::test_kanjidialog0()
{
    int argc =1;
    char * argv[1];
    argv[0]= QDir::currentPath().toAscii().data();
    QApplication a(argc, argv,1);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    KanjiDialog kd;
    kd.show();
    QLineEdit * le = ud.findChild<QLineEdit*>("lineEdit");
    QTest::keyClicks(le,"testKanji");

    le = ud.findChild<QLineEdit*>("lineEdit_2");
    QTest::keyClicks(le,"testOnYoumi");

    le = ud.findChild<QLineEdit*>("lineEdit_3");
    QTest::keyClicks(le,"testKunYoumi");

    QPlainTextEdit * pte = ud.findChild<QPlainTextEdit*>("plainTextEdit");
    QTest::keyClicks(pte,"testMeaning");

    pte = ud.findChild<QPlainTextEdit*>("plainTextEdit_2");
    QTest::keyClicks(pte,"testUsage");

    QDialogButtonBox * qbb = ud.findChild<QDialogButtonBox*>("buttonBox");
    QPushButton * qbbOk  = bb->button(QDialogButtonBox::Ok);
    QTest::mouseClick(qbbOk,Qt::LeftButton);

    kanji_t u = kd.get ;
    // Here should be Kanji Check
}*/


void Qt_unit_test_testTest::test_kanji_module0(){

}

void Qt_unit_test_testTest::test_WholeApplication0(){
    int argc =1;
    char * argv[1];
    argv[0]= QDir::currentPath().toAscii().data();
    QApplication a(argc, argv,1);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    KanjiToolsWindow ktw;
    ktw.show();

    LoginDialog *ld = ktw.findChild<LoginDialog*>("m_pLoginDialog");
    Sleep(1000);
    QLineEdit * le = ld->findChild<QLineEdit*>("lineEdit");
    QTest::keyClicks(le,"master");

    le = ld->findChild<QLineEdit*>("lineEdit_2");
    QTest::keyClicks(le,"master");

    QDialogButtonBox * bb = ld->findChild<QDialogButtonBox*>("buttonBox");
    QPushButton * qbbOk  = bb->button(QDialogButtonBox::Ok);
    QTest::mouseClick(qbbOk,Qt::LeftButton);

    a.exit();

}


QTEST_APPLESS_MAIN(Qt_unit_test_testTest)

#include "tst_qt_unit_test_testtest.moc"
