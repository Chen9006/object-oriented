#include "Print.h"


Print::Print(void)
{
}


Print::~Print(void)
{
}



void Print::show(queue<string> strs)  //定义一个函数用于输出队列 
{
	while (!strs.empty())  //队列strs不为空时 
	{
		cout << strs.front();
		strs.pop();
	}
}

void Print::result(double number,string argv,string string)
{
	ofstream in(argv,ios::app);

	if(string!="")
	{
       in<<string<<endl; //输出报错
	}

	else

	{
        in<<number<<endl;

	}

	in.close();
	   
}


