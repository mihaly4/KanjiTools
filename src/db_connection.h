#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include <string>

class DB_Connection
{
public:
    DB_Connection();
private:    
    std::string username;
    std::string password;
    std::string hostname;
    
    std::string GetValue(std::string KeyValue);    
    bool LoadSettings();
};
#endif
