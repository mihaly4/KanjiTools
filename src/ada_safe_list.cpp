#include "ada_safe_list.h"
#include <QDebug>

extern "C" void adathreadinit();
extern "C" void adathreadfinal();
extern "C" void push_back(const char * data,int len,unsigned long method, unsigned long obj);
extern "C" NodeData_t pop_front();
extern "C" int list_empty();
extern "C" void clear();

ADA_SAFE_LIST* ADA_SAFE_LIST::instance = NULL;

ADA_SAFE_LIST::ADA_SAFE_LIST()
{
    adathreadinit();
    clear();
    qDebug() << "ADA list init.  State is "<<empty();
}
ADA_SAFE_LIST::~ADA_SAFE_LIST()
{
    adathreadfinal();
}
bool ADA_SAFE_LIST::empty()
{
    qDebug() << "Asked if is empty?" << list_empty();
    return list_empty();
}
query_t ADA_SAFE_LIST::pop_front()
{
    if(empty())
        throw;
    NodeData_t ada_node = ::pop_front();
    query_t q;
    q.statement = std::string(ada_node.data);
    q.f = (void (*)(void *,void*))(void*)ada_node.method;
    q.obj = (void*)ada_node.obj;
    //c->queue->pop();
   // qDebug() << "Poped query from ADA list." << q.statement.c_str();// Everything is now probably fucked :(
    return q;
}

void ADA_SAFE_LIST::push(query_t q)
{

    NodeData_t ada_node;
    if(q.statement.length()>1023)
        throw;
    strcpy(ada_node.data,q.statement.c_str());
    ada_node.method = (unsigned long)(void*)q.f;
    ada_node.obj = (unsigned long)q.obj;
    push_back(ada_node.data,q.statement.length()+1,ada_node.method,ada_node.obj);
   // qDebug() << "Added query to ADA list :(" << q.statement.c_str();
}

ADA_SAFE_LIST *ADA_SAFE_LIST::GetInstance()
{
    return (instance?instance:instance = new ADA_SAFE_LIST());
}
