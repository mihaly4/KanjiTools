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
#include <QListWidget>
#include <iostream>
#include <QListWidgetItem>
#include <QListWidget>
#include <QList>

#ifdef __linux__
#include <unistd.h>
#endif

#ifdef __linux__
    #define myWait sleep(1)
#else
    #define myWait Sleep(1000)
#endif


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
        sets.password = "4202mv";
        sets.host = "188.112.150.117";

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

//    QDialogButtonBox * bb = ud.findChild<QDialogButtonBox*>("buttonBox");
//    QPushButton * ab  = bb->button(QDialogButtonBox::Ok);
//    QTest::mouseClick(ab,Qt::LeftButton);

    user_t u = ud.GetUser() ;

    QVERIFY2(u.name=="testname1","User name does not match.") ;
    QVERIFY2(u.surename=="testsurname1", "User surename does not match.");
    QVERIFY2(u.login=="testlogin1", "User login does not match.");
    QVERIFY2(u.password=="testpass1", "User password does not match.");
    QVERIFY2(u.account_type==2, "Account type does not match.");
    //a.exec();
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

void waitForEventsHappen(){
    for(int i=0; i<10; i++)
        myWait;// waits untl all queries are processed

    //std::cout<<"reload users\n";
    //ktw.ReloadUsers();    /// <------  reload users after changes
    for(int i=0; i<5; i++)
        myWait;// waits until users reloaded

    QCoreApplication::processEvents(); /// <------- check this out! If u have problems with updatting window try this first!
    std::cout<<"waiting events\n";
    for(int i=0; i<2; i++)
        myWait;// waits until all signals are passed to slots

}

void userDialogFillIn(UserDialog * ud, user_t u, QString btn){
    QLineEdit * le = ud->findChild<QLineEdit*>("lineEdit");
    QTest::keyClicks(le,QString::fromStdString(u.name));
    le = ud->findChild<QLineEdit*>("lineEdit_2");
    QTest::keyClicks(le,QString::fromStdString(u.surename));
    le = ud->findChild<QLineEdit*>("lineEdit_3");
    QTest::keyClicks(le,QString::fromStdString(u.login));
    le = ud->findChild<QLineEdit*>("lineEdit_4");
    QTest::keyClicks(le,QString::fromStdString(u.password));
    QString s;
    if(u.account_type==ACCOUNT_TYPE_ADMIN)
        s="radioButton_1";
    else if(u.account_type==ACCOUNT_TYPE_TEACHER)
        s="radioButton_2";
    else if(u.account_type==ACCOUNT_TYPE_STUDENT)
        s="radioButton_3";
    else
        s="";
    QRadioButton * rb = ud->findChild<QRadioButton*>(s);
    if(rb)
        QTest::mouseClick(rb,Qt::LeftButton);
    else
        std::cout << "Account type can't be chosen\n";

    if(btn=="Ok")
    {
        QDialogButtonBox * bb = ud->findChild<QDialogButtonBox*>("buttonBox");
        QPushButton * ab  = bb->button(QDialogButtonBox::Ok);
        QTest::mouseClick(ab,Qt::LeftButton);
    }else if(btn=="Cancel"){
        QDialogButtonBox * bb = ud->findChild<QDialogButtonBox*>("buttonBox");
        QPushButton * ab  = bb->button(QDialogButtonBox::Cancel);
        QTest::mouseClick(ab,Qt::LeftButton);
    }else
        std::cout << "No button pressed after fill in UserDialog form";
}

