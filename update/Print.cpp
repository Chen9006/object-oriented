#include "Print.h"
#include <iostream>
using namespace std;
Print::Print(void)
{
}

Print::~Print(void)
{
}

void Print::show(queue<string> strs)  //����һ����������������� 
{
	while (!strs.empty())  //����strs��Ϊ��ʱ 
	{
		cout << strs.front() <<endl;
		strs.pop();
	}
}
