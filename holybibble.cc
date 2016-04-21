///
///@date   2016-04-20 22:07:37
///
 
 
 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::stringstream;

class wordstatic
{
public:
	void read_file(string);
	void write_file(string);
private:
	vector<string> strvec;
	vector<int> intvec;
};

void wordstatic::read_file(string name)
{	
	const char *nam=name.c_str();
	ifstream ifs(nam);
	if(!ifs.good())
	{
		cout<<"fstream open error"<<endl;
		return;
	}
	
	string str;
	while(ifs>>str)
	{
		int i=0;
		for(i=0;i<strvec.size();++i)
		{
			if(strvec[i]==str)
			{
				intvec[i]++;
				break;
			}
		}
		if(i==strvec.size())
		{
			strvec.push_back(str);
			intvec.push_back(1);
		}
	}
	
}

void wordstatic::write_file(string name)
{
	const char *nam=name.c_str();
	ofstream ofs(nam,std::ios::out);
	for(int i=0;i<strvec.size();++i)
	{
		ofs<<strvec[i]<<"                                        "<<intvec[i]<<endl;
	}

}

int main(int argc,char**argv)
{
	if(argc!=3)
	{
		cout<<"argc error"<<endl;
		return -1;
	}
	wordstatic wdcount;
	string s1=*(argv+1);
	string s2=*(argv+2);

	wdcount.read_file(s1);
	wdcount.write_file(s2);

	return 0;
}
