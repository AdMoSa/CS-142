
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
	void Delete0(Node *curr);
	void Delete1(Node *curr);
	void Delete2(Node *curr);
	void remove(Node *temp);
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

void Tree::Delete0(Node *curr)
{
    Node *ab;
    if(curr->left==NULL&&curr->right==NULL)
		{
			ab=curr->parent;
			if(curr==root)
            {
                root=NULL;
                return;
            }
			if(ab->left==curr)
            {
                ab->left=NULL;
            }
            else
            {
                ab->right=NULL;
            }
            delete curr; cout<<"deleted value";
		}
		else
        {
            cout<<"\ninvalid argument";
        }
}

void Tree::Delete1(Node *curr)
{
    Node *ab;
    if(curr->left!=NULL||curr->right!=NULL)
        {
            if(curr->left==NULL&&curr->right!=NULL)
            {
                ab=curr->parent;
                if(ab->left==curr)
                {
                    ab->left=curr->right;
                }
                else
                {
                    ab->right=curr->right;
                }
                delete curr; cout<<"deleted value";
            }
            if(curr->left!=NULL&&curr->right==NULL)
            {
                ab=curr->parent;
                if(ab->left==curr)
                {
                    ab->left=curr->left;
                }
                else
                {
                    ab->right=curr->left;
                }
                delete curr; cout<<"deleted value";
            }
            else
                cout<<"/ninvalid argument";

        }
}

void Tree::Delete2(Node *curr)
{
    Node *ab;
    if(curr->left!=NULL&&curr->right!=NULL)
    {
        ab=curr->right;
        while(ab->left!=NULL)
            ab=ab->left;
        curr->data=ab->data;
        if(ab->left==NULL&&curr->right==NULL)
        {   Delete0(ab); cout<<"deleted value";}
        if(ab->left!=NULL||ab->right!=NULL)
        {   Delete1(ab); cout<<"deleted value";}
        else
            cout<<"\nInvalid Argument.";

    }
}

void Tree::remove(Node*temp)
{
	Node *curr;
	curr=search(temp);

	if(curr->left==NULL&&curr->right==NULL)
	{
	    cout<<"Deleted "<<curr->data;
	    Delete0(curr);
	}
    else if(curr->left!=NULL||curr->right!=NULL)
    {
        cout<<"Deleted "<<curr->data;
        Delete1(curr);
    }
    else if(curr->left!=NULL&&curr->right!=NULL)
    {
        cout<<"Deleted "<<curr->data;
        Delete2(curr);
    }
    else
        cout<<"\nInvalid Argument.";

}


int main()
{
	Tree t;
	int ch;
	do
	{
		cout<<"\nEnter choice : \n";
		cout<<"1 to add node\n"<<"2 to display tree\n"<<"3 to search for object\n"<<"4 to delete an object\n"<<"5 to exit\n";
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
			case 4: int z;cout<<"\nenter element to delete : ";
				cin>>z;
				Node *tmp;
				tmp = new Node;

				tmp->data=z;
				t.remove(tmp);
			case 5: return 0;

			deafult:cout<<"\n1 to add node\n"<<"2 to display tree\n"<<"3 to search for object\n"<<"4 to delete an object\n"<<"5 to exit\n";
				break;
		}
	}
	while(ch!=0);
	return 0;
}

