#include "exampletest1.h"
#include "kanji_module.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <boost/algorithm/string/regex.hpp>

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) 
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) 
    {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) 
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

ExampleTest1::ExampleTest1() : BaseTest()
{
    m_lCases.clear();
    
}
int ExampleTest1::GetTestCaseCount()
{
    if(m_lCases.size() ==0)
	PrepareAllCases();
    return m_lCases.size();
}

void ExampleTest1::PrepareAllCases()
{
    m_lCases.clear();
    for(int i=0;i<m_pKanjiModule->KanjiCount();i++)
    {
	std::string example_string = m_pKanjiModule->GetKanji(i).examples;
	//std::cout << "Example string = " << example_string << std::endl;
	std::vector<std::string> examples = split(example_string,'\n');
	for(int j=0; j < examples.size(); j++)
	{
	    std::vector<std::string> word_reading_meaning = split(examples[j],'-');
	    //std::cout <<"WRM0="<<word_reading_meaning[0] << std::endl;
	    //std::cout <<"WRM1="<<word_reading_meaning[1] << std::endl;
	    std::vector<std::string> word_reading;
	    boost::algorithm::split_regex( word_reading, word_reading_meaning[0], boost::regex("（") ) ;
	    //std::cout <<"Split size = "<< word_reading.size() << std::endl;
	    //std::cout <<"WR0="<<word_reading[0] << std::endl;
	    //std::cout <<"WR1="<<word_reading[1] << std::endl;
	    
	    std::string word = word_reading[0];
	    
	    std::vector<std::string> reading_shit;
	    boost::algorithm::split_regex( reading_shit, word_reading[1], boost::regex("）") ) ;
	    
	    std::string reading = reading_shit[0];
	    std::string meaning = word_reading_meaning[1]; 
	    
	    case_t cs;
	    cs.question = word;
	    float r=rand()/(float)RAND_MAX;
	    cs.correct_variant = (int)(r*3+0.5);
	    cs.variants[cs.correct_variant] = reading;
	    cs.kanji = m_pKanjiModule->GetKanji(i).kanji;
	    m_lCases.push_back(cs);
	}
    }
}
void ExampleTest1::PrepareCase(case_t &c)
{
    if(m_lCases.size() ==0)
	PrepareAllCases();
    
    c = m_lCases[m_iCurrentCase];
    //std::cout<<"<<index = "<<m_iCurrentCase <<" "<<k.on_youmi<< "\n";
    int max_case = m_lCases.size()-1;
    for(int i=0;i<4;i++)
    {
        while(i!=c.correct_variant)
        {
            float r=rand()/(float)RAND_MAX;
            case_t cc = m_lCases[r*max_case+0.5];
            if(cc.variants[cc.correct_variant] == c.variants[c.correct_variant])
                continue;
            c.variants[i] = cc.variants[cc.correct_variant];
            break;
        }
    }
}
