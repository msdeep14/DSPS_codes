//vegetable fruit mall;
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class mall1
{
	public:
		int qty;
		char name[20];
		mall1 *next1;
		mall1 *prev1;
}*first1=NULL, *last1=NULL, *node1=NULL;

class mall2
{
	public:
		int qty;
		char name[20];
		mall2 *next2;
		mall2 *prev2;
}*first2=NULL, *last2=NULL, *node2=NULL;

class purchase
{
	public:
		void vmenu(int vnum);
		void fmenu(int fnum);
		void vpurchase(int vnum);
		void fpurchase(int fnum);
		void vsorting();
		void fsorting();
		void vdisplay();
		void fdisplay();
};

void purchase :: vmenu(int vnum)
{
	int k;
	cout<<"enter the names of vegetables."<<endl;
	for(k=1;k<=vnum;k++)
	{
		mall1 *vnode=new mall1();
		cout<<k<<".";
		cin>>vnode->name;
		if(first1==NULL)
		{
			vnode->prev1=NULL;
			vnode->next1=NULL;
			first1=vnode;
			last1=vnode;
		}
		else
		{
			vnode->next1=NULL;
			last1->next1=vnode;
			vnode->prev1=last1;
			last1=vnode;
		}
	}
}

void purchase :: fmenu(int fnum)
{
	int k;
	cout<<"enter the names of fruits?"<<endl;
	for(k=1;k<=fnum;k++)
	{
		mall2 *fnode=new mall2();
		cout<<k<<".";
		cin>>fnode->name;
		if(first2==NULL)
		{
			fnode->prev2=NULL;
			fnode->next2=NULL;
			first2=fnode;
			last2=fnode;
		}
		else
		{
			fnode->next2=NULL;
			last2->next2=fnode;
			fnode->prev2=last2;
			last2=fnode;
		}
	}
}

void purchase :: vpurchase(int vnum)
{
	node1=first1;
	int k=1,vqty,flag=0;
	char vname[20],ans='y';
	while(node1!=NULL)
	{
		cout<<k<<"."<<node1->name<<endl;
		k++;
		node1=node1->next1;
	}
	cout<<"do you wish to buy any vegetables?"<<endl;
	cout<<"enter 'y' if wish to do so!"<<endl;
	cin>>ans;
	while(ans=='y')
	{
		cout<<"enter the name of veg you want to buy?"<<endl;
		cin>>vname;
		node1=first1;
		while(node1!=NULL)
		{
			if(strcmp(vname,node1->name)==0)
			{
				cout<<"enter the quantity in kg you want to buy?"<<endl;
				cin>>vqty;
				node1->qty=node1->qty + vqty;
				flag=1;
			}
			node1=node1->next1;
		}
		if(flag==0)
		{
			cout<<"you have entered the wrong choice!"<<endl;
		}
		cout<<"enter 'y' if you wish to continue!"<<endl;
		cin>>ans;
		if(ans=='y')
			continue;
	}
}

void purchase :: fpurchase(int fnum)
{
	char fname[20] ,ans='y';
	node2=first2;
	int k=1,fqty,flag=0;
	while(node2!=NULL)
	{
		cout<<k<<"."<<node2->name<<endl;
		k++;
		node2=node2->next2;
	}
	cout<<"do you wish to buy any fruits?"<<endl;
	cout<<"enter 'y' if wish to do so!"<<endl;
	cin>>ans;
	while(ans=='y')
	{
		cout<<"enter the name of fruit you want to buy?"<<endl;
		cin>>fname;
		node2=first2;
		while(node2!=NULL)
		{
			if(strcmp(fname,node2->name)==0)
			{
				cout<<"enter the quantity in kg you want to buy?"<<endl;
				cin>>fqty;
				node2->qty=node2->qty + fqty;
				flag=1;
			}
			node2=node2->next2;
		}
		if(flag==0)
		{
			cout<<"you have entered the wrong choice!"<<endl;
		}
		cout<<"enter 'y' if you wish to continue!"<<endl;
		cin>>ans;
		if(ans=='y')
			continue;
	}
}

void purchase :: vsorting()
{
	char tempstr[20];
	for(mall1 *i=last1;i!=first1;i=i->prev1)
	{
		for(mall1 *j=first1;j!=i;j=j->next1)
		{
			if(j->qty<j->next1->qty)
			{
				int temp=j->qty;
				strcpy(tempstr,j->name);
				j->qty=j->next1->qty;
				strcpy(j->name,j->next1->name);
				j->next1->qty=temp;
				strcpy(j->next1->name,tempstr);
			}
		}
	}
}

void purchase :: fsorting()
{
	char tempstr[20];
	for(mall2 *i=last2;i!=first2;i=i->prev2)
	{
		for(mall2 *j=first2;j!=i;j=j->next2)
		{
			if(j->qty<j->next2->qty)
			{
				int temp=j->qty;
				strcpy(tempstr,j->name);
				j->qty=j->next2->qty;
				strcpy(j->name,j->next2->name);
				j->next2->qty=temp;
				strcpy(j->next2->name,tempstr);
			}
		}
	}
}

void purchase :: vdisplay()
{
	node1=first1;
	while(node1!=NULL)
	{
		cout<<node1->name<<"\t"<<node1->qty<<"kg"<<endl;
		node1=node1->next1;
	}
}

void purchase :: fdisplay()
{
	node2=first2;
	while(node2!=NULL)
	{
		cout<<node2->name<<"\t"<<node2->qty<<"kg"<<endl;
		node2=node2->next2;
	}
}



int main()
{
	int choice=0;
	purchase prc;
	cout<<"\n";
	cout<<"Welcome to vfmall!"<<endl;
	int cus,k,fnum,vnum;
	cout<<"enter no. of vegetables present in stock?"<<endl;
	cin>>vnum;
	prc.vmenu(vnum);

	cout<<"enter no. of fruits present in stock?"<<endl;
	cin>>fnum;
	prc.fmenu(fnum);

	cout<<"enter no. of customers?"<<endl;
	cin>>cus;
	for(k=1;k<=cus;k++)
	{
		cout<<"for customer "<<k<<endl;
		prc.vpurchase(vnum);
		prc.fpurchase(fnum);
	}
	prc.vsorting();
	cout<<"total vegetables purchased are:"<<endl;
	prc.vdisplay();
	cout<<"\n";
	prc.fsorting();
	cout<<"total fruits purchased are: "<<endl;
	prc.fdisplay();
	cout<<"\n";
	cout<<"Thanks for visiting vfmall!"<<endl;
	cout<<"\n";
	return 0;
}

