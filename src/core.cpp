#include "core.h"
#include "db_connection.h"
#include "kanji_module.h"
#include "user_account_module.h"
Core::Core()
{
    m_iAccountType = ACCOUNT_TYPE_ERROR;
    m_pCon = new DB_Connection();
    m_pKanjiModule = new KanjiModule(this);
    m_pUserAccountModule = new UserAccountModule(this);
}

int Core::Authenticate(std::string name,std::string pass)
{
    if(name=="master" && pass=="master")
    {
	m_iAccountType = ACCOUNT_TYPE_ADMIN;
	return 0;
    }
    return -1;
}

void Core::AddQuery(std::string q, void (*f)(void * obj,void * arg),void * obj)
{
    query_t qe;
    qe.statement = q;
    qe.f = f;
    qe.obj = obj;
    m_pCon->AddQuery(qe);
}

void Core::AddKanji(std::string kanji,std::string on,std::string kun,std::string meaning,std::string examples)
{
    m_pKanjiModule->AddKanji(kanji,on,kun,meaning,examples);
}

void Core::LoadMaterial(int mat_id)
{
    m_pKanjiModule->LoadMaterial(mat_id);
}

kanji_t Core::NextKanji()
{
    return m_pKanjiModule->NextKanji();
}

kanji_t Core::PreviousKanji()
{
    return m_pKanjiModule->PreviousKanji();
}

void Core::AddUser(user_t u)
{
    m_pUserAccountModule->AddUser(u);
}

void Core::UpdateUser(user_t u)
{
    m_pUserAccountModule->UpdateUser(u);
}
