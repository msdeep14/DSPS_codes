//queue implementation
#include<iostream>
#include<stdlib.h>
int front=-1,rear=-1,arr[1000];
using namespace std;
class queue
{
public:
	int isempty();
	void insert();
	void dequeue();
	void display();
	int isfull();
};

int queue :: isempty()
{
	if(front==-1 && rear==-1)
		return 1;
	else
		return 0;
}

int queue :: isfull()
{
	if(front==999)
	{
		return 1;
	}
	else
        return 0;
}

void queue :: insert()
{
	int x;
	cout<<"enter the element to be inserted into the queue: "<<endl;
	cin>>x;
	if(isfull())
		{
			cout<<"queue is full"<<endl;
			return;
		}
	else if(isempty())
	{
		front=0;
		rear=0;
	}
	else
	{
		rear=rear+1;
	}
	arr[rear]=x;
}

void queue :: dequeue()
{
	if(isempty()==1)
	{
		cout<<"Nothing to dequeue!"<<endl;
		return;
	}
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		front=front+1;
	}
}

void queue :: display()
{
	int i;
	for(i=front;i<=rear;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

int main()
{
	class queue q;
	int i,j,n;
	int choice;
	char ch='y';

	do
	{
		cout<<"choose the operations to perform on the queue: ";
		cout<<"1.isempty\n2.insert\n3.dequeue\n4.display\n5.exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				q.isempty();
				cout<<"do you wish to contiue, enter 'y' for this? "<<endl;
				cin>>ch;
				break;
			case 2:
				q.insert();
				cout<<"do you wish to contiue, enter 'y' for this? "<<endl;
				cin>>ch;
				break;
			case 3:
				q.dequeue();
				cout<<"do you wish to contiue, enter 'y' for this? "<<endl;
				cin>>ch;
				break;
			case 4:
				q.display();
				cout<<"do you wish to contiue, enter 'y' for this? "<<endl;
				cin>>ch;
				break;
			default:
				cout<<"you had entered the wrong choice!"<<endl;
				cout<<"do you wish to contiue, enter 'y' for this? "<<endl;
				cin>>ch;
				break;
		}
	}while(ch=='y');
	return 0;
}

