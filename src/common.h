#ifndef COMMON_H
#define COMMON_H

#include <string>


enum
{
    ACCOUNT_TYPE_ERROR=0,
    ACCOUNT_TYPE_ADMIN=1,
    ACCOUNT_TYPE_TEACHER,
    ACCOUNT_TYPE_STUDENT
};

struct kanji_t
{
    std::string kanji,on_youmi,kun_youmi,meaning,examples;
    kanji_t(std::string kanji,std::string on_youmi,std::string kun_youmi,std::string meaning,std::string examples)
    {
        this->kanji = kanji;
        this->on_youmi = on_youmi;
        this->kun_youmi = kun_youmi;
        this->meaning = meaning;
        this->examples = examples;
    }
};

struct user_t
{
    std::string id,name,surename,login,password;
    int account_type;
};

struct case_t
{
    std::string variants[4];
    std::string question;
};

struct test_result_t
{
    std::string id,test_type,test_id,person_id;
};

struct db_settings_t
{
    std::string host,user,password,dbname;
};

struct encore_t
{
    std::string result_id,test_name,test_type;
};

#endif
