//Program to sort 0s and 1s in an increasing order Method 2

#include<iostream>

using namespace std;

int main()
{
    int ar[10],sort[10],z=0,o=0;
    cout<<"Enter the sequence : ";
    for(int i=0;i<10;i++)
        cin>>ar[i];
    for(int i=0;i<10;i++)
    {
        if(ar[i]==0)
        {
            sort[z]=ar[i];
            z++;
        }
        else if(ar[i]==1)
        {
            sort[9-o]=ar[i];
            o++;
        }
    }
    cout<<"No of zeros : "<<z<<"\nNo of ones : "<<o;
    cout<<"\nThe sorted array is : \n";
    for(int i=0;i<10;i++)
        cout<<sort[i]<<"\n";
    return 0;
}
