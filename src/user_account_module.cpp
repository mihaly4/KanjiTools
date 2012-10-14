#include "user_account_module.h"
#include <sstream>
#include "core.h"
#include <cppconn/resultset.h>

void UserAccountModule::AddUser(user_t u)
{
    std::stringstream ss;
    ss << u.account_type;
    std::string q = "INSERT INTO kanjitools.person (`Login`,`Password`,`Name`,`Surename`,`account_type`) VALUES(\""+
            u.login+"\",\""+
            u.password+"\",\""+
            u.name+"\",\""+
            u.surename+"\","+
            ss.str()  +");";
    m_pCore->AddQuery(q);
}

void UserAccountModule::UpdateUser(user_t u)
{
    std::stringstream ss;
    ss << u.account_type;
    std::string q = "UPDATE kanjitools.person SET `Login` =\""+
            u.login+"\", `Password` = \""+
            u.password+"\", `Name` = \""+
            u.name+"\", `Surename` = \""+
            u.surename+"\", `account_type` = "+
            ss.str()  +" WHERE `Person_ID` = "+
            u.id+";";
    m_pCore->AddQuery(q);
}

void UserAccountModule::Authenticate(std::string name, std::string pass, void (*f)(void * obj,void *arg),void * obj)
{
    std::string q = "SELECT * FROM kanjitools.person WHERE `Login` = \""+name+"\" AND `password` = \""+pass+"\";";
    m_pCore->AddQuery(q,f,obj);
}
