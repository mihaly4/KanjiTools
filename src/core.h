#ifndef CORE_H
#define CORE_H


#include <string>
#include "common.h"

class DB_Connection;
class KanjiModule;

enum
{
    ACCOUNT_TYPE_ERROR=0,
    ACCOUNT_TYPE_ADMIN=1,
    ACCOUNT_TYPE_TEACHER,
    ACCOUNT_TYPE_STUDENT
};


class Core
{
public:
    Core();
    int Authenticate(std::string name,std::string pass);
    int GetLevel()
    {
        return m_iAccountType;
    }
    void AddQuery(std::string q, void (*f)(void * obj,void * arg) = NULL,void * obj = NULL);
    void AddKanji(std::string kanji,std::string on,std::string kun,std::string meaning,std::string examples);
    void LoadMaterial(int mat_id);
    kanji_t NextKanji();

private:
    int m_iAccountType;
    DB_Connection * m_pCon;
    KanjiModule * m_pKanjiModule;
};
#endif
