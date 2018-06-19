#include<iostream>

using namespace std;

int main()
{
    int ar[100],n;
    cout<<"Enter the array size n : ";
    cin>>n;
    cout<<"Enter the sequence : ";
    for(int i=0;i<n;i++)
   	cin>>ar[i];
    int h;
    if(n%2==0)
    {
	h=n/2;
	for(int i=0,k=h;i<h;i++,k++)
        {	
	int temp;
	temp=ar[i];
 	ar[i]=ar[k];
        ar[k]=temp;
        }
    }
    
    else
    {
	h=(n/2);
	int temp[n];
	
	for(int i=0;i<h;i++)
	{	temp[i]=ar[i];}
	for(int i=0;i<h+1;i++)
	{	ar[i]=ar[i+h];
		if(i>0)
		ar[i+h]=temp[i-1];
        }
    }
    cout<<"The sequence after first shuffle is : \n";
    for(int i=0;i<n;i++)
        cout<<ar[i]<<"\n";

    int shuf[n],q;
    if(n%4!=0)
    {
	q=n/4;
	int k=0;
	for(int i=q;i<n-(q+1);i++,k++)
	{
	 shuf[k]=ar[i];
	 //cout<<temp[k]<<"\n";
        }
	for(int i=0;k<n-(q+1);k++,i++)
	{shuf[k]=ar[i];}
	for(int i=n-(q+1);i<n;i++)
	{shuf[i]=ar[i];}
    }    

    else
    {
	q=n/4;
	int k=0;
	for(int i=q;i<n-q;i++,k++)
	{
	 shuf[k]=ar[i];
	 //cout<<temp[k]<<"\n";
        }
  	for(int i=0;k<n-q;k++,i++)
	{shuf[k]=ar[i];}
	for(int i=n-q;i<n;i++)
	{shuf[i]=ar[i];}

    }
	
    cout<<"The sequence after second shuffle is : \n";
    for(int i=0;i<n;i++)
        cout<<shuf[i]<<"\n";
    if(n%2==0)
    {
	h=n/2;
	for(int i=0,k=h;i<h;i++,k++)
        {	
	int temp;
	temp=shuf[i];
 	shuf[i]=shuf[k];
        shuf[k]=temp;
        }
    }
    
    else
    {
	h=(n/2);
	int temp[n];
	
	for(int i=0;i<h;i++)
	{	temp[i]=shuf[i];}
	for(int i=0;i<h+1;i++)
	{	ar[i]=ar[i+h];
		if(i>0)
		shuf[i+h]=temp[i-1];
        }
    }

    cout<<"The sequence after third shuffle is : \n";
    for(int i=0;i<n;i++)
        cout<<shuf[i]<<"\n";

    return 0;
}
