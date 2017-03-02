#include<iostream>
using namespace std;
float L(int i,float p,float x[3])
{
	int n=3;
	float mult=1.0;
	for(int j=0;j<=n-1;j++)
	{
		if(i!=j)
			mult=mult*((p-x[j])/(x[i]-x[j]));
	}
	return mult;
}
void input(float x[10],int n)
{
	int i;
	cout<<"Input data = ";
	for(i=0;i<n;i++)
		cin>>x[i];
}
int main()
{
	int i,j,n;
	float sumx=0.0,p,f[10],x[10];
	cout<<"Enter number of data : "; cin>>n;
	cout<<"X = "<<endl;	input(x,n);
	cout<<"f = "<<endl;	input(f,n);
	for(i=0;i<n;i++)
	{
		cout<<"  "<<x[i]<<"      "<<f[i]<<endl;
		cout<<"...................................."<<endl;
	}
	cout<<"Enter p = "; cin>>p;
	for(i=0;i<=n-1;i++)
		sumx=sumx+(f[i]*L(i,p,x));
	cout<<"  x"<<"	  f"<<endl;
	for(i=0;i<n;i++)
		cout<<"  "<<x[i]<<"      "<<f[i]<<endl;
		cout<<"...................................."<<endl;
	cout<<"Mult = "<<L(i,p,x)<<endl;
	cout<<"p = "<<p<<" : f("<<p<<") = "<<sumx<<endl;
	return 0;
}
