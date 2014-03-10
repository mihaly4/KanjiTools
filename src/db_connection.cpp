
#include "db_connection.h"

/*#include <cppconn/driver.h>
 * #include <cppconn/exception.h>
 * #include <cppconn/resultset.h>
 * #include <cppconn/statement.h>*/

#include "connector_wraper.h"

#include <iostream>
#include <fstream>

#include <queue>
#include <time.h>

#ifdef WIN32
#include <windows.h>
#else
#include <thread>
#include <unistd.h>
#endif

#include <QDebug>






//void thread_func(DB_Connection * c);
DB_Connection::DB_Connection()
{
    port = 3306;
    exit = false;
    m_bConnected = false;
    queue = new std::queue<query_t>();
    if(LoadSettings())
    {
	Connect();
    }
}

DB_Connection::~DB_Connection()
{
    exit = true;
    
    #ifdef WIN32
    WaitForSingleObject(thread,INFINITE);
    #else
    thread->join();
    #endif
    delete con;
    delete driver;
    delete queue;
    
}
THREAD_TYPE DB_Connection::thread_func(void * arg)
{
    DB_Connection * c = (DB_Connection*) arg;
    
    while(!c->exit)
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
	#ifdef WIN32
	Sleep(1000);
	#else
	sleep(1);
	#endif
    }
    std::cout << "connection thread exited\n";
}

db_settings_t DB_Connection::GetDBSettings()
{
    return db_settings_t(hostname,username,password,"This field is unused");
    /*db_settings_t sets;
     *    sets.host = hostname;
     *    sets.user = username;
     *    sets.password = password;
     *    sets.dbname = "This field is unused";
     *    return sets;*/
}

void DB_Connection::SetDBSettings(db_settings_t &sets)
{
    hostname = sets.host;
    username = sets.user;
    password = sets.password;
}

bool DB_Connection::Connect()
{
    if(m_bConnected)
	return true;
    DB_Connection * c =this;
    sql::Statement *stmt;
    sql::ResultSet *res;
    try
    {
	/* Create a connection */
	c->driver = get_driver_instance();
	if(!c->driver)
	{
	    std::cout<<"unable to get driver instance"<<"\n";
	    return false;
	}
	
	c->con = c->driver->connect(c->hostname, c->username.c_str(), c->password.c_str(),c->port);
	/* Connect to the MySQL test database */
	c->con->setSchema("test");
	
	stmt = c->con->createStatement();
	res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
	while (res->next())
	{
	    std::cout << "\t... MySQL replies: ";
	    /* Access column data by alias or column name */
	    std::cout << res->getString(1) << std::endl;
	    //std::cout << "\t... MySQL says it again: ";
	    /* Access column fata by numeric offset, 1 is the first column */
	    //std::cout << res->getString(1) << std::endl;
	    c->m_bConnected = true;
	    //std::cout << "Was connection successfull?\n";
	}
	delete res;
	delete stmt;
	//delete con;
    }
    catch(...)
    {
	std::cout << "Unable to connect to MySQL server.\nSomething is fucked up! :(((\n";
	return false;
    }
    
    //queue = new std::queue<query_t>();
    #ifndef WIN32
    thread = new std::thread(thread_func,this);
    #else
    thread = CreateThread(NULL,0,thread_func,this,0,0);
    #endif
    return true;
}

bool DB_Connection::IsConnected()
{
    return m_bConnected;
}

bool DB_Connection::SaveSettings()
{
    std::ofstream sets;
    sets.open("dbsettings.cfg");
    if(sets.is_open())
    {
	sets <<"hostname=\""<<hostname<<"\"\n";
	sets <<"username=\""<<username<<"\"\n";
	sets <<"password=\""<<password<<"\"\n";
	sets <<"port=\""<<port<<"\"\n";
	sets.close();
	return true;
    }
    else
    {
	std::cout <<"unable to create dbsettings.cfg!\n";
	return false;
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
		std::cout <<"username is |"<<username<<"|\n";
	    }
	    else if(kv.find("password")!=std::string::npos)
	    {
		password = GetValue(kv);
		std::cout << "password is |"<<password<<"|\n";
	    }
	    else if(kv.find("hostname")!=std::string::npos)
	    {
		hostname = GetValue(kv);
		std::cout << "hostaname is |"<<hostname<<"|\n";
	    }
	    else if(kv.find("port")!=std::string::npos)
	    {
		port = atoi(GetValue(kv).c_str());
		std::cout << "port is |"<<hostname<<"|\n";
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


