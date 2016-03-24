#include "Scan.h"
#include <iostream>
using namespace std;
Scan::Scan(void)
{
	//set �����������������ķ���Ԫ��//

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
	queue<string> strs;  //�������� strs

	string temp="";  //����һ�����ַ��� temp

	for (unsigned int i=0; i<input.size(); i++)  //��������ַ����������
	{
		if (temp.size()>10)  //������ַ����е�ĳ���ַ�����10λ
		{
			cout<<temp<<":����10λ"<<endl;

			queue<string> rs;  //����һ���ն��� rs

			return rs;
		}

		if (charset.find(input[i])!= charset.end())  //�ַ����еĵ�i���ַ���Ϊ���������еķ���
		{
			if (temp!="")  //�ַ���temp��Ϊ��
			{
				strs.push(temp); //���ַ���temp�е�Ԫ�ؼ������strs

				temp.clear();  //���ַ���temp���
			}

			temp.push_back(input[i]); //���ַ���tempβ����Ӹ��ַ�

			strs.push(temp);

			temp.clear();  //���ַ���temp���
		}
		else
		{
			temp += input[i];  //�����ַ�ƴ�ӵ� temp��
		}
	}

	if (temp!="")  //�ַ���temp��Ϊ��
	{
		strs.push(temp);  //���ַ���temp�е��ַ��������strs

		temp.clear();
	}
	return strs;
}
