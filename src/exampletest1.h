#ifndef EXAMPLETEST1_H
#define EXAMPLETEST1_H

#include "basetest.h"

class ExampleTest1 : public BaseTest
{
    std::vector<case_t> m_lCases;
    void PrepareAllCases();
public:
    ExampleTest1();
    void PrepareCase(case_t &c);
    std::string GetType(){return "example-1";}
    int GetTestVarFontSize(){return 14;}
    int GetTestQueFontSize(){return 72;};
    int GetTestCaseCount();
};


#endif // EXAMPLETEST1_H
