#ifndef BASETEST_H
#define BASETEST_H
#include "common.h"
#include <vector>
#include <stdlib.h>

class KanjiModule;
class Core;
class BaseTest
{
protected:
    int             m_iCurrentCase;
    KanjiModule *   m_pKanjiModule;
    bool            m_bFinished;
    Core *          m_pCore;
    int             m_iTestID;
    std::vector<std::string> m_vMistakenKanji;
    case_t 	m_tCurrentCase;
public:
    BaseTest();
    virtual         ~BaseTest(){};
    void            SetKanjiModule(KanjiModule * mod){m_pKanjiModule = mod;}
    case_t          NextCase();
    virtual void    PrepareCase(case_t & c);
    void            SaveResults();
    void            Init(Core * core,int id){m_pCore = core,m_iTestID = id;};
    virtual std::string GetType(){return "base-test";};
    void            Answer(int variant);
    virtual int     GetTestVarFontSize();
    virtual int     GetTestQueFontSize(){return 14;};
    std::string		GetCorrectAnswer();
    std::string 	GetStatus();
    bool IsFinished();
    virtual int 	GetTestCaseCount();
    
};

#endif // BASETEST_H
