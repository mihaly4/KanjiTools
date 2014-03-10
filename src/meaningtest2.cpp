#include "meaningtest2.h"
#include "kanji_module.h"
#include <iostream>



void MeaningTest2::PrepareCase(case_t &c)
{
    kanji_t k = m_pKanjiModule->GetKanji(m_iCurrentCase);
    //std::cout<<"<<index = "<<m_iCurrentCase <<" "<<k.on_youmi<< "\n";
    int max_kanji = m_pKanjiModule->KanjiCount()-1;
    c.question = k.meaning;
    float r=rand()/(float)RAND_MAX;
    int correct = r*3+0.5;
    m_iCorrentAnswer = correct;
    c.variants[correct] = k.kanji;
    for(int i=0;i<4;i++)
    {
        while(i!=correct)
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
