#ifndef KUNYOUMITEST1_H
#define KUNYOUMITEST1_H

#include "basetest.h"


class KunYoumiTest1 : public BaseTest
{
public:
    void PrepareCase(case_t &c);
    std::string GetType(){return "kun-youmi-1";}
    int GetTestVarFontSize(){return 72;}
    int GetTestQueFontSize(){return 14;};
};


#endif // KUNYOUMITEST1_H
