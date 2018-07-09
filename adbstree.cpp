#include<iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *left,*right,*parent;
	Node()
	{
		data=0;
		left=NULL;
		right=NULL;
		parent=NULL;
	}
};


class Tree
{
	public:
	Node *root,*last;
	Tree()
	{
		root=NULL;
	}

	void add(int num);
	void display(Node *temp);
	Node *search(Node *temp);
	Node *remove(Node *temp);
};


void Tree::add(int num)
{
	Node *temp= new Node;
	temp->data=num;
	temp->left=temp->right=NULL;
	if(root==NULL)
	{	
	
		root=temp;
		return;
	}
	else
	{
		Node *curr;
		curr=root;
		while(1)
		{	
			if(num<curr->data)
			{
				if(curr->left==NULL)
				{
					temp->parent=curr;
					curr->left=temp;
					break;
				}
				else
					curr=curr->left;
			}
			else
			{
				if(curr->right==NULL)
				{
					temp->parent=curr;
					curr->right=temp;
					break;
				}
				else
					curr=curr->right;
			}
		}
	}

}


void Tree::display(Node *temp)
{
	if(temp==NULL)
         return;
      display(temp->left);
      cout<<"\t"<<temp->data;
      display(temp->right);
}

Node* Tree::search(Node *temp)
{	
	Node *curr; int num;
	curr=root;
	num= temp->data;
	if(num==curr->data)
		return curr;
	while(1)
	{
		
		if(num<curr->data)
		{
			if(num==curr->left->data)
			{
				return curr->left;
				break;
			}
			else
				curr=curr->left;
		}
		else
		{	
			if(num==curr->right->data)
			{
				return curr->right;
				break;
			}
			else
				curr=curr->right;
		}
	}

}

Node* Tree::remove(Node*temp)
{
	Node *curr,*ab;
	curr=root;
	Delete0()
	{
		if(curr->left==NULL&&curr->right==NULL)
		{
			ab=curr->parent;			
			curr=NULL;
			if(ab->left==NULL)
				


int main()
{
	Tree t;
	int ch;
	do
	{
		cout<<"\nEnter choice : \n";
		cout<<"1 to add node\n"<<"2 to display tree\n"<<"3 to search for object\n"<<"4 to exit\n";
		cin>>ch;
		switch(ch)
		{
			
			case 1:	int x;cout<<"\nenter the data you want to enter :";
         			cin>>x;
				t.add(x);break;
			case 2:	t.display(t.root);break;
			
			case 3: int y;cout<<"\nenter element to search : ";
				cin>>y;
				Node *temp,*result;
				temp = new Node;
				temp->data=y;
				result=t.search(temp);
				if(result->data==y)
					cout<<"Object found. ";
				else
					cout<<"Object not found. ";
				break;
			
			case 4: return 0;

			deafult:cout<<"\n1 to add node\n"<<"2 to display tree\n"<<"3 to search for object\n"<<"4 to exit\n";
				break;
		}
	}
	while(ch!=0);
	return 0;
}

			
			













