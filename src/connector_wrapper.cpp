#include <string>
#include "connector_wraper.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>


sql::Driver * get_driver_instance()
{
    return new sql::Driver();
}

QSqlDatabase ololo;
sql::Driver::Driver()
{
    ololo =::QSqlDatabase::addDatabase("QMYSQL");
    db = & ololo;

}
sql::Connection * sql::Driver::connect(std::string host, std::string login, std::string pass)
{
    db->setHostName(QString::fromStdString(host));
    db->setUserName(QString::fromStdString(login));
    db->setPassword(QString::fromStdString(pass));
    return new sql::Connection(db);
}

void sql::Connection::setSchema(std::string name)
{
    db->setDatabaseName(QString::fromStdString(name));

    if (!db->open())
    {
      QMessageBox::critical(0, QObject::tr("Database Error"),
                db->lastError().text());
    }
}

sql::Statement * sql::Connection::createStatement()
{
    return new sql::Statement();
}

sql::ResultSet * sql::Statement::executeQuery(std::string query)
{
    qr = new QSqlQuery(QString::fromStdString(query));
    if(!qr->isValid())
    {
        //QMessageBox::critical(0, QObject::tr("Database Error"),
         //         qr->lastError().text());
        qDebug() << qr->lastError().text();
    }
    return new sql::ResultSet(qr);

}

bool sql::ResultSet::next()
{
    return res->next();
}

std::string sql::ResultSet::getString(int idx)
{
    return res->value(idx-1).toString().toStdString();
}

int sql::ResultSet::getInt(int idx)
{
    return res->value(idx-1).toInt();
}

int sql::ResultSet::rowsCount()
{
    return res->size();
}

std::string sql::SQLException::what()
{
    return "this should be fixed...";
}

