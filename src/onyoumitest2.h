#ifndef ONYOUMITEST2_H
#define ONYOUMITEST2_H

#include "basetest.h"

class OnYoumiTest2 : public BaseTest
{
public:
    OnYoumiTest2();
    void PrepareCase(case_t &c);
    std::string GetType(){return "on-youmi-2";}
    int GetTestVarFontSize(){return 14;}
    int GetTestQueFontSize(){return 64;};
};

#endif // ONYOUMITEST2_H
