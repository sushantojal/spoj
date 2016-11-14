#include <iostream>
#include<stdlib.h>
using namespace std;
int m,n;
int main()
{ 
    cout<<"Input"<<endl;
    int t;
    cin>>t;
    if(t>10)
    return 0;
    int size=2*t;
    int *arr=new int[size];
    for(int k=0; k<=(size-1); k++)
    {
        int num1;
        cin>>num1;
        arr[k]=num1;
    }
    cout<<endl<<endl<<endl<<"Output"<<endl;
    for(int l=0; l<=size-1; l+=2)
    {
       m=arr[l];
       n=arr[l+1];
       int *arr2=new int[n-1];
       for(int i=0; i<=n-2; i++)
       {
           arr2[i]=i+2;
       }
       int p=2;
       while((p*p)<=n)
       {
           for(int j=p; j<=n-1; j++)
           {
               if(arr2[j-1]%p==0)
               arr2[j-1]=0;
           }
           
           for(int k=(p-1); k<=(n-2); k++)
           {
               if(arr2[k]!=0)
               {
                   p=arr2[k];
                   break;
               }
           }
       }  
       if(m==1)
       m=2;  
       for(int var=m-2; var<=n-2; var++)
       {
           if(arr2[var]!=0)
           cout<<arr2[var]<<endl;
       }
       cout<<endl<<endl;
   }
   system("pause");    
}          
