 
#include "db_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <iostream>
#include <fstream>

DB_Connection::DB_Connection()
{
    if(LoadSettings())
    {
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
	try
	{
	    /* Create a connection */
	    driver = get_driver_instance();
	    con = driver->connect("tcp://"+hostname, username.c_str(), password.c_str());
	    /* Connect to the MySQL test database */
	    con->setSchema("test");

	    stmt = con->createStatement();
	    res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
	    while (res->next()) 
	    {
	      std::cout << "\t... MySQL replies: ";
	      /* Access column data by alias or column name */
	      std::cout << res->getString("_message") << std::endl;
	      std::cout << "\t... MySQL says it again: ";
	      /* Access column fata by numeric offset, 1 is the first column */
	      std::cout << res->getString(1) << std::endl;
	    }
	    delete res;
	    delete stmt;
	    delete con;
	}
	catch(...)
	{
	    std::cout << "Unable to connect to MySQL server.\nSomething is fucked up! :(((\n";
	}
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


