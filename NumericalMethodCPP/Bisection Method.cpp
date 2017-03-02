// Bisection Method to find the root
#include<iostream>
#include<cmath>
#include<cfloat>
using namespace std;
inline long double f(long double x)
{
	long double k;
	k=(pow(x,3)+(3*pow(x,2))-(5*x)+6);
	return k;
}
int main()
{
	bool flag=true;
	long double a=-5.0,b=10.0,c,acc=0.000001;
	int n=0;
	if(f(a)*f(b)<0.0)//5*-4
	{
		//cout<<f(a)<<"  "<<f(b);
		while(flag)
		{
			c=(a+b)/2.0;
			n++;
			//cout<<"f(c) = "<<f(c)<<" "<<f(a)<<" "<<f(b)<<" c = "<<c<<" n = "<<n<<endl;
			if(f(c)==0.0||(b-a)/2<acc)
			{
				flag=false;
				cout<<"f(c) = "<<f(c)<<" c = "<<c<<" n = "<<n<<endl;
			}
			else  if(f(a)*f(c)>0.0)
						a=c;
				  else
				  		b=c;
		}
	}
	else
		cout<<"Root are detect"<<endl;
	return 0;
}
	/*
f = inline('(x^3)-(10*x^(2))+5','x');
a = 0.0; b = 1.0;
dx = 0.1;
x1 = a; 
x2 = a + dx; 
n = 0;
while f(x1)*f(x2) > 0.0
if x1 >= b
   x1 = NaN; 
   x2 = NaN; 
   return;
else
   x1 = x2; 
   x2 = x1 + dx; 
end
end
p = (x1+x2)/2;
[x1 x2 f(x1) f(x2)]
[p f(p)]
*/
