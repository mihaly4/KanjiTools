#ifndef MEANINGTEST1_H
#define MEANINGTEST1_H

#include "basetest.h"


class MeaningTest1 : public BaseTest
{
public:
    void PrepareCase(case_t &c);
    std::string GetType(){return "meaning-1";}
    int GetTestVarFontSize(){return 14;}
    int GetTestQueFontSize(){return 72;};
};


#endif // MEANINGTEST1_H
