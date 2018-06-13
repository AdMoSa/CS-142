//Linear Search in array

#include<iostream>

using namespace std;

void display(int x,int y,int z);

int main()
{
    int ar[10],a;
    int count=0,s[10],p[10];
    for(int i=0;i<10;i++)
    {
        cout<<"Enter array element "<<i<<" : ";
        cin>>ar[i];
    }
    cout<<"Now enter element to search for : ";
    cin>>a; cout<<"\n";
    for(int j=0,m=0;j<10;j++)
    {
        if(ar[j]==a)
        {
            count++;
            s[m]=j; p[m]=j+1;
            m++;
        }
    }

    if(count!=0)
    {
        cout<<"Object found at "<<count<<" places :\n\n";
        for(int k=0;k<count;k++)
        {
            display(s[k],p[k],k);
        }
    }
    else
        cout<<"Object not found!!";
    return 0;


}

void display(int x,int y,int z)
{
    cout<<z+1<<". Index : "<<x<<"\tPosition : "<<y<<"\n";
}
