#ifndef MEANINGTEST2_H
#define MEANINGTEST2_H

#include "basetest.h"


class MeaningTest2 : public BaseTest
{
public:
    void PrepareCase(case_t &c);
    std::string GetType(){return "meaning-2";}
    int GetTestVarFontSize(){return 72;}
    int GetTestQueFontSize(){return 14;};
};


#endif // MEANINGTEST2_H
