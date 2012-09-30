#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

//#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <iostream>
#include <fstream>
#include <string>

#define SETS_SIZE 256

class DB_Connection
{
public:
    DB_Connection()
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
		con = driver->connect("tcp://127.0.0.1:3306", username.c_str(), password.c_str());
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
		std::cout << "Something is fucked up! :(((\n";
	    }
	}
    }
private:
    
    std::string username;
    std::string password;
    
    std::string GetValue(std::string KeyValue)
    {
	size_t start = KeyValue.find_first_of('=');
	start+=2;
	return KeyValue.substr(start,KeyValue.size() - start - 1);
    }
    
    bool LoadSettings()
    {
	std::ifstream sets;
	sets.open("dbsettings.cfg");
	if(sets.is_open())
	{
	    while(!sets.eof())
	    {
		std::string kv;
		std::getline (sets,kv);		
		if(strstr(kv.c_str(),"username"))
		{
		    username = GetValue(kv);
		    std::cout <<"username is |"<<username<<"|\n";
		}
		else if(strstr(kv.c_str(),"password"))
		{
		    password = GetValue(kv);
		    std::cout << "password is |"<<password<<"|\n";
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
};
#endif
