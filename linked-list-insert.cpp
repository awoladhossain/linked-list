#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*head;

void create(int n);
void beg(int data);
void end(int data);
void mid(int data, int pos);
void travel();

int main()
{
    int data,n,pos;
    cout<<"enter the numbre to creat node: "<<endl;
    cin>>n;
    create(n);
    
    cout<<"the list: "<<endl;
    travel();
    
    cout<<endl;
    
    cout<<"enter the data to insert beg: "<<endl;
    cin>>data;
    beg(data);
    
    cout<<"the list is: "<<endl;
    travel();
    
    cout<<endl;
    
    cout<<"enter the data to insert end: "<<endl;
    cin>>data;
    end(data);
    
    cout<<"the list is: "<<endl;
    travel();
    
    cout<<endl;
    
    cout<<"enter the data and position to insert: "<<endl;
    cin>>data>>pos;
    mid(data,pos);
    
    cout<<"the list is: "<<endl;
    travel();
    
    return 0;
}

void create(int n)
{
    struct node *newnode,*temp;
    int i,data;
    
    head = (struct node*)malloc(sizeof(struct node));
    cout<<"enter the data for head: "<<endl;
    cin>>data;
    
    head->data = data;
    head->next = NULL;
    
    temp = head;
    cout<<"enter the data for others node: "<<endl;
    for(i=2; i<n; i++)
    {   cin>>data;
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        
        temp->next = newnode;
        temp = temp->next;
    }
}

void beg(int data)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    
    head = newnode;
}
void end(int data)
{
    struct node *newnode,*temp;
    
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data =data;
    newnode->next = NULL;
    
    temp = head;
    
    while(temp != NULL && temp->next !=NULL)
    {
        temp= temp->next;
    }
    temp->next = newnode;
}
void mid(int data, int pos)
{
    struct node *temp,*newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    temp = head;
    pos--;
    while(pos != 1)
    {
        temp = temp->next;
        pos--;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void travel()
{
    struct node *temp;
    temp = head;
    while(temp !=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}
