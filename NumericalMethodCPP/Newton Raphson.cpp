// Newton Raphson to find the root
#include<iostream>
#include<iomanip> // setprecision
#include<cmath>
using namespace std;
inline long double f(long double x)
{
	return (pow(x,2)-(4*x)+4);
}
inline long double g(long double x)
{
	return (2*(pow(x,1))-(4));
}
int main()
{
	bool flag=true;
	int n=0;
	long double p0,p1,acc=0.00000000000001;
	cout<<"Enter p0 = "; cin>>p0;
	while(flag)
		{
			p1=p0-(f(p0)/g(p0));
			n++;
			cout<<"f(p"<<n<<") = "<<setprecision(20)<<f(p1)<<" p"<<n<<" = "<<p1<<" n = "<<n<<endl;
			if(f(p1)==0.00000000000001||abs(f(p1))<acc)
			{
				flag=false;
				//cout<<"f(p1) = "<<setprecision(20)<<f(p1)<<" p"<<n<<" = "<<p1<<" n = "<<n<<endl;
			}
			else  p0=p1;
		}
	return 0;
}

/*
inline long double f(long double x)
{
	long double  k;
	k=(pow(x,3)-(10*pow(x,2))+5);
	return k;
}
inline long double g(long double x)
{
	long double  k;
	dk=(3*(pow(x,2))-(20*(pow(x,1))));
	return 0;
}
*/
