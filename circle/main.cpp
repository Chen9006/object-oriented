#include <iostream>
#include<cmath>
#include "output.h"

using namespace std;


int main(int argc, char* argv[])
{
	double rad;
	
	cin>>rad;
	
	output out;
	
	cout<<out.calculate(rad)<<endl;
	
	return 0;
}
