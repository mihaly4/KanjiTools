#include "core.h"
#include "db_connection.h"
#include "kanji_module.h"
#include "user_account_module.h"
#include <iostream>
#include "onyoumitest1.h"
#include "onyoumitest2.h"
#include "kunyoumitest1.h"
#include "kunyoumitest2.h"

Core::Core()
{
    m_pCon = new DB_Connection();
    m_pKanjiModule = new KanjiModule(this);
    m_pUserAccountModule = new UserAccountModule(this);
    m_pTest = NULL;
}

void Core::Authenticate(std::string name,std::string pass,void (*f)(void* obj,void*arg),void * obj)
{
    if(name=="master" && pass=="master")
    {
        f(obj,NULL);
    }
    else
    {
        m_pUserAccountModule->Authenticate(name,pass,f,obj);
    }
}

void Core::AddQuery(std::string q, void (*f)(void * obj,void * arg),void * obj)
{
    query_t qe;
    qe.statement = q;
    qe.f = f;
    qe.obj = obj;
    m_pCon->AddQuery(qe);
}

/*void Core::AddKanji(std::string kanji,std::string on,std::string kun,std::string meaning,std::string examples)
{
    m_pKanjiModule->AddKanji(kanji,on,kun,meaning,examples);
}

void Core::LoadMaterial(int mat_id,void (*f)(void * obj),void *obj)
{
    m_pKanjiModule->LoadMaterial(mat_id,f,obj);
}

void Core::LoadKanjiFromResult(std::string mat_id, void (*f)(void *), void *obj)
{
    m_pKanjiModule->LoadKanjiFromResult(mat_id,f,obj);
}

kanji_t Core::NextKanji()
{
    return m_pKanjiModule->NextKanji();
}

kanji_t Core::PreviousKanji()
{
    return m_pKanjiModule->PreviousKanji();
}*/

void Core::AddUser(user_t u)
{
    m_pUserAccountModule->AddUser(u);
}

void Core::UpdateUser(user_t u)
{
    m_pUserAccountModule->UpdateUser(u);
}

void * Core::ExecQuery(std::string q)
{
    return m_pCon->ExecQuery(q);
}

void Core::SetUser(user_t u)
{
    m_User = u;
}

/*void Core::CreateTest(std::string test,int mat_id, void (*f)(void*obj),void * obj)
{
    if(test=="on-youmi-1")
    {
        m_pTest = new OnYoumiTest1();
    }
    else if(test=="on-youmi-2")
    {
        m_pTest = new OnYoumiTest2();
    }
    else if(test=="kun-youmi-1")
    {
        m_pTest = new KunYoumiTest1();
    }
    else if(test=="kun-youmi-2")
    {
        m_pTest = new KunYoumiTest2();
    }
    m_pTest->Init(this,mat_id);
    m_pTest->SetKanjiModule(m_pKanjiModule);

    LoadMaterial(mat_id,f,obj);
}

case_t Core::NextCase()
{
    return m_pTest->NextCase();
}

void Core::Answer(int variant)
{
    m_pTest->Answer(variant);
}

int Core::GetTestVarFontSize()
{
    return m_pTest->GetTestVarFontSize();
}

int Core::GetTestQueFontSize()
{
    return m_pTest->GetTestQueFontSize();
}*/

db_settings_t Core::GetDBSettings()
{
    return m_pCon->GetDBSettings();
}

KanjiModule* Core::GetKanjiModule()
{
    return m_pKanjiModule;
}
