#ifndef ONYOUMITEST1_H
#define ONYOUMITEST1_H
#include "basetest.h"

class OnYoumiTest1 : public BaseTest
{
public:
    OnYoumiTest1();
    ~OnYoumiTest1(){}
    void PrepareCase(case_t &c);
    std::string GetType(){return "on-youmi-1";}
    int GetTestVarFontSize(){return 72;}
    int GetTestQueFontSize(){return 14;};
};

#endif // ONYOUMITEST1_H
