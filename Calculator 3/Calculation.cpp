
#include "Calculation.h"

using namespace std;

int Calculation::level(string c) //判断运算符号优先级 
{
	int q;
	if(c=="+" || c=="-")
	{
		q=1;
	}
	if(c=="*" || c=="/")
	{
		q=2;
	}

	return (q);
}

bool Calculation::isOperator(string s) //判断是否是四则运算符号 
{
	if (s=="+" || s=="-" ||s== "*" ||s=="/")
		return true;
	else
		return false;
}



double Calculation::output(queue<string> strs)
{
	stack<string> ch;  // 放队列strs的逆表达式
	stack<string> s1; //运算符栈
	stack<string> s2; //储存中间元素的栈
	stack<string> ch1;//放前缀表达式的逆式子
	stack<double> out; //放运算结果的栈
	string temp;


	while(!strs.empty()) // 将scan中返回的队列按逆序的方式压入栈ch中 
	{
		ch.push(strs.front()) ;
		strs.pop();

	}

	while(!ch.empty())
	{
		temp=ch.top();

		ch.pop();

		if(isOperator(temp))
		{

			ex:;

			if(s1.empty())
			{
				s1.push(temp);
			}
            else if (s1.top() == ")")
            {
                s1.push(temp);
			}   


			else if(level(temp)>=level(s1.top()))
			{

				s1.push(temp);

			}

			else
			{
				s2.push(s1.top());
				s1.pop();
   
				goto ex;
			}
		}

		else if(temp=="(")
		{
			while(s1.top()!=")")
			{
				s2.push(s1.top());
				s1.pop();
			}

            s1.pop();
		}

		else if(temp==")")
		{
			s1.push(temp);
		}

		else
		{
			s2.push(temp) ;
		}


	}


	while(!s1.empty()) //栈s1不为空则把s1中剩下的所有元素压入栈s2中 
	{
		s2.push(s1.top());
		s1.pop();
	}
	
	
    	// 此时已得到前缀表达式 

	while(!s2.empty()) //将前缀表达式的逆序逐个压入栈ch1中 
	{
		ch1.push((s2.top())) ;
		s2.pop();
	}

      
 
	while(!ch1.empty()) //开始计算
	{
		double x,y,z;
		string symble; 
		stringstream stream; //创建stringstream对象  
		symble=ch1.top(); //将栈顶元素赋给字符串
		ch1.pop();
	


     	if(symble =="+")
		{
			x=out.top();
			out.pop();
			y=out.top();
			out.pop();
			z=x+y;
			out.push(z);
		}
		else if(symble == "-")
		{
			x=out.top();
			out.pop();
			y=out.top();
			out.pop();
			z=x-y;
			out.push(z);

		}
		else if(symble == "*")
		{
			x=out.top();
			out.pop();
			y=out.top();
			out.pop();
			z=x*y;
			out.push(z);
		}
		else if(symble == "/")
		{
			x=out.top();
			out.pop();
			y=out.top();
			out.pop();
			z=x/y;
			out.push(z);
		}

		else // 将字符串中的数字转成double型 
		{
			double number;
			stream<<symble;
			stream>>number;
			out.push(number);
			stream.clear();
		}
	}

	double num=0;
	num=out.top();
	out.pop();
	return num;

}











