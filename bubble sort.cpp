#include<iostream>
using namespace std;
int main()
{
    int num, size;
    int arr[10];
    void bubbl(int [], int);
    cout<<"size of array"<<endl;
    cin>>size;
    cout<<"input the numbers to be sorted"<<endl;
    for(int i=0; i<size;i++)
    {
        cin>>num;
        arr[i]=num;
    }
    bubbl(arr,size);
    cout<<"after bubble sorting"<<endl;
    for (int i2=0;i2<size;i2++)
    {
        cout<<arr[i2]<<endl;
    }
    system("pause");
}    
    
void bubbl( int arr[],int size )
{
    for(int i1=0;i1<size-1;i1++)
    {
        for(int i2=0;i2<size-1;i2++)
        {
            if(arr[i2]>arr[i2+1])
            {
                int hold=arr[i2];
                arr[i2]=arr[i2+1];
                arr[i2+1]=hold;
            }
        }
    }
}
                
