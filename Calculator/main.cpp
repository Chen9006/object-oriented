#include<iostream>
#include <string>
#include "Scan.h"
#include "Print.h"
using namespace std;

int main() 
{
	string input;
	cin>>input;
	Scan scan;
	Print print;
	print.show(scan.ToStringQueue(input));

	cin.get();
	cin.get();
	return 0;
}


