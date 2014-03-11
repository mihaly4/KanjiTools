#include "kunyoumitest1.h"
#include "kanji_module.h"
#include <iostream>



void KunYoumiTest1::PrepareCase(case_t &c)
{
    kanji_t k = m_pKanjiModule->GetKanji(m_iCurrentCase);
    //std::cout<<"<<index = "<<m_iCurrentCase <<" "<<k.on_youmi<< "\n";
    int max_kanji = m_pKanjiModule->KanjiCount()-1;
    c.question = k.kun_youmi;
    float r=rand()/(float)RAND_MAX;
    c.correct_variant = r*3+0.5;
    c.kanji = k.kanji;
    c.variants[c.correct_variant] = k.kanji;
    for(int i=0;i<4;i++)
    {
        while(i!=c.correct_variant)
        {
            float r=rand()/(float)RAND_MAX;
            kanji_t cc = m_pKanjiModule->GetKanji(r*max_kanji+0.5);
            if(cc.kun_youmi == k.kun_youmi)
                continue;
            c.variants[i] = cc.kanji;
            break;
        }
    }
}
