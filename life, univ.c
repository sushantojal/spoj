#include <iostream>
using namespace std;

int main()
{
bool cond=1;
while(cond)
{
int x;
cin>>x;
if((-100<x) && (x<100))
{
    if(x==42)
    cond=0;
    else
    cout<<x<<endl;
}
}
}
