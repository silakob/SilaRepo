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
void SameDistance(float f[10],float x[10],float delt[10][10],int n,float p,float h[10],float sumx)
{
	int i,j;
	float u,a[10][10];
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
}
void DiffDistance(float f[10],float x[10],float a[10][10],int n,float p,float sumx)
{
	int i,j;
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
	print(a,n,n);
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
}
int main()
{
	float f[10],x[10],a[10][10]={0.0},h[10]={0.0},p,sumx=0.0;
	int n;
	bool flag=true;
	int k=0;
	cout<<"Enter number of data : "; cin>>n;
	cout<<"X = "<<endl;	input(x,n);
	cout<<"f = "<<endl;	input(f,n);
	h[k]=x[k+1]-x[k];
	while(k<n-2)
	{
		k++;
		h[k]=x[k+1]-x[k];
		if(h[k]!=h[k-1])
			flag=false;
	}
	if(flag==true)
	{
		cout<<"Equipvalent Distance"<<endl;
		SameDistance(f,x,a,n,p,h,sumx); //Equipvalent all Distance
	}
	else
	{
		cout<<"Different Distance"<<endl;
		DiffDistance(f,x,a,n,p,sumx); // Not Equipvalent Distance
	}
	return 0;
}
