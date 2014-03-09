#ifndef D3XX_H
#define D3XX_H

class d3xx
{
public:
	std::string * ksdb[60];// = new std::string * [60];
	std::string GetKanji(int idx)
	{
	    return ksdb[idx][0];
	}
	std::string GetOn(int idx)
	{
	    return (ksdb[idx][1]=="x"?"":ksdb[idx][1]) + (ksdb[idx][2] == "x"?"":("\n" + ksdb[idx][2]));
	}
	std::string GetKun(int idx)
	{
	    return (ksdb[idx][3]=="x"?"":ksdb[idx][3]) + (ksdb[idx][4] == "x"?"":("\n" + ksdb[idx][4]));
	}
	std::string GetMeaning(int idx)
	{
	    return ksdb[idx][8] + (ksdb[idx][9] == "x"?"":("\n" + ksdb[idx][9])) + (ksdb[idx][10] == "x"?"":("\n" + ksdb[idx][10]));
	}
	std::string GetExamples(int idx)
	{
	    return 
	    (ksdb[idx][11] == "x"?"":(       ksdb[idx][11] + " - " + ksdb[idx][17])) + 
	    (ksdb[idx][12] == "x"?"":("\n" + ksdb[idx][12] + " - "+ksdb[idx][18])) + 
	    (ksdb[idx][13] == "x"?"":("\n" + ksdb[idx][13] + " - "+ksdb[idx][19]));
	}
	virtual std::string GetGroupName() = 0;
};

#endif