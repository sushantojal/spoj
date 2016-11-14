#include <iostream>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    int arr[tc][2];
    int darr[tc][tc];
    int term1; int term2;
    int x,y;
    for(int var3=0; var3<tc; var3++)
    {
            cin>>x>>y;
            arr[var3][0]=x;
            arr[var3][1]=y;
    }
    for(int var1=0; var1<tc; var1++)
    {
            for(int var2=var1; var2<tc; var2++)
            {
                    if(var1==var2)
                    darr[var1][var2]=-1;
                    else
                    {
                        term1=arr[var1][0]-arr[var2][0];
                        if(term1<0)
                        term1=-term1;
                        term2=arr[var1][1]-arr[var2][1];
                        if(term2<0)
                        term2=-term2;
                        darr[var1][var2]=term1+term2;
                        darr[var2][var1]=darr[var1][var2];
                    }
            }
    }
    delete arr;       
    int temp;
    for(int var4=0; var4<tc; var4++)
    {
        if(var4==0)
            temp=darr[var4][1];
        else
            temp=darr[var4][0];
            for(int var5=0; var5<tc; var5++)
            {
                    if((darr[var4][var5]<temp)&&(darr[var4][var5]!=-1))
                    {
                         temp=darr[var4][var5];
                    }
            }
            cout<<temp<<endl;
    }
}
