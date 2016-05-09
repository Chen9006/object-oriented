/********************************
Author:chenjiaquan     Date:2016/05/09     version:2.1
********************************/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include "Scan.h"
#include "Print.h"
#include "Calculation.h"
using namespace std;

int main(int argc, char* argv[])
{
	string input="",input1,input2=""; //定义字符串

	double num=0;

	queue<string> strs,strs1;

	Scan scan;

	Print print;

	Calculation calcula;

	if(argc==2)
	{
		input1=argv[1];

		if(scan.ToStringQueue(input1).empty())
		{
			cout<<"input error"<<endl; // 报错
		}
		else

			cout<<calcula.output(scan.ToStringQueue(input1))<<endl;

	}

	if(argc==3)
	{
		input1=argv[2];

		if(scan.ToStringQueue(input1).empty())
		{
			cout<<"input error"<<endl;
		}

		else

		{

			print.show(scan.ToStringQueue(input1));

			cout<<"="<<" "<<calcula.output(scan.ToStringQueue(input1));

		}

	}

	if(argc==4)
	{
		ifstream fin;        //创建输入文件流fin 
		fin.open(argv[2]);

		while(!fin.eof())
		{

			getline(fin,input2);


			if(input2=="") //跳过文件空行
			{
				continue;
			}


			if(scan.ToStringQueue(input2).empty())  // 报错
			{
				input="input error";
				print.result(num,argv[3],input);
				num=0;

			}


			else
			{
				num=calcula.output(scan.ToStringQueue(input2));

				print.result(num,argv[3],input);

			}

			input.clear();
			input2.clear();


		}

	}


	return 0; //函数返回值
}