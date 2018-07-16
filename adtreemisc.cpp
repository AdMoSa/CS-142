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
        left=right=parent=NULL;
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
    void display(Node*temp);

};

void Tree::add(int num)
{
    int k=0;

    if(num%2!=0)
        k=num-2;
    if(num%2==0)
        k=num-3;

    Node *temp= new Node;
    cout<<"\nenter the data you want to enter :";
    cin>>temp->data;
	temp->left=temp->right=temp->parent=NULL;
    if(root==NULL)
    {
        root=temp;
        last=root;
        return;
    }
    if(num<=0)
        return;
    if(num%2!=0)
    {
        cout<<"inside case 1"<<endl;
        last->left->parent=last;
        last->left=temp;
        cout<<"Check data : "<<
        for(k;k<k+2;k++)
            add(k);
    }
    else if(num%2==0)
    {
        last->right->parent=last;
        last->right=temp;
        for(k;k<k+2;k++)
            add(k);
    }
    temp=last;
}

void Tree::display(Node*temp)
{
    if(temp==NULL)
        return;
    else
    {
        if(temp==root)
            cout<<temp->data<<"\t";
        if(temp->left!=NULL)
            cout<<temp->left->data<<"\t";
        if(temp->right!=NULL)
            cout<<temp->right->data<<"\t";
        if(temp->left==NULL&&temp->right==NULL)
            return;
        display(temp->left);
        display(temp->right);
    }
}

int main()
{
    Tree t;
	int ch,n=0;
	do
	{
		cout<<"\nEnter choice : \n";
		cout<<"1 to add node\n"<<"2 to display tree\n"<<"3 to search for object\n"<<"4 to delete an object\n"<<"5 to exit\n";
		cin>>ch;
		switch(ch)
		{

			case 1:
                t.add(n);
			    n++;
			    break;
			case 2:	t.display(t.root);break;

			case 3: /*int y;cout<<"\nenter element to search : ";
				cin>>y;
				Node *temp,*result;
				temp = new Node;
				temp->data=y;
				result=t.search(temp);
				if(result->data==y)
					cout<<"Object found. ";
				else
					cout<<"Object not found. ";*/
				break;
			case 4: /*int z;cout<<"\nenter element to delete : ";
				cin>>z;
				Node *tmp;
				tmp = new Node;

				tmp->data=z;
				t.remove(tmp);*/
				break;
			case 5:
			    return 0;

			deafult:cout<<"\n1 to add node\n"<<"2 to display tree\n"<<"3 to search for object\n"<<"4 to delete an object\n"<<"5 to exit\n";
				break;
		}
	}
	while(ch!=0);
	return 0;
}
