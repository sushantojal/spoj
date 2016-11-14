#include<iostream>
#include<ctime>
using namespace std;
int main()
{
    int k=1;
    float i=clock();
    while (1)
    {
        if((clock()-i)>=1000)
        {
            cout<<k<<endl;
            k++;
            i=clock();
        }
        if(k==11)
        break;    
    }
    system("pause");
}        
