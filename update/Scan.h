#ifndef SCAN_H
#define SCAN_H
#pragma once
#include <queue>
#include <string>
#include<ctype.h>
using namespace std;
class Scan
{
	private:

	public:
		Scan(void);
		~Scan(void);
		queue<string> ToStringQueue(string input);


};


#endif
