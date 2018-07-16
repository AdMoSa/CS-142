#include<iostream>
using namespace std;

// function definition to swap the values.
void swap(int &x, int &y)
{
   int temp;
   temp = x; /* save the value at address x */
   x = y;    /* put y into x */
   y = temp; /* put x into y */

   return;
}


class minheap
{
	public:
	int ar[50];
	int last;
	minheap()
	{	last=0;}


	int insert(int num);
	void remove(int num);
	void display();
};

int minheap::insert(int num)
{
	ar[last]=num;		//enters value in the last position
	int i=last;

	//check if parent<child
	while(ar[(i-1)/2]>ar[i])
	{
		swap(ar[(i-1)/2],ar[i]);
		i=(i-1)/2;		//shift to swapped position
	}
	last++;
}

void minheap::remove(int index)
{
    int i=index;
    if(ar[i]==-1)
        return;
    if(ar[2*i+1]==-1||ar[2*i+2]==-1)
        return;
    if(ar[i]>ar[2*i+1])
    {
        swap(ar[i],ar[2*i+1]);
        remove(2*i+1);
    }
    if(ar[i]>ar[2*i+2])
    {
        swap(ar[i],ar[2*i+2]);
        remove(2*i+2);
    }
    else
        return;
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
  void swap(int &x, int &y);
	minheap min;
	int ch;
	do
	{
		cout<<"\nEnter your choice (1-5): ";
		cout<<"1 to Add to heap\n"<<"2 to delete root\n"<<"3 to display heap\n"<<"4 to exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1: 
          int x;
				  cout<<"Enter the element you want to insert:\n";
				  cin>>x;
          min.insert(x);
          break;
			case 2:
			    min.ar[0]=min.ar[min.last-1];
          min.ar[min.last-1]=-1;
          min.last--;
          min.remove(0);
  				break;
			case 3:
          min.display();
				  break;
			case 4:
          break;
      default:cout<<"Enter a valid choice \n";
				  break;
		}
	}
	while(ch!=4);
	return 0;
}
