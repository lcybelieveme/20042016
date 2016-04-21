///
///@date   2016-04-20 19:11:40
///
 
 
#include <string.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#if 0
class student
{
public:
	student();
	student(char*,int);
	student(const student&);
	student& operator=(const student&);
	~student();
private:
	static void*operator new(size_t size){}   //重载new运算符并私有化，不能生产堆对象
	char *_name;
	int _id;
};
#endif

#if 0
class student
{
public:
	student();
	student(char*,int);
	student(const student&);
	student& operator=(const student&);
	void destroy()   //由于析构函数私有，只能创建一个公有函数成员释放对象的指针
	{
		delete this;
	}
private:
	~student(){}            //析构函数私有后不能创建栈对象
	char*_name;
	int _id;
};
#endif


class student
{
public:
	static student* getstupointer(); //构造函数私有后不能创建栈对象，此时需定义这个类的静态成员函数来调用构造函数
									 //来new一个新对象
	student(const student &);
	student& operator=(const student&);
	~student();

private:	
	student(){};
	student(char *,int){};
	char *_name;
	int _id;
};

student* student::getstupointer()
{
	student *t=new student;
	return t;
}

#if 0
student::student()
:_id(1000)
{
	_name=new char[1];
}

student::student(char*name,int id)
:_id(id)
{
	_name=new char[strlen(name)+1];
	strcpy(_name,name);
}
#endif


student::student(const student &stu)
:_id(stu._id)
{
	this->_name=new char[strlen(stu._name)+1];
	strcpy(_name,stu._name);
}

#if 1
student::~student()
{
	delete []_name;
}
#endif

int main()
{
//	student stu;

//	student *stu1=new student;         //new运算符被重载成私有成员

	student *stu=student::getstupointer();		
}
