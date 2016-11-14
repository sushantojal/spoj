#include<iostream>
using namespace std;
int main()
{
    float t1=clock();
    cout<<t1<<endl;
    int var;
    for(int j=1; j<=100; j++)
    {
    for(int i=0; i<=10; i++)
    {
        var=i;
        if(i==5)
        {
            var=100000;
            break;
        }
    }
    cout<<var<<endl;
}    
    float t2=clock();
    cout<<t2<<endl;
    system("pause");
}
        
            
