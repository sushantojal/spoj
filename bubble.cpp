#include <iostream>
using namespace std;
int main()
{
    int count=0;
    bool var2=0;
    int var1=0;
    int arr[]={3,2,5,6,10,1,4,7,8,9,10};
    for(int i=0; (i<=8)&&(var2!=1); i++)
    {
        for(int j=0; j<=(8-count); j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                var1=1;
            }
        }
        if(var1==0)
        var2=1;
        count++;
    }
    for(int k=0; k<10; k++)
    {
        cout<<arr[k]<<"  ";
    }
    system("pause");
}
                    
