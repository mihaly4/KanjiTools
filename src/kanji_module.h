#ifndef KANJI_MODULE_H
#define KANJI_MODULE_H
#include <string>
#include <vector>
#include "common.h"



class Core;
class KanjiModule
{
private:
  Core * m_pCore;
  std::vector<kanji_t> kanji_list;
  static void kanji_loaded(void * obj, void * a);
  int cur_idx;
  void * m_pObj;
  void (*m_pF)(void*);

public:
  KanjiModule(Core * core);
  void AddKanji(std::string kanji,std::string on,std::string kun,std::string meaning,std::string examples);
  void LoadMaterial(int mat_id, void (*f)(void * obj),void * obj);
  kanji_t NextKanji();
  kanji_t PreviousKanji();




};

#endif
