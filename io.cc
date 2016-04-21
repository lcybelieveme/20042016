///
///@date   2016-04-20 20:16:39
///
 
 
 
#include <iostream>
#include <string>
#include <limits>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	int n;
	while(cin>>n,!cin.eof())
	{
		if(cin.bad())
		{
			cout<<"big problem"<<endl;
			return -1;
		}
		if(cin.fail())
		{
			cout<<"wrong type try again"<<endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			continue;
		}
		cout<<n<<endl;
	}
}


//cin,ignore(std::numeric_limits<std::streamsize>::max(),'\n');
