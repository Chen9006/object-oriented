#include "output.h"

using namespace std;

double output::calculate(double ch)
{
	double pi,result;
	
	pi=acos(-1);
	
	result=pi*ch*ch;
	
	return result;	
}
