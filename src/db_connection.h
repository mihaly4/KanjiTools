#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include <string>
#include <queue>

namespace sql
{
    class Driver;
    class Connection;
}
namespace std
{
    class thread;
}

struct query_t
{
    std::string statement;
    void (*f)(void * obj,void * arg);
    void * obj;
};

class DB_Connection
{
public:
    DB_Connection();
    void AddQuery(query_t q);
private:    
    std::string username;
    std::string password;
    std::string hostname;
    
    std::string GetValue(std::string KeyValue);    
    bool LoadSettings();

    sql::Driver *driver;
    sql::Connection *con;
    static void thread_func(DB_Connection * c);
    std::thread * thread;
    std::queue<query_t> * queue;
};
#endif
