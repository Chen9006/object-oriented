
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
	queue<string> strs;  //�������� strs

	string temp="";  //����һ�����ַ��� temp


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
				
				
			if(temp.size()>10) //����������ֳ���10λ
			{
				queue<string> rs; //����һ���ն���
				return rs; //���ظÿն���
			}
			
		}

		else  // ���ַ�Ϊ��������������������
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
