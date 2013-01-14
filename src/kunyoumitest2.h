#ifndef KUNYOUMITEST2_H
#define KUNYOUMITEST2_H
#include "basetest.h"


class KunYoumiTest2 : public BaseTest
{
public:
    void PrepareCase(case_t &c);
    std::string GetType(){return "kun-youmi-2";}
    int GetTestVarFontSize(){return 14;}
    int GetTestQueFontSize(){return 64;};
};


#endif // KUNYOUMITEST2_H
