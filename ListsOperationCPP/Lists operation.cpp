// Linked list implementation
#include<iostream>
using namespace std;
struct node		//Defination
{
	int data;		//data
	node *link;		//pointer
};
void input(node*& first)
{
	int info;
	node *n;		//new node
	node *last;		//last node
	cout<<"Input data(digit) : ";	cin>>info;
	while(info!=-999)
	{
		n=new node;			//create node
		n->data=info;
		n->link=NULL;		// pointer->null
		if(first==NULL)		// NULL *** upper case only ***
			first=n;		//first node only
		else
		{
			last=first;		//  |first|->| 1 |->| 2 |->| 3 |->| 4 |->|last|
			while(last->link!=NULL)
				last=last->link;
			last->link=n;
		}
		cout<<"Input data(digit) : ";	cin>>info;	
	}
}
void search(node*& first)
{
	int item;
	node *loc,*ptr;
	cout<<"Put value to be search : "; cin>>item;
	ptr=first;
	loc=NULL;
	while(ptr!=NULL)
	{
		if(ptr->data==item)
		{
			loc=ptr;
			cout<<"Data is found : "<<loc->data<<endl;
			ptr=NULL;
		}
		else 
			ptr=ptr->link;
	}
	if(loc==NULL)
		cout<<"Data is not found"<<endl;
}
void insert(node*& first)
{
	int item;
	node *n,*ptr,*pre,*post;
	cout<<"Input data : "; cin>>item;
	n=new node;
	n->data=item;
	n->link=NULL;
	if(first==NULL) // Empty list
		first=n;
	if(n->data<first->data) //list have 1 data only
	{
		n->link=first;
		first=n;
	}
	else
	{
		pre=first;
		ptr=first->link;
		post=ptr;
		while(ptr!=NULL)
		{
			if(n->data<ptr->data)
			{
				pre->link=n;
				n->link=post;
				ptr=NULL;
			}
			else
			{
				pre=pre->link;
				post=post->link;
				ptr=ptr->link;
			}
		}
	}
}
void del(node*& first)
{
	int item,z=0;
	bool flag=false;
	node *ptr,*pre,*post;
	cout<<endl<<"Input data to delete : "; cin>>item;
	if(first==NULL) // Empty list
	{
		cout<<"List empty"<<endl;
		cout<<"Can not delete data"<<endl;
	}
	else	
	{	
		if(first->data==item) //list have 1 data only
		{
			flag=true;
			first=first->link;
			cout<<"success"<<endl;
		}
		if(first!=NULL && first->link!=NULL)
		{	
			pre=first;
			ptr=first->link;
			post=ptr->link;
			while(ptr->link!=NULL)
			{
				if(ptr->data==item)
				{
					pre->link=post;
					flag=true;
					ptr->link=NULL;
					cout<<"success"<<endl;
				}
				else
				{
					pre=pre->link;
					post=post->link;
					ptr=ptr->link;
				}
			}
		}
	}
	if(flag==false)
	{
		cout<<"Data is not found"<<endl;			
		cout<<"Unsuccess"<<endl;
	}
}
void print(node*& first)
{
	node *ptr;
	ptr=first;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" -> ";
		ptr=ptr->link;
	}
}
int main()
{
	node *first;
	first=NULL;
	input(first);
	/*search(first);
	print(first);
	cout<<"....................."<<endl;
	insert(first);
	print(first);
	cout<<"....................."<<endl;
	*/del(first);
	print(first);
	return 0;
}
