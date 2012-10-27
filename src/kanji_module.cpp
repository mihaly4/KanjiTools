#include "kanji_module.h"
#include "core.h"
#include <sstream>
#include "connector_wraper.h"

#define min(a,b)((a)<(b)?(a):(b))
#define max(a,b)((a)>(b)?(a):(b))

KanjiModule::KanjiModule(Core * core)
{
    m_pCore = core;
}

void KanjiModule::AddKanji(std::string kanji,std::string on,std::string kun,std::string meaning,std::string examples)
{
    std::string q = "INSERT INTO kanjitools.kanji ( `kanji`,`on_youmi`,`kun_youmi`,`translations`,`examples`) VALUES(\""+kanji+"\",\""+on+"\",\""+kun+"\",\""+meaning+"\",\""+examples+"\");";

    m_pCore->AddQuery(q);
}

void KanjiModule::LoadMaterial(int mat_id, void (*f)(void * obj), void *obj)
{
    std::stringstream ss;
      ss << mat_id;

    std::string q = "SELECT * FROM kanjitools.kanji JOIN kanjitools.kanjiinmaterial ON ( kanjitools.kanji.kanji=kanjitools.kanjiinmaterial.kanji) WHERE `Material_ID` = "+ss.str()+";";
    m_pObj = obj;
    m_pF = f;
    //std::cout << "Loading material\n" <<q <<"\n";
    m_pCore->AddQuery(q,kanji_loaded,this);
}

void KanjiModule::LoadKanjiFromResult(std::string res_id, void (*f)(void *), void *obj)
{
    std::string q = "SELECT * FROM kanjitools.kanji JOIN kanjitools.kanjiinresult ON ( kanjitools.kanji.kanji=kanjitools.kanjiinresult.kanji) WHERE `Result_ID` = "+res_id+";";
    m_pObj = obj;
    m_pF = f;
    //std::cout << "Loading material\n" <<q <<"\n";
    m_pCore->AddQuery(q,kanji_loaded,this);
}

void KanjiModule::kanji_loaded(void *obj, void *a)
{

    KanjiModule * mod = (KanjiModule*)obj;

    mod->cur_idx = -1;
    mod->kanji_list.clear();
    sql::ResultSet *res=(sql::ResultSet *)a;
    while (res->next())
    {
        kanji_t k = kanji_t(res->getString(1),
                            res->getString(2),
                            res->getString(3),
                            res->getString(4),
                            res->getString(5));
        mod->kanji_list.push_back(k);
    }
    //printf("kanji module loaded %i kanji\n",res->rowsCount());
    /*if(mod->kanji_list.size()==0)   /// We should't get here under normal contitions
    {
        delete res;
        return;
    }*/
    delete res;
    if(mod->m_pF && mod->m_pObj)
        mod->m_pF(mod->m_pObj);
}

kanji_t KanjiModule::NextKanji()
{
    cur_idx = min(cur_idx+1,kanji_list.size()-1);
    return kanji_list[cur_idx];
}

kanji_t KanjiModule::PreviousKanji()
{
    cur_idx = max(0,cur_idx-1);
    return kanji_list[cur_idx];
}

kanji_t KanjiModule::GetKanji(int idx)
{
    //std::cout<<"index = "<<idx <<" of "<<KanjiCount()<<" "<<kanji_list[idx].on_youmi<< "\n";
    return kanji_list[idx];
}
