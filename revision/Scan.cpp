#include "Scan.h"
#include <iostream>
using namespace std;
Scan::Scan(void)
{
	//set 容器里添加四则运算的符号元素//

	charset.insert('+');
	charset.insert('-');
	charset.insert('*');
	charset.insert('/');
	charset.insert ('(');
	charset.insert(')');
}

Scan::~Scan(void)
{
}

queue<string> Scan::ToStringQueue(string input)
{
	queue<string> strs;  //建立队列 strs

	string temp="";  //定义一个空字符串 temp

	for (unsigned int i=0; i<input.size(); i++)  //对输入的字符串逐个检索
	{
		if (temp.size()>10)  //输入的字符串中的某个字符超过10位
		{
			cout<<temp<<":超出10位"<<endl;

			queue<string> rs;  //定义一个空队列 rs

			return rs;
		}

		if (charset.find(input[i])!= charset.end())  //字符串中的第i个字符不为四则运算中的符号
		{
			if (temp!="")  //字符串temp不为空
			{
				strs.push(temp); //将字符串temp中的元素加入队列strs

				temp.clear();  //将字符串temp清空
			}

			temp.push_back(input[i]); //在字符串temp尾部添加该字符

			strs.push(temp);

			temp.clear();  //将字符串temp清空
		}
		else
		{
			temp += input[i];  //将该字符拼接到 temp后
		}
	}

	if (temp!="")  //字符串temp不为空
	{
		strs.push(temp);  //将字符串temp中的字符加入队列strs

		temp.clear();
	}
	return strs;
}
