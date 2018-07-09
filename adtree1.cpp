//Binary Tree

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

	void add(Node *naya);
	void display(Node *temp);
};


void Tree::add(Node *naya)
{
	Node *temp=new Node;
	int num;
	cout<<"\nenter the data you want to enter :";
	cin>>num;
	temp->data=num;
	temp->left=temp->right=NULL;
	int n=2;
	if(naya==NULL)
	{
		naya=temp;
		if(n==2)
            root=naya;
		cout<<"first case\n";
		return;
	}
	else
	{
		cout<<"not first case\n";
		Node *curr;
		curr=naya;
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
			if(curr->left!=NULL)
            {
                add(curr->left);
            }
			if(curr->right!=NULL)
			{
			    add(curr->right);
				break;
			}
            n++;
		}
	}

}


void Tree::display(Node *temp)
{
	if(temp==NULL)
         return;
      cout<<"\t"<<temp->data;
      display(temp->left);
      display(temp->right);
}


int main()
{
	Tree t;
	int ch;
	do
	{
	    cout<<"Enter choice : \n";
        cout<<"1 to add node\n"<<"2 to display tree\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				t.add(t.root);
				break;
			case 2:
			    t.display(t.root);
			    break;

			deafult:
			    cout<<"\n1 to add node\n"<<"2 to display tree\n";
			    break;
		}
	}
	while(ch!=0);
	return 0;
}
