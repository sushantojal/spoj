#include <iostream>
using namespace std;
int main()
{
    int y;
    int i=1;
    int *arr= new int[i];
    for(; i<=10; i++)
    {
        cin>>y;
        arr[i]= y;
        i++;
    }
    for(int j=0; j<10; j++)
    cout<<arr[j];
system("pause");
}
        
