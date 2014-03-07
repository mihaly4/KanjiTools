#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include <string>
#include <queue>
#ifdef WIN32
#include <windows.h>
#endif
#include "common.h"

namespace sql
{
    class Driver;
    class Connection;
}
namespace std
{
    class thread;
}
class ADA_SAFE_LIST;

#ifdef WIN32
#define THREAD_TYPE DWORD WINAPI
#define THREAD_OBJ void*
#else
#define THREAD_TYPE void
#define THREAD_OBJ std::thread*
#endif

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
    ~DB_Connection();
    void AddQuery(query_t q);
    void * ExecQuery(std::string q);
    db_settings_t GetDBSettings();
    void SetDBSettings(db_settings_t & sets);
    bool Connect();
    bool IsConnected();
    bool SaveSettings();
private:    
    std::string username;
    std::string password;
    std::string hostname;
    
    std::string GetValue(std::string KeyValue);    
    bool LoadSettings();

    sql::Driver *driver;

    sql::Connection *con;

    static THREAD_TYPE thread_func(void * arg);
    THREAD_OBJ thread;
    std::queue<query_t> * queue;
    bool m_bConnected;
    bool exit;

};
#endif
