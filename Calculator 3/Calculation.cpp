
#include "Calculation.h"

using namespace std;

int Calculation::level(string c) //�ж�����������ȼ� 
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

bool Calculation::isOperator(string s) //�ж��Ƿ�������������� 
{
	if (s=="+" || s=="-" ||s== "*" ||s=="/")
		return true;
	else
		return false;
}



double Calculation::output(queue<string> strs)
{
	stack<string> ch;  // �Ŷ���strs������ʽ
	stack<string> s1; //�����ջ
	stack<string> s2; //�����м�Ԫ�ص�ջ
	stack<string> ch1;//��ǰ׺���ʽ����ʽ��
	stack<double> out; //����������ջ
	string temp;


	while(!strs.empty()) // ��scan�з��صĶ��а�����ķ�ʽѹ��ջch�� 
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


	while(!s1.empty()) //ջs1��Ϊ�����s1��ʣ�µ�����Ԫ��ѹ��ջs2�� 
	{
		s2.push(s1.top());
		s1.pop();
	}
	
	
    	// ��ʱ�ѵõ�ǰ׺���ʽ 

	while(!s2.empty()) //��ǰ׺���ʽ���������ѹ��ջch1�� 
	{
		ch1.push((s2.top())) ;
		s2.pop();
	}

      
 
	while(!ch1.empty()) //��ʼ����
	{
		double x,y,z;
		string symble; 
		stringstream stream; //����stringstream����  
		symble=ch1.top(); //��ջ��Ԫ�ظ����ַ���
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

		else // ���ַ����е�����ת��double�� 
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











