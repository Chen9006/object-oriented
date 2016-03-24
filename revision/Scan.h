#ifndef SCAN_H
#define SCAN_H
#pragma once
#include <queue>
#include <string>
#include <set>
using namespace std;
class Scan
{
	private:
		set<char> charset;  //定义一个set容器// 
	public:
		Scan(void);
		~Scan(void);
		queue<string> ToStringQueue(string input);
};


#endif
