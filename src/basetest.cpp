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
    if(m_bFinished)
    {
	m_tCurrentCase.question = "Test finished. Go away.";
	return m_tCurrentCase;
    }
    if(m_iCurrentCase<GetTestCaseCount())
        PrepareCase(m_tCurrentCase);
    else
    {
        for(int i=0;i<4;i++)
            m_tCurrentCase.variants[i] = "";
        std::stringstream tc,ac;
        tc << GetTestCaseCount();
        ac <<GetTestCaseCount()-m_vMistakenKanji.size();
        m_tCurrentCase.question = "Test Finished!\nYou have correctly answered "+ac.str()+" of "+tc.str() ;
        if(!m_bFinished)
        {
            m_bFinished = true;
            SaveResults();
        }
    }
    m_iCurrentCase = min(m_iCurrentCase+1,GetTestCaseCount());
    return m_tCurrentCase;
}

void BaseTest::PrepareCase(case_t &c)
{

}

void BaseTest::SaveResults()
{
    std::stringstream mid;
    mid << m_iTestID;
    m_pCore->AddQuery("DELETE FROM kanjitools.testresults WHERE `Material_ID`=\""+mid.str()+"\" AND `Test_type`=\""+GetType()+"\" AND `Person_ID`=\""+m_pCore->GetUser().id+"\";",NULL,NULL);
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
    if(m_bFinished)
	return;
    if(m_tCurrentCase.correct_variant!=variant && m_iCurrentCase<=GetTestCaseCount())
    {
	for(int i=0;i<m_vMistakenKanji.size();i++)
	    if(m_vMistakenKanji[i] == m_tCurrentCase.kanji)
		return;	
        m_vMistakenKanji.push_back(m_tCurrentCase.kanji);
    }
}

int BaseTest::GetTestVarFontSize()
{
    return 14;
}

std::string	BaseTest::GetCorrectAnswer()
{
    return m_tCurrentCase.variants[m_tCurrentCase.correct_variant];
}

std::string BaseTest::GetStatus()
{
    std::stringstream ss;
    ss << "Mistakes:" <<m_vMistakenKanji.size()<<"/"<<m_iCurrentCase <<" of "<< GetTestCaseCount();
    return ss.str();
}

bool BaseTest::IsFinished()
{
    return m_bFinished;
}

int BaseTest::GetTestCaseCount()
{
    return m_pKanjiModule->KanjiCount();
}

