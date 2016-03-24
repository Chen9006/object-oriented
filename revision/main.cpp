/********************************
Author:chenjiaquan     Date:2016/02/23
********************************/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <iostream>
#include <string>
#include "Scan.h"
#include "Print.h"
using namespace std;

int main()
{
	string input; //定义字符串 
	cin>>input; //输入字符串 
	Scan scan;
	Print print;
	print.show(scan.ToStringQueue(input));

	cin.get();
	cin.get();
	return 0; //函数返回值
}
