#include<iostream>
#include<math.h>
using namespace std;
void print(float x[10][10],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			cout<<x[i][j]<<" ";
		cout<<endl;
	}
}
void printarr(float x[10],int m)
{
	int i;
	for(i=0;i<m;i++)
	{
			cout<<x[i]<<" ";
		cout<<endl;
	}
}
int main()
{
	float f[10]={1.0,5.0,7.0,8.0},x[10]={0.0,3.0,7.0,9.0},a[10][10]={0.0},p,sumx=0.0;
	int i,j,n;
	n=4;
	for(i=0;i<n;i++)// a0=f0
	{
		a[i][0]=f[i];
		//cout<<a[i][0]<<"::"<<f[i]<<"  i="<<i<<endl;   // a = [22 24 37 95]
	}
	for(j=1;j<n;j++)
	{
		for(i=0;i<n-j;i++)
		{
			a[i][j]=(a[i+1][j-1]-a[i][j-1])/(x[i+j]-x[i]);
			//cout<<a[i][j]<<"::"<<"  row="<<i<<"::"<<"  col="<<j<<"     ";   // nd_rd...delivertive_of_a = []
		}
		cout<<endl;
	}
	//printarr(x,n);
	//print(a,n,n);
	cout<<"Input a value to intropolate(between "<<x[0]<<" and "<<x[n-1]<<" ) = "; cin>>p;
	for(j=0;j<n;j++)
	{
		int mul=1;
		for(i=0;i<j;i++)
		{
			mul=mul*(p-x[i]);
			//cout<<mul[i]<<"::"<<"  row="<<i;   // (x-x0)(x-x1)... = []
		}
		cout<<endl;
		sumx+=(a[0][j]*mul);
	}
	cout<<endl<<".............................................."<<endl;
	cout<<endl<<"sumx = "<<sumx;
	return 0;
}
