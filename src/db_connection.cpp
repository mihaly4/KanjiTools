
#include "db_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <iostream>
#include <fstream>
#include <thread>
#include <queue>
#include <time.h>

//void thread_func(DB_Connection * c);
DB_Connection::DB_Connection()
{
    m_bConnected = true;
    if(LoadSettings())
    {
        queue = new std::queue<query_t>();
        thread = new std::thread(thread_func,this);

    }
}
void DB_Connection::thread_func(DB_Connection * c)
{
    sql::Statement *stmt;
    sql::ResultSet *res;
    try
    {
        /* Create a connection */
        c->driver = get_driver_instance();
        c->con = c->driver->connect("tcp://"+c->hostname, c->username.c_str(), c->password.c_str());
        /* Connect to the MySQL test database */
        c->con->setSchema("test");

        stmt = c->con->createStatement();
        res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
        while (res->next())
        {
          std::cout << "\t... MySQL replies: ";
          /* Access column data by alias or column name */
          std::cout << res->getString("_message") << std::endl;
          std::cout << "\t... MySQL says it again: ";
          /* Access column fata by numeric offset, 1 is the first column */
          std::cout << res->getString(1) << std::endl;
          c->m_bConnected = true;
          std::cout << "Was connection successfull?\n";
        }
        delete res;
        delete stmt;
        //delete con;
    }
    catch(...)
    {
        std::cout << "Unable to connect to MySQL server.\nSomething is fucked up! :(((\n";
    }

    while(true)
    {
        while(!c->queue->empty() && c->m_bConnected)
        {
            query_t q = c->queue->front();
            c->queue->pop();

            try
            {
                sql::Statement *stmt= c->con->createStatement();
                sql::ResultSet *res= stmt->executeQuery(q.statement.c_str());
                if(q.f)
                    q.f(q.obj,res);
                delete stmt;
                if(!q.f && res && stmt)
                    delete res;
            }
            catch(sql::SQLException & ex)
            {
                std::cout << q.statement <<"\n";
                std::cout<<"problems:\n"<<ex.what();
            }
        }

        //std::cout<<"tick\n";
        sleep(1);
    }
}


std::string DB_Connection::GetValue(std::string KeyValue)
{
    size_t start = KeyValue.find_first_of('=');
    start+=2;
    return KeyValue.substr(start,KeyValue.size() - start - 1);
}

bool DB_Connection::LoadSettings()
{
    std::ifstream sets;
    sets.open("dbsettings.cfg");
    if(sets.is_open())
    {
	while(!sets.eof())
	{
	    std::string kv;
	    std::getline (sets,kv);		
	    if(kv.find("username")!=std::string::npos)
	    {
		username = GetValue(kv);
        //std::cout <<"username is |"<<username<<"|\n";
	    }
	    else if(kv.find("password")!=std::string::npos)
	    {
		password = GetValue(kv);
        //std::cout << "password is |"<<password<<"|\n";
	    }
	    else if(kv.find("hostname")!=std::string::npos)
	    {
		hostname = GetValue(kv);
        //std::cout << "hostaname is |"<<hostname<<"|\n";
	    }
	}
	sets.close();
	return true;
    }
    else
    {
	std::cout <<"no dbsettings.cfg found!\n";
	return false;
    }
}

void DB_Connection::AddQuery(query_t q)
{
    queue->push(q);
}

void * DB_Connection::ExecQuery(std::string q)
{
    sql::ResultSet *res;
    try
    {
        sql::Statement *stmt= con->createStatement();
        res= stmt->executeQuery(q.c_str());
        delete stmt;

    }
    catch(sql::SQLException & ex)
    {
        std::cout << q <<"\n";
        std::cout<<"problems:\n"<<ex.what();
    }
    return res;
}


