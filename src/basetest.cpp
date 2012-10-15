#include "basetest.h"
#include "kanji_module.h"
#include "core.h"
#include <sstream>
#include <iostream>

#define min(a,b)((a)<(b)?(a):(b))
#define max(a,b)((a)>(b)?(a):(b))

BaseTest::BaseTest()
{
    m_iCurrentCase=0;
    m_bFinished = false;
    m_vMistakenKanji.clear();
}

case_t BaseTest::NextCase()
{
    case_t case_;
    if(m_iCurrentCase<m_pKanjiModule->KanjiCount())
        PrepareCase(case_);
    else
    {
        for(int i=0;i<4;i++)
            case_.variants[i] = "";
        std::stringstream tc,ac;
        tc << m_pKanjiModule->KanjiCount();
        ac <<m_pKanjiModule->KanjiCount()-m_vMistakenKanji.size();
        case_.question = "Test Finished!\nYou have correctly answered "+ac.str()+" of "+tc.str() ;
        if(!m_bFinished)
        {
            m_bFinished = true;
            SaveResults();
        }
    }
    m_iCurrentCase = min(m_iCurrentCase+1,m_pKanjiModule->KanjiCount());
    return case_;
}

void BaseTest::PrepareCase(case_t &c)
{

}

void BaseTest::SaveResults()
{
    std::stringstream mid;
    mid << m_iTestID;
    m_pCore->AddQuery("INSERT INTO kanjitools.testresults (`Material_ID`,`Test_type`,`Person_ID`) VALUES(\""+mid.str()+"\", \""+GetType()+"\",\""+m_pCore->GetUser().id+"\");",NULL,NULL);
    std::string q = "INSERT INTO kanjitools.kanjiinresult (`kanji`,`Result_ID`) VALUES";
    for(int i=0;i<m_vMistakenKanji.size();i++)
    {
        if(i>0)
            q+=",";
        q+=(" (\""+m_vMistakenKanji[i]+"\",(SELECT `Result_ID` FROM kanjitools.testresults WHERE `Result_ID` = LAST_INSERT_ID()) )");
        //q+=(" (SELECT \""+m_vMistakenKanji[i]+"\", `Result_ID` FROM kanjitools.testresults WHERE `Result_ID` = LAST_INSERT_ID()))");
    }
    q+=";";
    //std::cout << q <<"\n";
    if(m_vMistakenKanji.size())
        m_pCore->AddQuery(q,NULL,NULL);
}

void BaseTest::Answer(int variant)
{
    if(m_iCorrentAnswer!=variant && m_iCurrentCase<=m_pKanjiModule->KanjiCount())
    {
        m_vMistakenKanji.push_back(m_pKanjiModule->GetKanji(m_iCurrentCase-1).kanji);
    }
}

int BaseTest::GetTestVarFontSize()
{
    return 14;
}
