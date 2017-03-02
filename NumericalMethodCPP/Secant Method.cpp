// Secant to find the root
#include<iostream>
#include<cmath>
using namespace std;
inline long double f(long double x)
{
	return (pow(x,2)-(4*pow(x,1))+4);
}
inline long double g(long double x)
{
	return (2*(pow(x,1))-(4*(pow(x,0))));
}
int main()
{
	bool flag=true;
	int n=0;
	long double p0,p1,p2,acc=0.000000001;
	cout<<"Enter p0 = "; cin>>p0;
	cout<<"Enter p1 = "; cin>>p1;
	while(flag)
		{
			p2=p1-((f(p1)*(p1-p0))/(f(p1)-f(p0)));
			n++;
			if(f(p2)==0.0000000000||abs(f(p2))<acc)
			{
				flag=false;
				cout<<"f(p2) = "<<f(p2)<<" p2 = "<<p2<<" n = "<<n<<endl;
			}
			else  p0=p1;
				  p1=p2;
		}
	return 0;
}
