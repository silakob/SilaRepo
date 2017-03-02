#include<iostream>
#include<math.h>
using namespace std;
void input(float x[10],int n)
{
	int i;
	cout<<"Input data = ";
	for(i=0;i<n;i++)
		cin>>x[i];
}
int factorial(int i)
{
	int f;
	if(i==0)        
		return 1;
	else
	    f=i*factorial(i-1);
	return f;
}
int uterm(float& u,int& j)
{
	float ans;
	ans=1;
	for(int i=1;i<=j;i++)
	{
		ans=ans*(u-(i-1));
		//cout<<"ans = "<<ans<<endl;
	}
	return ans;
}
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
int main()
{
	float x[10],f[10],delt[10][10]={0},u,h[10]={0.0},p,sumx;  //delt = dy/dx
	float a[1][10]={0};										// x   = [5 10 15 20]
	int n,i,j;											// f(x)= [22 24 37 95]
	cout<<"Enter number of data : "; cin>>n;
	cout<<"X = "<<endl;	input(x,n);
	cout<<"f = "<<endl;	input(f,n);
	for(i=0;i<n;i++)
	{
		delt[i][0]=f[i];
		//cout<<delt[i][0]<<"::"<<f[i]<<"  i="<<i<<endl;   // st_delt = [22 24 37 95]
	}
	for(j=1;j<n;j++)
	{
		for(i=0;i<n-j;i++)
		{
			delt[i][j]=delt[i+1][j-1]-delt[i][j-1];
			//cout<<delt[i][j]<<"::"<<"  row="<<i<<"::"<<"  col="<<j<<"     ";   // nd_rd..._delt = [22 24 37 95]
		}
		cout<<endl;
	}
	h[0]=x[1]-x[0];
	cout<<"Input a value to intropolate(between "<<x[0]<<" and "<<x[n-1]<<" ) = "; cin>>p;
	u=(p-x[0])/h[0];
	//cout<<u<<":"<<h[0];
	for(j=0;j<n;j++)
	{
		a[0][j]=delt[0][j]/(factorial(j));		// a=delt/factorial
		//cout<<"a[0]["<<j<<"]="<<a[0][j]<<endl;
	}
	sumx=0;
	for(j=0;j<n;j++)
	{
		sumx=sumx+(a[0][j]*uterm(u,j));
		//cout<<"j= "<<j<<"  sumx= "<<sumx<<endl;
	}
	cout<<endl<<".............................................."<<endl;
	cout<<"delt = "<<endl;
	print(delt,n,n);
	cout<<endl<<".............................................."<<endl;
	cout<<endl<<"sumx = "<<sumx;
	return 0;
}
