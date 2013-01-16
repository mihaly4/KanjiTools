#include "ada_safe_list.h"
#include <QDebug>

extern "C"  void adathreadinit();
extern "C"  void adathreadfinal();
extern "C" void push_back(const char * data,int len,unsigned long method, unsigned long obj);
extern "C" NodeData_t pop_front();
extern "C" int empty();

ADA_SAFE_LIST* ADA_SAFE_LIST::instance = NULL;

ADA_SAFE_LIST::ADA_SAFE_LIST()
{
    adathreadinit();
}
ADA_SAFE_LIST::~ADA_SAFE_LIST()
{
    adathreadfinal();
}
bool ADA_SAFE_LIST::empty()
{
    return ::empty();
}
query_t ADA_SAFE_LIST::pop_front()
{
    NodeData_t ada_node = ::pop_front();
    query_t q;
    q.statement = std::string(ada_node.data);
    q.f = (void (*)(void *,void*))(void*)ada_node.method;
    q.obj = (void*)ada_node.obj;
    //c->queue->pop();
    qDebug() << "Poped query from ADA list.";// Everything is now probably fucked :(
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
    qDebug() << "Added query to ADA list :(";
}

ADA_SAFE_LIST *ADA_SAFE_LIST::GetInstance()
{
    return (instance?instance:instance = new ADA_SAFE_LIST());
}
