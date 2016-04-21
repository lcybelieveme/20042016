///
///@date   2016-04-20 21:16:58
///
 
 
 
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::fstream;

int main(int argc,char**argv)
{
	fstream fs(*(argv+1),std::ios::in|std::ios::out);
	if(!fs.good())
	{
		cout<<"fstream error"<<endl;
		return -1;
	}
#if 1	
	string str;
	while(getline(cin,str),!cin.eof())
	{
		fs<< str <<endl;
	}
#endif
	fs.seekg(0, std::ios::beg);  //每次读写的时候需要思考指针的位置

	string str1;

	while(getline(fs,str1))
	{
		cout<<str1<<endl;
	}
	
	return 0;
}	
