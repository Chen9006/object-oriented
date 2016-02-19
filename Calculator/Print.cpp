#include "Print.h"
#include <iostream>
using namespace std;
Print::Print(void)
{
}

Print::~Print(void)
{
}

void Print::show(queue<string> strs)
{
	while (!strs.empty())  
	{  
		cout << strs.front() <<endl;  
		strs.pop();  
	} 
}
