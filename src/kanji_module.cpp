#include "kanji_module.h"
#include "core.h"
#include <sstream>
#include <cppconn/resultset.h>

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

void KanjiModule::LoadMaterial(int mat_id)
{
    std::stringstream ss;
      ss << mat_id;

    std::string q = "SELECT * FROM kanjitools.kanji JOIN kanjitools.kanjiinmaterial ON ( kanjitools.kanji.kanji=kanjitools.kanjiinmaterial.kanji) WHERE `Material_ID` = "+ss.str()+";";

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
        kanji_t k = kanji_t(res->getString(1).asStdString(),
                            res->getString(2).asStdString(),
                            res->getString(3).asStdString(),
                            res->getString(4).asStdString(),
                            res->getString(5).asStdString());
        mod->kanji_list.push_back(k);
    }
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
