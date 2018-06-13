//Program to sort 0s,1s and 2s in an increasing order and count their values using Method 2

#include<iostream>

using namespace std;

int main()
{
    int ar[10],sort[10],z=0,o=0,t=0,on=0;
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
        else if(ar[i]==2)
        {
            sort[9-t]=ar[i];
            t++;
        }
    }
    o=z+t;
    for(int i=z;i<o;i++)
    {
        sort[i]=1;
        on++;
    }
    cout<<"No of zeros : "<<z<<"\nNo of ones : "<<on<<"\nNo of twos : "<<t;
    cout<<"\nThe sorted array is : \n";
    for(int i=0;i<10;i++)
        cout<<sort[i]<<"\n";
    return 0;
}
