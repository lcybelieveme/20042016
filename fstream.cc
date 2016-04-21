///
///@date   2016-04-20 20:38:37
///
 
 
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;

int main(int argc,char**argv)
{
	ifstream ifs(*(argv+1));
	if(!ifs.good())
	{
		cout<<"ifstream open error"<<endl;
		return -1;
	}

	string str;
	vector<string> strVec;
	strVec.reserve(10);
	
	cout<<strVec.capacity()<<endl;

	while(getline(ifs,str))
	{
		strVec.insert(strVec.end(),str);
	}

	for(int i=0;i<strVec.size();i++)
	{
		cout<<strVec[i]<<endl;
	}

	ofstream ofs(*(argv+2));

	for(int i=0;i<strVec.size();++i)
	{
		ofs << strVec[i] << endl;
	}
	










	return 0;
}
