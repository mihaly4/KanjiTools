#ifndef ADA_SAFE_LIST_H
#define ADA_SAFE_LIST_H
#include "db_connection.h"
struct NodeData_t
{
    char data[1024];
    unsigned long method;
    unsigned long obj;
};


class ADA_SAFE_LIST
{
public:    
    ~ADA_SAFE_LIST();
    bool empty();
    query_t pop_front();
    void push(query_t q);
    static ADA_SAFE_LIST * GetInstance();
private:
    static ADA_SAFE_LIST * instance;
    ADA_SAFE_LIST();
};

#endif // ADA_SAFE_LIST_H
