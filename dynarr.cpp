#include <iostream>
using namespace std;
int main()
{
    int x,y,var1;
    cout<<"no. of rows"<<endl;
    cin>>x;
    cout<<"no. of columns"<<endl;
    cin>>y;
    int **ptr=new int* [x];
    int *ptr2= new int[y];
    for(int i=0; i<x; i++)
    {
        
        for(int j=0; j<y; j++)
        {
            cin>>var1;
            ptr[j]=var1;
        }
    }
    for(int k=0; k<x; k++)
    {
        for(int l=0; l<y; l++)
        {
            cout<<*ptr[l]<<" ";
        }
        cout<<endl;
    }
    system("pause");
}
                