void Qt_unit_test_testTest::test_WholeApplication0(){
    int argc =1;
    char * argv[1];
    argv[0]= QDir::currentPath().toAscii().data();
    QApplication a(argc, argv,1);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    LoginDialog::ResetCurrentDialog();

    KanjiToolsWindow ktw;
    ktw.show();

    //LOGIN
    LoginDialog *ld = LoginDialog::GetCurrentDialog();
    while(!ld)
    {
        myWait;
        ld = LoginDialog::GetCurrentDialog();
    }
    if(ld)qDebug()<<"Dialog found";
    else qDebug()<<"Dialog not found";
    QLineEdit * le = ld->findChild<QLineEdit*>("lineEdit");
    QTest::keyClicks(le,"master");

    le = ld->findChild<QLineEdit*>("lineEdit_2");
    QTest::keyClicks(le,"master");

    QDialogButtonBox * bb = ld->findChild<QDialogButtonBox*>("buttonBox");
    QPushButton * qbbOk  = bb->button(QDialogButtonBox::Ok);
    QTest::mouseClick(qbbOk,Qt::LeftButton);

    myWait;
    Core * core = ktw.getCore();
    user_t u = core->GetUser();
    std::cout << endl << endl << u.login ;
    QVERIFY2(u.name=="Admin","User's name isn't Admin");
    QVERIFY2(u.surename=="Adminovich","User's surname isn't Adminovich");
    QVERIFY2(u.account_type==ACCOUNT_TYPE_ADMIN, "User's account type isn't ACCOUNT_TYPE_ADMIN");

    //RECREATING TABLES
    QWidget * tw = ktw.findChild<QWidget*>("tab");
    QTest::mouseClick(tw,Qt::LeftButton);
    QPushButton *qpb = tw->findChild<QPushButton*>("pushButton");
    QTest::mouseClick(qpb,Qt::LeftButton);


    // ADDING NEW USER
    tw = ktw.findChild<QWidget*>("tab_3");
    QTest::mouseClick(tw,Qt::LeftButton);
    qpb = tw->findChild<QPushButton*>("pushButton_2");
    QTest::mouseClick(qpb,Qt::LeftButton);

    UserDialog * ud = ktw.getUserDialog();
    while(!ud)
    {
        std::cout << "Search for ud\n" ;
        myWait;
        ud = ktw.getUserDialog();
    }

    u.name="testname1";
    u.surename="testsurname1";
    u.login="testlogin1";
    u.password="testpass1";
    u.account_type=ACCOUNT_TYPE_TEACHER;
    userDialogFillIn(ud, u, "Ok");

    u.name="testname2";
    u.surename="testsurname2";
    u.login="testlogin2";
    u.password="testpass2";
    userDialogFillIn(ud, u, "Cancel");

    waitForEventsHappen();


    QListWidget * lw = ktw.findChild<QListWidget*>("listWidget");

/*    if(!lw)
        std::cout << " lw was not found!!! \n";
    else
        std::cout << " lw was found \n";
    lw->selectAll();
*/
    bool found1=false;
    bool found2=false;
    int found1index;
    for(int i=0; i<lw->count(); i++){
        if(lw->item(i)->text().contains("testname1")){
            found1=true;
            found1index=i;
        }
        if(lw->item(i)->text().contains("testname2"))
            found2=true;
    }
    QVERIFY2(found1,"Item containind 'testname1' was not found");
    QVERIFY2(!found2,"Item containind 'testname2' was found, but it shouldn't");

    //Removing "testname1" from users
    lw->setCurrentRow(found1index);
    qpb = tw->findChild<QPushButton*>("pushButton_3");
    QTest::mouseClick(qpb,Qt::LeftButton);      // Remove user btn

    waitForEventsHappen();

    found1=false;
    found2=false;
    for(int i=0; i<lw->count(); i++){
        if(lw->item(i)->text().contains("testname1")){
            found1=true;
            found1index=i;
        }
        if(lw->item(i)->text().contains("testname2"))
            found2=true;
    }
    QVERIFY2(!found1,"Item containind 'testname1' was found, but it shouldn't");
    QVERIFY2(!found2,"Item containind 'testname2' was found, but it shouldn't");
}


QTEST_APPLESS_MAIN(Qt_unit_test_testTest)

#include "tst_qt_unit_test_testtest.moc"
