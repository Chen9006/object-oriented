
#include "Scan.h"
#include <iostream>
using namespace std;

Scan::Scan(void)
{
}


Scan::~Scan(void)
{
}

queue<string> Scan::ToStringQueue(string input)
{
	queue<string> strs;  //建立队列 strs

	string temp="";  //定义一个空字符串 temp


	for (unsigned int i = 0; i < input.size(); i++)
	{

		if (  (isdigit(input[i]) )  || input[i] == '.' || input[i] == '-')
		{
			if (input[i] == '-')
			{
				if ( (i == 0)|| (i>=1  && input[i-1] == '(') )
				{
					temp = "-";
				}


				else
				{

					strs.push(temp);
					temp.clear();
					strs.push("-");
				}
			}

			else
			{
				temp += input[i];
			}
				
				
			if(temp.size()>10) //当输入的数字超过10位
			{
				queue<string> rs; //定义一个空队列
				return rs; //返回该空队列
			}
			
		}

		else  // 该字符为四则运算的运算符或括号
		{
			if (!temp.empty())
			{
				strs.push(temp);
				temp.clear();
			}

			temp = input[i];

			if (!temp.empty())
			{
				strs.push(temp);
				temp.clear();
			}
		}
	}

	if (!temp.empty())
	{
		strs.push(temp);
	}

	return strs;
}
