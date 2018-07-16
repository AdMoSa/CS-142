//Program to sort numbers in an ascending manner

#include<iostream>

using namespace std;

int main()
{
    int ar[10];
    cout<<"Enter the sequence : ";
    for(int i=0;i<10;i++)
        cin>>ar[i];
    for(int i=1,j=0;i<10;i++,j++)
    {
        int k=i;
        for(k;k<10;k++)
        {
           if(ar[j]>ar[k])
           {
            int temp;
            temp=ar[j];
            ar[j]=ar[k];
            ar[k]=temp;
           }
        }
    }
    cout<<"The sorted sequence is : \n";
    for(int i=0;i<10;i++)
        cout<<ar[i]<<"\n";
    return 0;
}
