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

    //authentication
    void Authenticate(std::string name,std::string pass,void (*f)(void* obj,void*arg),void * obj);
    void AddUser(user_t u);
    void UpdateUser(user_t u);

    //users
    void SetUser(user_t u);
    user_t GetUser(){return m_User;}


    //kanji
    KanjiModule* GetKanjiModule();
    /*void AddKanji(std::string kanji,std::string on,std::string kun,std::string meaning,std::string examples);
    void LoadMaterial(int mat_id, void (*f)(void *)=NULL, void *obj=NULL);
    void LoadKanjiFromResult(std::string mat_id, void (*f)(void *)=NULL, void *obj=NULL);
    kanji_t NextKanji();
    kanji_t PreviousKanji();*/

    //tests
    /*void CreateTest(std::string test, int mat_id, void (*f)(void *), void *obj);
    case_t NextCase();
    void Answer(int variant);
    int GetTestVarFontSize();
    int GetTestQueFontSize();*/

    //database
    db_settings_t GetDBSettings();
    void AddQuery(std::string q, void (*f)(void * obj,void * arg) = NULL,void * obj = NULL);
    void * ExecQuery(std::string q);

private:
    DB_Connection * m_pCon;
    KanjiModule * m_pKanjiModule;
    UserAccountModule * m_pUserAccountModule;
    user_t m_User;
    BaseTest * m_pTest;

};
#endif
