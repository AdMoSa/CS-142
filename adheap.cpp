#include<iostream>
using namespace std;

class minheap
{
	public:
	int ar[50];
	int last;
	minheap()
	{	last=0;}
	
	
	int insert(int num);
	void display();
};

int minheap::insert(int num)
{
	ar[last]=num;		//enters value in the last position
	int i=last;
	
	//check if parent<child
	while(ar[(i-1)/2]>ar[i])
	{
		int temp=0;
		temp=ar[i];
		ar[i]=ar[(i-1)/2];
		ar[(i-1)/2]=temp;
		i=(i-1)/2;		//shift to swapped position
	}
	last++;	
}

void minheap::display()
{
	cout<<"//";
	for(int i=0;i<last;i++)
	{
		cout<<"ar["<<i<<"] is "<<ar[i]<<"  ";
	}
	cout<<"//\n";
}


int main()
{
	minheap min;
	int ch;
	do
	{
		cout<<"\nEnter your choice (1-5): ";
		cout<<"1 to Add to heap\n"<<"2 to delete root\n"<<"3 to display root\n"<<"4 to exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1: int x;
				cout<<"Enter the element you want to insert:\n";
        			cin>>x;
        			min.insert(x);
				break;
			case 2: cout<<"Work in progress\n";
        			//min.remove();
				break;
			case 3: min.display();
				break;
			case 4:	break;

 			default:cout<<"Enter a valid choice \n";
				break;
		}
	}
	while(ch!=4);
	return 0;
}
	
