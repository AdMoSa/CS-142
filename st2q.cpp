#include <iostream>
using namespace std;

class Node
{
  public:
  int data;
  Node* next;
  Node()
  {
    data=0;
    next=NULL;
  }
};


/*   Stack via Linked list   */
class Stack
{
  public:
  Node* head;
  Stack()
  {
    head=NULL;
  }
  void push(int num);
  void pop();
  void display();
};

/*  pushing in a stack node  */
void Stack::push(int num)
{
  Node* temp=new Node;
  temp->data=num;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp;
    return;
  }
  temp->next=head;
  head=temp;
}


/*  popping in a stack node  */
void Stack::pop()
{
  Node* temp;
  if(head==NULL)
  {
   cout<<"\nThe queue is empty";
   return;
  }
  temp=head;
  head=head->next;
  temp->next=NULL;
  delete temp;
}


/*  displaying a stack  */
void Stack::display()
{
  Node *locate = head;
  cout<<"\n";
  while (locate!=NULL)
  {
    cout << locate->data << "->" ;
    locate = locate->next;
  }
  cout << "NULL" <<endl;
}

/* The queue using two stacks, front and rear */
class Queue
{public:
	Stack front;
            Stack rear;
            void insert(int x);
            void remov();
            void display();
};

/* adds elements by inserting them in front queue */
void Queue::insert(int x)
{front.push(x);
cout<<"\n Added element "<<x;
}

/* inverts the stack and pops out the head, the original end element and then reverts it back */
void Queue::remov()
{int temp;
while(front.head!=NULL)
{temp=front.head->data;
front.pop();
rear.push(temp);}
rear.pop();
cout<<"\n Deleted last element";
while(rear.head!=NULL)
{temp=rear.head->data;
rear.pop();
front.push(temp);}
}

/* inverts the stack, displays it and reverts it back*/
void Queue::display()
{int temp;
while(front.head!=NULL)
{temp=front.head->data;
front.pop();
rear.push(temp);}
rear.display();
while(rear.head!=NULL)
{temp=rear.head->data;
rear.pop();
front.push(temp);}}


/*program to check the queue*/
int main()
{ Queue q;
q.insert(12);
q.insert(15);
q.insert(16);
q.display();
q.remov();
q.display();
q.insert(17);
q.display();
q.remov();
q.display();
return 0;
}
