//create a binary tree given two traversals
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class node
{
public:
	char data;
	node *left;
	node *right;
};

class newtree
{
	public:
		node *getnewnode(char data);
		node *createtree1(char in[],char pre[],int instart,int inend);
		node *createtree2(char in[],int instart,int inend,char post[],int poststart,int postend);
		int search(char in[],int instart,int inend,char searchelement);
		void inorder(node *root);
		void preorder(node *root);
		void postorder(node *root);
};

node *newtree :: getnewnode(char data)
{
	node *newnode=new node();
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

int newtree :: search(char in[],int instart,int inend,char searchelement)
{
	int i,pos;
	for(i=instart;i<inend;i++)
	{
		if(in[i]==searchelement)
		{
			pos=i;
			break;
		}
	}
	return pos;
}

node *newtree :: createtree1(char in[],char pre[],int instart,int inend)
{
	static int preindex=0;
	if(instart>inend)
		return 	NULL;
	node *treenode=getnewnode(pre[preindex]);
	preindex++;
	if(instart==inend)
		return treenode;
	int inindex=search(in,instart,inend,treenode->data);
	treenode->left=createtree1(in,pre,instart,inindex-1);
	treenode->right=createtree1(in,pre,inindex+1,inend);
	return treenode;
}

node *newtree :: createtree2(char in[],int instart,int inend,char post[],int poststart,int postend)
{
	if(instart>inend || poststart>postend)
	{
		return NULL;
	}
	char searchelement=post[postend];
	node *treenode=getnewnode(searchelement);
	if(instart==inend)
		return  treenode;
	int k=0;
	for(int i=0;i<inend;i++)
	{
		if(in[i]==searchelement)
		{
			k=i;
			break;
		}
	}
	treenode->left=createtree2(in,instart,k-1,post,poststart,poststart+k-(instart+1));
	treenode->right=createtree2(in,k+1,inend,post,poststart+k-instart,postend-1);
	return treenode;
}

void newtree :: preorder(node *root)
{
	if(root==NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void newtree :: inorder(node *root)
{
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void newtree :: postorder(node *root)
{
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	int i,choice,n,ch;
	newtree nt;
	char chh='y',chhh;
	char in[1000],pre[1000],post[1000];
	cout<<"enter which two order you have to create the tree?"<<endl;
	cout<<"1.inorder and preorder\n2.inorder and postorder"<<endl;
	cin>>choice;
	if(choice==1)
	{
		cout<<"enter the size of inorder or preorder array: "<<endl;
		cin>>n;
		cout<<"now enter the elements of inorder array: "<<endl;
		for(i=0;i<n;i++)
		{
			cin>>in[i];
		}
		cout<<"now enter the elements of preorder array: "<<endl;
		for(i=0;i<n;i++)
		{
			cin>>pre[i];
		}
		node *root=nt.createtree1(in,pre,0,n-1);
		cout<<"your tree is created now!"<<endl;
		cout<<"do you wish to display the formed tree?"<<endl;
		cout<<"enter 'y' to display, else enter 'n' to quit"<<endl;
		cin>>chhh;
			if(chhh=='y')
			{
				while(chh=='y')
				{
				cout<<"enter the order you want to display: "<<endl;
				cout<<"1.inorder\n2.preorder\n3.postorder"<<endl;
				cin>>ch;
					switch(ch)
					{
						case 1:
							nt.inorder(root);
							cout<<"\n";
							cout<<"do you want to display it in any other order?"<<endl;
							cout<<"enter 'y' to do this, else type 'n' to quit"<<endl;
							cin>>chh;
							break;
						case 2:
							nt.preorder(root);
							cout<<"\n";
							cout<<"do you want to display it in any other order?"<<endl;
							cout<<"enter 'y' to do this, else type 'n' to quit"<<endl;
							cin>>chh;
							break;
						case 3:
							nt.postorder(root);
							cout<<"\n";
							cout<<"do you want to display it in any other order?"<<endl;
							cout<<"enter 'y' to do this, else type 'n' to quit"<<endl;
							cin>>chh;
							break;
						default:
							cout<<"you entered the wrong choice"<<endl;
							cout<<"do you want to display it in any other order?"<<endl;
							cout<<"enter 'y' to do this, else type 'n' to quit"<<endl;
							cin>>chh;
					}
				}
			}
	}

	else if(choice==2)
	{
		cout<<"enter the size of inorder or postorder array: "<<endl;
		cin>>n;
		cout<<"now enter the elements of inorder array: "<<endl;
		for(i=0;i<n;i++)
		{
			cin>>in[i];
		}
		cout<<"now enter the elements of postorder array: "<<endl;
		for(i=0;i<n;i++)
		{
			cin>>post[i];
		}
		node *root=nt.createtree2(in,0,n-1,post,0,n-1);
		cout<<"your tree is created now!"<<endl;
				cout<<"do you wish to display the formed tree?"<<endl;
				cout<<"enter 'y' to display, else enter 'n' to quit"<<endl;
				cin>>chhh;
					if(chhh=='y')
					{
						while(chh=='y')
						{
						cout<<"enter the order you want to display: "<<endl;
						cout<<"1.inorder\n2.preorder\n3.postorder"<<endl;
						cin>>ch;
							switch(ch)
							{
								case 1:
									nt.inorder(root);
									cout<<"\n";
									cout<<"do you want to display it in any other order?"<<endl;
									cout<<"enter 'y' to do this, else type 'n' to quit"<<endl;
									cin>>chh;
									break;
								case 2:
									nt.preorder(root);
									cout<<"\n";
									cout<<"do you want to display it in any other order?"<<endl;
									cout<<"enter 'y' to do this, else type 'n' to quit"<<endl;
									cin>>chh;
									break;
								case 3:
									nt.postorder(root);
									cout<<"\n";
									cout<<"do you want to display it in any other order?"<<endl;
									cout<<"enter 'y' to do this, else type 'n' to quit"<<endl;
									cin>>chh;
									break;
								default:
									cout<<"you entered the wrong choice"<<endl;
									cout<<"do you want to display it in any other order?"<<endl;
									cout<<"enter 'y' to do this, else type 'n' to quit"<<endl;
									cin>>chh;
							}
						}
					}
	}

	else
	{
		cout<<"you had entered the wrong choice"<<endl;
	}

	return 0;
}


