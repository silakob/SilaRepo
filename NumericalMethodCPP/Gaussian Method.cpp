#include<iostream>
using namespace std;
void input(float x[10][10],int& n)
{
	int size,i,j,pa;
	cout<<"Input size of Matrix = "; cin>>size;
	cout<<"InPut data "<<endl;
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size+1;j++)
			cin>>x[i][j];
	}
	n=size;
}
void gaussian(float A[10][10],float B[1][10],int& n,float& m)
{
	int i,j,k,l;
	for(j=1;j<=n;j++)//1...2
	{
		for(l=n+1;l>=j;l--)//1...4//2...4
		{
			A[j][l]=A[j][l]/A[j][j];//a11=a11/a11 // a12=a12/a11 // a13=a13/a11 // ... // a1n=a1n/a11
		}
		for(i=j+1;i<=n;i++)//2...3//3...3
		{
			m=A[i][j];//a21//a31//a32
			for(k=j;k<=n+1;k++)//1...4
			{
				A[i][k]=A[i][k]-(m*A[j][k]);//a21=a21-(1)(a11) //a22=a22-(1)(a12) //a23=a23-(1)(a13) 
			}
		}
		B[1][j]=A[j][4]; // Already get the result b11=a14
	}
}
void menu(int& select)
{
	cout<<"  Menu  "<<endl;
	cout<<"1 Backward Method"<<endl;
	cout<<"2 Jordan Method"<<endl;
	cout<<"3 Find Determinent"<<endl;
	cout<<"4 End"<<endl;
	cout<<"Select 1/2/3 : ";	cin>>select;
}
void backward(float A[10][10],float B[1][10],float ans[10],int& n,float sum)
{
	int i,k;
	cout<<" Backward Method "<<endl;
	for(i=n;i>=1;i--)
	{
		sum=0;
		for(k=i+1;k<=n;k++)
			sum=sum+(A[i][k]*ans[k]);
		ans[i]=(B[1][i]-sum)/A[i][i];
	}
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";	
}
void jordan(float A[10][10],float ans[10],int& n,float& m)
{
	int i,j,k,l;
	cout<<endl<<".........................."<<endl<<endl;
	cout<<" Jordan Method "<<endl;	
	for(j=n;j>=2;j--)//1...2
	{
		for(l=n+1;l>=j;l--)//1...4//2...4
		{
			A[j][l]=A[j][l]/A[j][j];//a11=a11/a11
		}
		for(i=j-1;i>=1;i--)//2...3//3...3
		{
			m=A[i][j];//21//31//32
			for(k=j;k<=n+1;k++)//1...4
			{
				A[i][k]=A[i][k]-(m*A[j][k]);//a21=a21-(1)(a11)
			}
		}
	}
}
void det(float A[10][10],int& n)
{
	float det=1.0;
	cout<<endl<<".........................."<<endl;
	cout<<"det = ";
	for(int x=1;x<=n;x++)
		det=det*A[x][n+1];
	cout<<det;
}
void print(float x[10][10],int n)
{
	int i,j;
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n;j++)
			cout<<x[i][j]<<"  ";
		cout<<endl;
	}
}
int main()
{
	float A[10][10],B[1][10],ans[10],sum;
	int n,i,j,pa,select;
	char con;
	float m;
	input(A,n);
	cout<<endl<<".........................."<<endl<<endl;
	do
	{
		gaussian(A,B,n,m);
		cout<<" Gaussian Method "<<endl;
		print(A,n+1);
		cout<<endl<<".........................."<<endl<<endl;
		menu(select);
		switch(select)
		{
			case 1:	backward(A,B,ans,n,sum);
				break;
			case 2:	jordan(A,ans,n,m);
					print(A,n+1);
				break;
			case 3:	det(A,n);
				break;
		}
		cout<<endl<<"Run again Y/N : "; cin>>con;
	}while(con=='Y'|| con=='y');
	return 0;
}
