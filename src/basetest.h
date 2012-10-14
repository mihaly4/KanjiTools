#ifndef BASETEST_H
#define BASETEST_H
#include "common.h"

class KanjiModule;
class BaseTest
{
private:
    KanjiModule * m_pKanjiModule;
public:
    BaseTest();
    void SetKanjiModule(KanjiModule * mod){m_pKanjiModule = mod;}
    case_t NextCase();
};

#endif // BASETEST_H
