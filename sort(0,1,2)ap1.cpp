//Program to sort 0s,1s and 2s in an increasing order and their values using Method 1

#include<iostream>

using namespace std;

int main()
{
    int ar[10],czero=0,cone=0,ctwo=0;
    cout<<"Enter the sequence : ";
    for(int i=0;i<10;i++)
        cin>>ar[i];
    for(int i=0;i<10;i++)
    {
        if(ar[i]==0)
            czero++;
        else if(ar[i]==1)
            cone++;
        else
            ctwo++;
    }
    cout<<"No of zeros : "<<czero<<"\nNo of ones : "<<cone<<"\nNo of twos : "<<ctwo;
    for(int i=0;i<czero;i++)
    {
        ar[i]=0;
    }
    for(int i=czero;i<10-ctwo;i++)
    {
        ar[i]=1;
    }
    for(int i=czero+cone;i<10;i++)
    {
        ar[i]=2;
    }
    cout<<"\nThe sorted array is : \n";
    for(int i=0;i<10;i++)
        cout<<ar[i]<<"\n";
    return 0;
}
