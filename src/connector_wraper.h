#ifndef CONNECTOR_WRAPER_H
#define CONNECTOR_WRAPER_H
class QSqlDatabase;
class QSqlQuery;
class QSqlResult;
namespace sql
{

    class SQLException
    {
    public:
        std::string what();
    };

    class ResultSet
    {
        QSqlQuery * res;
    public:
        ResultSet(QSqlQuery * res)
        {
            this->res = res;
        }

        bool next();
        std::string getString(int idx);
        int getInt(int idx);
        int rowsCount();
    };
	class Statement
	{
        QSqlQuery * qr;
    public:
        ResultSet * executeQuery(std::string query);
	};
    class Connection
    {
        ::QSqlDatabase *  db;
    public:
        Connection(::QSqlDatabase *  db)
        {
            this->db = db;
        }
        ~Connection();

        void setSchema(std::string name);
        Statement * createStatement();
    };
	class Driver
	{
        ::QSqlDatabase *  db;
	public:
        Driver();
        ~Driver();


		Connection * connect(std::string host,std::string login,std::string pass);
	};
};
sql::Driver * get_driver_instance();
#endif
