#ifndef CORE_H
#define CORE_H

#include "db_connection.h"


class Core
{
public:
    Core()
    {
	m_pCon = new DB_Connection();
    }
private:
    DB_Connection * m_pCon;
};
#endif
