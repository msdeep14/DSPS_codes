//dictionary
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<cstring>
using namespace std;

class node
{
public:
	string word;
	string meaning;
	node *left;
	node *right;
};

class dictionary
{
public:
	node* create(node *root,char data[],char datameaning[]);
	void display(node *root);
	void updatemeaning(node *root);
	node * deletekeyword(node *root, char word[]);
	void searchkeyword(node *root,char word[],int comp);
};

node* dictionary :: create(node *root, char data[],char datameaning[] )
{
	if(root==NULL)
	{
		root=new node();
		root->word=data;
		root->meaning=datameaning;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	if(data<(root->word))
	{
		root->left=create(root->left,data,datameaning);
	}
	else
	{
		root->right=create(root->right,data,datameaning);
	}
	return root;
}

void dictionary :: display(node *root)
{
	if(root==NULL) return;
	display(root->left);
	cout<<root->word<<"\nmeaning:"<<root->meaning<<endl;
	display(root->right);
}

node *search(node *root,char searchword[],char updateword[])
{
	if(root->word==searchword)
	{
		root->meaning=updateword;
	}
	else if(searchword<(root->word))
	{
		root->left=search(root->left,searchword,updateword);
	}
	else
	{
		root->right=search(root->right,searchword,updateword);
	}
	return root;
}

void dictionary :: searchkeyword(node *root,char word[],int comp)
{
	if(root==NULL)
	{
		cout<<"word not found!"<<endl;
	}
	else if((root->word)==word)
	{
		cout<<"word found!, the meaning is: "<<root->meaning<<endl;
		cout<<"no. of comparisons for this search are: "<<comp<<endl;
	}
	else if(word<=(root->word))
	{
		comp++;
		return searchkeyword(root->left,word,comp);
	}
	else
	{
		comp++;
		return searchkeyword(root->right,word,comp);
	}

}

void dictionary :: updatemeaning(node *root)
{
	char updateword[20],searchword[20];
	cout<<"enter the keyword you want to update the meaning of?"<<endl;
	cin>>searchword;
	cout<<"enter the new meaning of this word: "<<endl;
	cin>>updateword;
	search(root,searchword,updateword);
}

node *findmin(node *min)
{
	if(min==NULL)
		return NULL;
	while(min->left!=NULL)
	{
		min=min->left;
	}
	return min;
}

node * dictionary :: deletekeyword(node *root,char word[])
{
	if(root==NULL) return root;
	else if(word<(root->word))
	{
		root->left=deletekeyword(root->left,word);
	}
	else if(word>(root->word))
	{
		root->right=deletekeyword(root->right,word);
	}
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			root=NULL;
		}
		else if(root->left==NULL)
		{
			node *temp=root;
			root=root->right;
			temp=NULL;
			delete temp;
		}
		else if(root->right==NULL)
		{
			node *temp=root;
			root=root->left;
			temp=NULL;
			delete temp;
		}
		else
		{
			node *temp=findmin(root->right);
			root->word=temp->word;
			root->right=deletekeyword(root->right,word);
		}
	}
	return root;
}

int main()
{
	char data[20],datameaning[20];
	char ch,choice;
	int chh;
	string mean;
	dictionary dic;
	node *root=NULL;
	cout<<"hello dictionary!"<<endl;
	do
	{
		cout<<"enter word to be inserted in the dictionary: "<<endl;
		cin>>data;
		cout<<"enter the meaning of the given word: "<<endl;
		cin>>datameaning;
		root=dic.create(root,data,datameaning);
		cout<<"do you want to add more words? "<<endl;
		cin>>ch;
	}while(ch=='y');
	cout<<"your dictionary is created now!"<<endl;
	cout<<"do you want to check the created dictionary?"<<endl;
	cout<<"enter 'y' if you wish to do so!"<<endl;
	cin>>choice;
	while(choice=='y')
	{
		cout<<"choose from following operations you want to perform on it?"<<endl;
		cout<<"1.display\n2.delete keyword\n3.add new keyword\n4.update meaning of keyword\n5.search keyword"<<endl;
		cin>>chh;
		switch(chh)
		{
		case 1:
			dic.display(root);
			break;
		case 2:
			cout<<"enter word you want to delete"<<endl;
			cin>>data;
			dic.deletekeyword(root,data);
			break;
		case 3:
			cout<<"enter the new keyword you want to insert: "<<endl;
			cin>>data;
			cout<<"enter the meaning of the keyword: "<<endl;
			cin>>datameaning;
			root=dic.create(root,data,datameaning);
			break;
		case 4:
			dic.updatemeaning(root);
			break;
		case 5:
			cout<<"enter the word you want to search?"<<endl;
			cin>>data;
			dic.searchkeyword(root,data,0);
			break;
		default:
			cout<<"you had entered a wrong choice!"<<endl;
			break;
		}
		cout<<"do you want to perform more operations?"<<endl;
		cout<<"enter 'y' to continue "<<endl;
		cin>>choice;
	}


return 0;
}

