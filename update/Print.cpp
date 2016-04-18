#include "Print.h"
#include <iostream>
using namespace std;
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
		cout << strs.front() <<endl;
		strs.pop();
	}
}
