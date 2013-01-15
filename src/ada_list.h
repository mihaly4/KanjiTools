#ifndef ADA_LIST_H
#define ADA_LIST_H

struct NodeData_t
{
    char data[1024];
    unsigned long method;
    unsigned long obj;
};
extern "C"  void adathreadinit();
extern "C"  void adathreadfinal();
extern "C" void push_back(const char * data,int len,unsigned long method, unsigned long obj);
extern "C" NodeData_t pop_front();
extern "C" int empty();

#endif // ADA_LIST_H
