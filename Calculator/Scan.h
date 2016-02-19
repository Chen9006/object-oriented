#pragma once
#include <queue>
#include <string>
#include <set>
using namespace std;
class Scan
{
private:
	set<char> charset;
public:
	Scan(void);
	~Scan(void);
	queue<string> ToStringQueue(string input);
};
