#include<stdio.h>
int main()
{
   int a,b,i=1,j,d,n;

   int c[10000];

   scanf("%d %d",&a,&b);

   d=a+b;
   j=d;
   
if(j>=0)
{ 
	for(i=1,n=1;i<=100000;i++)
 {
 
   c[i]=d%10;
	   d=d/10;
	   if(d==0) break;
	   n++;
	}
}

if(j<0)
{
	
for(i=1,n=1;i<=100000;i++)
	{
       c[i]=d%10;
	       d=d/10;
		  c[i]=-c[i];

	  if(d==0) break;
	    n++;
	}

c[n]=-c[n];	
}


 
 for(i=1;i<=n;i++)
   { 
	     if(n>3)
		 { printf("%d",c[n-i+1]);

	          if((n-i)%3==0 && i!=n)
		      printf(",");}
     else
		 printf("%d",c[n-i+1]);

 }
 
	
	
   return 0;
}