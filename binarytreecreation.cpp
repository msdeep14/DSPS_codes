//binary tree creation
//mandeep singh @msdeep14
#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
	public:
		int data;
		node *left;
		node *right;
};

class binarytreecreation
{
	public:
		void preorder(node *root);
		void inorder(node *root);
		void postorder(node *root);
		node *insert(node *root,int data);
};
void binarytreecreation :: preorder(node *root)
{
	if(root==NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void binarytreecreation :: inorder(node *root)
{
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void binarytreecreation :: postorder(node *root)
{
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

node *binarytreecreation:: insert(node *root,int data)
{
	char ch;
		if(root==NULL)
		{
			node*s=new node;
			s->data=data;
			s->left=NULL;
			s->right=NULL;
			root=s;
			return root;
		   }
		else
		    {
			cout<<"enter choice l or r of node  "<<root->data<<endl;
			cin>>ch;
			if(ch=='l')
			{
				root->left=insert(root->left,data);
			}
			else if(ch=='r')
			{
				root->right=insert(root->right,data);
			}
			else
			{
				cout<<"you had entered the wrong choice!"<<endl;
			}
			return root;
		}
}
int main()
{
	binarytreecreation btc;
	node *root=NULL;
	int val,ch;
	char ans,chh='y';
	char choice;
	cout<<"enter data for root of the tree:  "<<endl;
	cin>>val;
	node*p=new node();
	p->left=NULL;
	p->right=NULL;
	p->data=val;
	root=p;
	cout<<"do you wish to continue to create further nodes of tree?"<<endl;
	cout<<"enter 'y' to continue "<<endl;
	cin>>ans;

	while(ans=='y')
	{
		cout<<"enter data to be inserted into node: "<<endl;
		cin>>val;
		root=btc.insert(root,val);
		cout<<"if you wish to continue, enter 'y'"<<endl;
		cin>>ans;
	}
	cout<<"\n";
	cout<<"your tree is created now! do you want to display it now?"<<endl;
	cout<<"enter your choice, 'y' to continue and 'n' to exit"<<endl;
	cin>>choice;
	if(choice=='y')
	{
		while(chh=='y')
		{
		cout<<"enter the order you want to display: "<<endl;
		cout<<"1.inorder\n2.preorder\n3.postorder"<<endl;
		cin>>ch;
			switch(ch)
			{
				case 1:
					btc.inorder(root);
					cout<<"\n";
					cout<<"do you want to display it in any other order?"<<endl;
					cout<<"enter 'y' to do this, else type 'n' to quit"<<endl;
					cin>>chh;
					break;
				case 2:
					btc.preorder(root);
					cout<<"\n";
					cout<<"do you want to display it in any other order?"<<endl;
					cout<<"enter 'y' to do this, else type 'n' to quit"<<endl;
					cin>>chh;
					break;
				case 3:
					btc.postorder(root);
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
	return 0;
	}


