#include "Scan.h"
#include <iostream>
using namespace std;
Scan::Scan(void)
{
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
	queue<string> strs;
	string temp="";
	for(unsigned int i=0;i<input.size();i++)
	{
		if(temp.size()>10)
		{
			cout<<temp<<":³¬³ö10Î»"<<endl;
			queue<string> rs;
			return rs;
		}
		if(charset.find(input[i])!= charset.end())
		{
			if(temp!="")
			{
				strs.push(temp);	
				temp.clear();
			}
			temp.push_back(input[i]);
			strs.push(temp);
			temp.clear();
		}
		else
		{
			temp += input[i];
		}
	}
	if(temp!="")
	{
		strs.push(temp);
		temp.clear();
	}
	return strs;
}
