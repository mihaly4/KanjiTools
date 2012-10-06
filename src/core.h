#ifndef CORE_H
#define CORE_H

#include "db_connection.h"
#include <string>

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
    Core()
    {
        m_iAccountType = ACCOUNT_TYPE_ERROR;
        m_pCon = new DB_Connection();
    }
    int Authenticate(std::string name,std::string pass)
    {
        if(name=="master" && pass=="master")
        {
            m_iAccountType = ACCOUNT_TYPE_ADMIN;
            return 0;
        }
        return -1;
    }

private:
    int m_iAccountType;
    DB_Connection * m_pCon;
};
#endif
