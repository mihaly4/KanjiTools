#ifndef CORE_H
#define CORE_H


#include <string>
#include "common.h"

class DB_Connection;
class KanjiModule;
class UserAccountModule;
class BaseTest;



class Core
{
public:
    Core();
    void Authenticate(std::string name,std::string pass,void (*f)(void* obj,void*arg),void * obj);
    void AddQuery(std::string q, void (*f)(void * obj,void * arg) = NULL,void * obj = NULL);
    void AddKanji(std::string kanji,std::string on,std::string kun,std::string meaning,std::string examples);
    void LoadMaterial(int mat_id, void (*f)(void *)=NULL, void *obj=NULL);
    kanji_t NextKanji();
    kanji_t PreviousKanji();
    void AddUser(user_t u);
    void UpdateUser(user_t u);
    void * ExecQuery(std::string q);
    void SetUser(user_t u);
    user_t GetUser(){return m_User;}
    void CreateTest(std::string test, int mat_id, void (*f)(void *), void *obj);
    case_t NextCase();
    void Answer(int variant);
    int GetTestVarFontSize();
    int GetTestQueFontSize();
    db_settings_t GetDBSettings();

private:
    DB_Connection * m_pCon;
    KanjiModule * m_pKanjiModule;
    UserAccountModule * m_pUserAccountModule;
    user_t m_User;
    BaseTest * m_pTest;

};
#endif
