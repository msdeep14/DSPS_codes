//double circular
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*start, *last;
int count = 0;
class double_clist
{
    public:
        node *create_node(int);
        void insert_begin();
        void insert_last();
        void insert_pos();
        void delete_pos();
        void display();
        double_clist()
        {
            start = NULL;
            last = NULL;			
        }
};
 
int main()
{
    int ch;
    double_clist dcir;
    while (1)
    {      
        cout<<"1.Insert at Beginning"<<endl;
        cout<<"2.Insert at end"<<endl;
        cout<<"3.Insert at Position"<<endl;
        cout<<"4.Delete at Position"<<endl;
        cout<<"5.Display final List"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            dcir.insert_begin();
            break;
        case 2:
            dcir.insert_last();
            break;   
        case 3:
            dcir.insert_pos();
            break; 
        case 4:
            dcir.delete_pos();
            break;
        case 5:
            dcir.display();
            break;
        case 6:
            exit(1); 
        default:
            cout<<"Wrong ch"<<endl;	
        }
    }
    return 0;
}
 
node* double_clist::create_node(int value)
{
    count++;  
    struct node *temp;
    temp = new(struct node);
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
 //INSERTS ELEMENT AT BEGINNING
void double_clist::insert_begin()
{
    int value;
    cout<<endl<<"Enter the element to be inserted: ";
    cin>>value;
    struct node *temp;
    temp = create_node(value);
    if (start == last && start == NULL)
    {    
        cout<<"Element inserted in empty list"<<endl;
        start = last = temp;
        start->next = last->next = NULL;
        start->prev = last->prev = NULL;
    }
    else
    {
        temp->next = start;
        start->prev = temp;
        start = temp;
        start->prev = last;
        last->next = start;
        cout<<"Element inserted"<<endl;
    }
}
 
 //INSERTS ELEMNET AT LAST
void double_clist::insert_last()
{
    int value;    
    cout<<endl<<"Enter the element to be inserted: ";
    cin>>value; 
    struct node *temp;
    temp = create_node(value);
    if (start == last && start == NULL)
    {
        cout<<"Element inserted in empty list"<<endl;
        start = last = temp;
        start->next = last->next = NULL;    
        start->prev = last->prev = NULL;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
        start->prev = last;
        last->next = start;
    }
}

 //INSERTS ELEMENT AT POSITION
void double_clist::insert_pos()
{    
    int value, pos, i;
    cout<<endl<<"Enter the element to be inserted: ";
    cin>>value;
    cout<<endl<<"Enter the postion of element inserted: ";
    cin>>pos;
    struct node *temp, *s, *ptr;
    temp = create_node(value);
    if (start == last && start == NULL)
    {
        if (pos == 1)
        {
            start = last = temp;
            start->next = last->next = NULL;    
            start->prev = last->prev = NULL;
        }
        else
        {
            cout<<"Position out of range"<<endl;
            count--;
            return;
        }
    }  
    else
    {
        if (count < pos)
        {
             cout<<"Position out of range"<<endl;
             count--;
             return;   		
        }
        s = start;		
        for (i = 1;i <= count;i++)
        {
            ptr = s;
            s = s->next;
            if (i == pos - 1)
            {
                ptr->next = temp;
                temp->prev = ptr;
                temp->next = s;
                s->prev = temp;
                cout<<"Element inserted"<<endl;
                break;
            }
        }
    }
}
 //Delete Node at Particular Position
void double_clist::delete_pos()
{    
    int pos, i;
    node *ptr, *s;
    if (start == last && start == NULL)
    {
        cout<<"List is empty, nothing to delete"<<endl;
        return;
    }
    cout<<endl<<"Enter the postion of element to be deleted: ";
    cin>>pos;
    if (count < pos)
    {
        cout<<"Position out of range"<<endl;
        return;
    }
    s = start;
    if(pos == 1)
    {
        count--;
        last->next = s->next;
        s->next->prev = last;
        start = s->next;
        free(s);
        cout<<"Element Deleted"<<endl;
        return;	   
    }
    for (i = 0;i < pos - 1;i++ )
    {  
        s = s->next;
        ptr = s->prev;    	  
    }    
    ptr->next = s->next;
    s->next->prev = ptr;
    if (pos == count)
    {
        last = ptr; 	   
    }
    count--;
    free(s);
    cout<<"Element Deleted"<<endl;
}

 // Display Elements of the List 
void double_clist::display()
{
    int i;
    struct node *s;
    if (start == last && start == NULL)
    {
        cout<<"The List is empty, nothing to display"<<endl;
        return;
    }
    s = start;
    for (i = 0;i < count-1;i++)
    {	
        cout<<s->data<<"<->";
        s = s->next; 
    }
    cout<<s->data<<endl;
}
