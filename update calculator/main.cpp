/********************************
Author:chenjiaquan     Date:2016/04/18     version:1.1
********************************/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <iostream>
#include <string>
#include <queue>
#include "Scan.h"
#include "Print.h"
#include "Calculation.h"
using namespace std;

int main(int argc, char* argv[])
{
	string input,input1; //�����ַ���

	queue<string> strs,strs1;

	Scan scan;

	Print print;

	Calculation calcula;

	cin>>input1;

	if(input1=="-a")
	{
		cin>>input; //�����ַ���

		cout<<input<<"="<<" "<<calcula.output(scan.ToStringQueue(input));

	}
	else
	{
		if(scan.ToStringQueue(input1).empty())
		{
			cout<<"input error"<<endl; // ���� 
		}
		
		else
		 cout<<calcula.output(scan.ToStringQueue(input1))<<endl;
	}

	return 0; //��������ֵ
}
