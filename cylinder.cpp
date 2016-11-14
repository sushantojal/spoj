#include <iostream>
#include <iomanip>

using namespace std;
#define pi 3.1415926535897932384626433832795

int main()
{
    while( 1 )
    {
        int w;
        cin>>w;

        int h;
        cin>>h;

        if( w==0 && h == 0 )
            break;

        if( w<h )
        {
            int temp = w;
            w = h;
            h = temp;
        }


        float temp1 = h/pi;
        float temp2 = 2*w/3;
        float V1; float V2;

        if( temp1 >= temp2 )
            V1 = (pi*w*w*w)/27;
        else
            V1 =( pi*temp1*temp1*(w - temp1) )/4;

        float temp3 = w/(1 + pi);
        if( temp3 >= h )
            V2 = pi*h*h*h/4;
        else
            V2 = pi*temp3*temp3*h/4;

        cout<<fixed;
        if( V1 > V2 )
            cout<<setprecision(3)<<V1<<endl;
        else
            cout<<setprecision(3)<<V2<<endl;
    }
}


