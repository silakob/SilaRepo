#include<iostream>
#include<cmath>
using namespace std;
void input(float x[10],int n)
{
	int i;
	cout<<"Input data = ";
	for(i=0;i<=n;i++)
		cin>>x[i];
}
void print(float x[10][10],int m,int n)
{
	int i,j;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
			cout<<x[i][j]<<" ";
		cout<<endl;
	}
}
void Findc(float A[10][10],float B[10],float C[10],int n)
{
	int i,j,k,l;
	float m,matrix[4][4]={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
/*	
//Check ML
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			cout<<A[i][j]<<"  ";
		}
		cout<<endl;
	}
*/	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			A[i][n+j+1]=matrix[i][j];
			//cout<<A[i][n+j+1];
		}
		//cout<<endl;
	}
	for(j=0;j<=n;j++)//0...2
	{
		for(l=(2*n)+1;l>=j;l--)//5...0//4...0
		{
			A[j][l]=A[j][l]/A[j][j];//a05=a05/a00 // a04=a04/a00 // a03=a03/a00 // ... // a0L=a0L/a00
		}
		for(i=j+1;i<=n;i++)//1...2//2...2
		{
			m=A[i][j];//a10//a20//a21
			for(k=j;k<=(2*n)+1;k++)//0...5
			{
				A[i][k]=A[i][k]-(m*A[j][k]);//a10=a10-(1)(a00) //a11=a11-(1)(a01) //a12=a12-(1)(a02) 
				cout<<"A["<<i<<"]["<<k<<"] = "<<A[i][k]<<" ";
			}
		}
	}
	// Jordan
	for(j=n;j>=1;j--)//2...1
	{
		for(i=j-1;i>=0;i--)//1...0//0...0
		{
			m=A[i][j];//10//20//21
			for(k=j;k<=(2*n)+1;k++)//2...5
			{
				A[i][k]=A[i][k]-(m*A[j][k]);//a12=a12-(1)(a22)
			}
		}
	}
	
/*	
//Check Inverse
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=(2*n)+1;j++)
		{
			cout<<A[i][j]<<"  ";
		}
		cout<<endl;
	}
	*/
	
	for(i=0;i<=n;i++)
	{
		for(j=n+1;j<=(2*n)+1;j++)
		{
			C[i]+=A[i][j]*B[i];
		}
		//cout<<C[i]<<"  ";
	}	
}

int main()
{
	float x[10],f[10],h[10],ml[10][10]={0},mr[10]={0},a[10]={0},b[10]={0},c[10]={0},d[10]={0},s;
	int n;
	cout<<"Enter number of data : "; cin>>n;
	n--;
	cout<<"X = "<<endl;	input(x,n);
	cout<<"f = "<<endl;	input(f,n);
	for(int i=0;i<=n;i++)
	{
		a[i]=f[i];
		//cout<<a[i]<<"::"<<f[i]<<"  i="<<i<<endl;
	}
	for(int inx=0;inx<=n-1;inx++)
		h[inx]=x[inx+1]-x[inx];
	ml[0][0]=ml[n][n]=1;
	for(int j=1;j<=n-1;j++)
	{
		ml[j][j-1]=h[j-1];
		ml[j][j]=2*(h[j-1]+h[j]);
		ml[j][j+1]=h[j];
		mr[j]=((3/h[j])*(a[j+1]-a[j]))-((3/h[j-1])*(a[j]-a[j-1]));
	}
	//print(ml,n,n);
	cout<<endl;
	for(int inx=0;inx<=n;inx++)
		cout<<mr[inx]<<"  ";
	
	cout<<endl<<endl<<endl;	
	Findc(ml,mr,c,n);

	for(int j=0;j<=n;j++)
		cout<<"c["<<j<<"] = "<<c[j]<<" ";
	cout<<endl;
		
	for(int inx=1;inx<=n-1;inx++)
	{
		d[inx]=((c[inx+1]-c[inx])/(3*h[inx]));
		//cout<<d[inx]<<"  inx="<<inx<<endl;
	}
	for(int inx=1;inx<=n-1;inx++)
	{
		b[inx]=((1/h[inx])*(a[inx+1]-a[inx]))-((h[inx]/3)*((2*c[inx])-c[inx+1]));
		//cout<<b[inx]<<"  inx="<<inx<<endl;
	}

	//part of equation has thrown

	float p;  // value to find interpolation
	int k=1;
	do
	{
		cout<<"Input a value to interpolation between "<<x[0]<<" and "<<x[n]<<" : ";
		cin>>p;
	}while(p<x[0]||p>x[n]);
	while(p>=x[k])
	{
		k++;
	}
	s=a[k-1]+(b[k-1]*pow((p-x[k-1]),1))+(c[k-1]*pow((p-x[k-1]),2))+(d[k-1]*pow((p-x[k-1]),3));
	cout<<"S["<<k-1<<"] = "<<s<<endl;
	
	return 0;
}
