#ifndef KUNYOUMITEST2_H
#define KUNYOUMITEST2_H
#include "basetest.h"


class KunYoumiTest2 : public BaseTest
{
public:
    KunYoumiTest2();
    ~KunYoumiTest2(){}
    void PrepareCase(case_t &c);
    std::string GetType(){return "on-youmi-1";}
    int GetTestVarFontSize(){return 72;}
    int GetTestQueFontSize(){return 14;};
};


#endif // KUNYOUMITEST2_H
