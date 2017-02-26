// Program to presentation of strings and arrays operations
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
void head(int& choice)
{
	cout<<"Menu"<<endl;
	cout<<"1 Strings"<<endl;
	cout<<"2 Arrays"<<endl;
	cout<<"3 End Program"<<endl;
	cout<<"Select 1/2/3 : "; cin>>choice;
}
void show1(int& select1)//show menu
{
	cout<<endl<<endl<<"Menu Strings"<<endl;
	cout<<"1 Substring"<<endl;
	cout<<"2 Indexing"<<endl;
	cout<<"3 Concatenation"<<endl;
	cout<<"4 Length"<<endl;
	cout<<"5 Insertion"<<endl;
	cout<<"6 Deletion"<<endl;
	cout<<"7 Replacement"<<endl;
	cout<<"8 <<Back"<<endl;
	cout<<"Select 1/2/3/4/5/6/7/8 : "; cin>>select1;
	cout<<".............................................................."<<endl;
}
void show2(int& select2)//show menu
{
	cout<<endl<<endl<<"Menu Arrays"<<endl;
	cout<<"1 Traversal Array"<<endl;
	cout<<"2 Search Array"<<endl;
	cout<<"3 Insertion Array"<<endl;
	cout<<"4 Deletion Array"<<endl;
	cout<<"5 Sorting Array"<<endl;
	cout<<"6 <<Back"<<endl;
	cout<<"Select 1/2/3/4/5/6 : "; cin>>select2;
	cout<<".............................................................."<<endl;
}
//
void input1(string& st1,string& st2)
{
	cout<<"Put string 1 : "; cin>>st1;
	cout<<"Put string 2 : "; cin>>st2;
}
void input2(int arr[10],int& n)
{
	int i;
	i=1;
	cout<<"Put data in array : ";
	cin>>arr[i];
	while(arr[i]!=-999)
	{
		i++;
		n++;
		cin>>arr[i];
	}
	cout<<endl;
}
//
void print(string& st1,string& st2)
{
	cout<<st1<<endl;
	cout<<st2<<endl;
	cout<<"............................................................."<<endl;
}
void substring(string& st1,string& st2)
{
	int pos,num;
	print(st1,st2);
	cout<<"Input position of strings : "; cin>>pos;
	cout<<"Input number of strings : "; cin>>num;
	cout<<"Substring 1 :"<<st1.substr(pos,num)<<endl;
}
void index(string& st1,string& st2)
{
	string pattern;
	int pos;
	print(st1,st2);
	cout<<"Index : "<<st1.find(st2)<<endl;

}
void concat(string& st1,string& st2)
{
	print(st1,st2);
	cout<<st1+st2<<endl;
}
void length(string& st1,string& st2)
{
	print(st1,st2);
	cout<<"Length string 1 :"<<st1.length()<<endl;
	cout<<"Length string 2 :"<<st2.length()<<endl;
}
void insert(string& st1,string& st2)
{
	int pos;
	string text;
	print(st1,st2);
	cout<<"position = "; cin>>pos;
	cout<<"Input the text to insert = "; cin>>text;
	cout<<st1.insert(pos,text);
}
void delet(string& st1,string& st2)
{

	int pos,num;
	print(st1,st2);
	cout<<"Input position of strings 1 : "; cin>>pos;
	cout<<"Input how many number of strings to delete in string 1 : "; cin>>num;
	cout<<endl<<st1.erase(pos,num)<<endl;
}
void replace(string& st1,string& st2)
{
	int pos,num;
	print(st1,st2);
	cout<<"Input position of strings 1 : "; cin>>pos;
	cout<<"Input how many number of strings to replace in string 1 : "; cin>>num;
	cout<<endl<<st1.replace(pos,num,st2)<<endl;
}
void arr1(int arr[10],int& n)
{
	cout<<"Output Array"<<endl;
	for(int i=1;i<=n;i++)
		cout<<arr[i]<<" ";
}
void arr2(int arr[10],int& n)
{
	int loc,item;
	bool flag;
	cout<<"Input data to be search : "; cin>>item;
	for(int i=1;i<=n;i++)
	{
		if(arr[i]==item)
		{
			loc=i;
			i=n+1;
			flag=true;
		}
		else
			flag=false;
	}
	if(flag==true)
	{
		cout<<"Data is found"<<endl;
		cout<<arr[loc]<<endl;
	}
	else
		cout<<"!!! Data is not found  !!!"<<endl;
}
void arr3(int arr[10],int& n)
{
	int item,j,k;
	cout<<"Put data to insert : "; cin>>item;
	cout<<"Put position : "; cin>>k;
	j=n;
	while(j>=k)
	{
		arr[j+1]=arr[j];
		j--;
	}
	arr[k]=item;
	n++;
	arr1(arr,n);
}
void arr4(int arr[10],int& n)
{
	int j,k;
	cout<<"Put position : "; cin>>k;
	for(j=k;j<=n-1;j++)
		arr[j]=arr[j+1];
	n--;
	arr1(arr,n);
}
void arr5(int arr[10],int& n)
{
	int temp,ptr,k;
	for(k=1;k<=n-1;k++)
	{
		ptr=1;
		while(ptr<=n-k)
		{
			if(arr[ptr]>arr[ptr+1])
			{
				temp=arr[ptr];
				arr[ptr]=arr[ptr+1];
				arr[ptr+1]=temp;
			}
			ptr++;
		}
	}
	arr1(arr,n);
}
int main()
{
	int select1,select2,choice;
	int arr[10],n=0;
	string st1,st2;
	//
	do
	{
	
		head(choice);
		system("cls");
		switch(choice)
		{
			case 1: input1(st1,st2);
				do
				{
					show1(select1);
					system("cls");
					switch(select1)
					{
						case 1: substring(st1,st2);
								break;
						case 2: index(st1,st2);
							break;
						case 3: concat(st1,st2);
								break;
						case 4: length(st1,st2);
							break;
						case 5: insert(st1,st2);
							break;
						case 6: delet(st1,st2);
							break;
						case 7: replace(st1,st2);
							break;
					}
				}while(select1!=8);
				break;
			case 2: input2(arr,n);
				do
				{
					show2(select2);
					system("cls");
					switch(select2)
					{
						case 1: arr1(arr,n);
							break;
						case 2: arr2(arr,n);
							break;
						case 3: arr3(arr,n);
							break;
						case 4: arr4(arr,n);
							break;
						case 5: arr5(arr,n);
							break;
					}
				}while(select2!=6);
				break;
		}
	}while(choice!=3);
	return 0;
}
