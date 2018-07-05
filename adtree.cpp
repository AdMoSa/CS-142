#include<iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *left,*right;
	Node()
	{
		data=0;
		left=NULL;
		right=NULL;
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
};


void Tree::add(int num)
{
	/*Node *temp=new Node;
	temp->data=num;	
	temp->left=temp->right=NULL;
	int n=2;
	if(root==NULL)
	{		
		root=temp;
		cout<<"first case\n";
		return;
	}
	else
	{
		cout<<"not first case\n";
		Node *curr;
		curr=root;
		while(1){	
			if(curr->left==NULL)
			{	
				cout<<"check safe";
				curr->left=temp;
				break;
			}		
			if(curr->right==NULL)
			{
				curr->right=temp;
				break;
			}
			if(n%2==0)
				curr=curr->left;
			else
				curr=curr->right;
		}
	}*/
	Node *temp=new Node;
   temp->data=num;
   temp->left=temp->right=NULL;

   if(root==NULL)
   { root=temp;
   }
   else{ Node *curr;
         curr=root;
        while(1)
	{
            if(num<curr->data)
		{
	               if(curr->left==NULL)
			{
	                  curr->left=temp;
		               break;
	               }
 	             else{curr=curr->left;}
        	 }
           else 
		{
                    if(curr->right==NULL)
                       {
                       curr->right=temp;
                     break;
			}
                   else{curr=curr->right;}
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


int main()
{
	Tree t;
	cout<<"Enter choice : \n";
	cout<<"1 to add node\n"<<"2 to display tree\n";
	int ch;
	cin>>ch;
	do
	{
		switch(ch)
		{
			case 1:	int x;cout<<"\nenter the data you want to enter :";
         			cin>>x;
				t.add(x);break;
			case 2:	t.display(t.root);break;

			deafult:cout<<"\n1 to add node\n"<<"2 to display tree\n";break;
		}
	}
	while(ch!=0);
	return 0;
}

			
			













