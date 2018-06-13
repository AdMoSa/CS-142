//Program to find median of 10 numbers

#include<iostream>

using namespace std;

int main()
{
    int ar[10];
    cout<<"Enter the sequence : ";
    for(int i=0;i<10;i++)
        cin>>ar[i];
    for(int i=1,j=0;i<7;i++,j++)
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
    float m[2];
    m[0]=ar[4]; m[1]=ar[5];
    float med=(m[0]+m[1])/2;
    cout<<"The median is : "<<med;
    return 0;
}
