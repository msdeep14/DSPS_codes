package project;
import java.io.*;


public class Queue {
	public static int front=-1;
	public static int rear=-1;
	public static int arr[]= new int[1000];
	public static int isempty(){
		if(front==-1 && rear==-1)
			return 1;
		else
			return 0;
	}
	public static void insert(){

		try{
		BufferedReader brr= new BufferedReader ( new InputStreamReader ( System.in));
		int x;
		System.out.println("enter the element to be inserted into the queue: ");
		x=Integer.parseInt ( brr.readLine());
		if(isfull()==1)
			{
				System.out.println("queue is full");
				return;
			}
		else if(isempty()==1)
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
		catch ( IOException ie ) {
			System.out.println ( "error in input" );
		}
		
	}
	public static void dequeue(){
		if(isempty()==1)
		{
			System.out.println("Nothing to dequeue!");
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
	public static  void display(){
		int i;
		if(front==-1 && rear==-1)
		{
			System.out.println("there is nothing to display in queue");
		}
		else
		{
		for(i=front;i<=rear;i++)
		{
			System.out.print(arr[i]);
			System.out.print(" ");
		}
		}
		System.out.println("");

	}
	public static int isfull(){
		if(front==999)
		{
			return 1;
		}
		else
	        return 0;
	}
	public static void main(String args[])
	{
		try
		{
		BufferedReader br= new BufferedReader ( new InputStreamReader ( System.in));
		int choice;
		int ch;
		System.out.println("if you want to perform operations, enter 1");
		ch=Integer.parseInt ( br.readLine());

		do
		{
			try{
			System.out.println("choose the operations to perform on the queue: ");
			System.out.println("1.isempty\n2.insert\n3.dequeue\n4.display\n5.exit");
			choice=Integer.parseInt ( br.readLine());
			switch(choice)
			{
				case 1:
					isempty();
					System.out.println("do you wish to contiue, enter '1' for this? ");
					ch=Integer.parseInt ( br.readLine());
					break;
				case 2:
					insert();
					System.out.println("do you wish to contiue, enter '1' for this? ");
					ch=Integer.parseInt ( br.readLine());
					break;
				case 3:
					dequeue();
					System.out.println("do you wish to contiue, enter '1' for this? ");
					ch=Integer.parseInt ( br.readLine());
					break;
				case 4:
					display();
					System.out.println("do you wish to contiue, enter '1' for this? ");
					ch=Integer.parseInt ( br.readLine());
					break;
				case 5:
					System.exit(0);

				default:
					System.out.println("you had entered the wrong choice!");
					System.out.println("do you wish to contiue, enter '1' for this? ");
					ch=Integer.parseInt ( br.readLine());
					break;
			}
			
			}
			catch ( IOException ie ) {
				System.out.println ( "error in input" );
			}

		}while(ch==1);
		
	}
	
	catch ( IOException ie ) {
		System.out.println ( "error in input" );
	}	
	
	}
}



