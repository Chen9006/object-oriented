#include "Print.h"


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
		cout << strs.front();
		strs.pop();
	}
}

void Print::result(double number,string argv,string string)
{
	ofstream in(argv,ios::app);

	if(string!="")
	{
       in<<string<<endl; //�������
	}

	else

	{
        in<<number<<endl;

	}

	in.close();
	   
}


