#include <iostream>
using namespace std;

int main()
{
    int arr[3];
    bool chk;
    string typ;
    int next;

    while( 1 )
    {
        chk = 0;
        for( int i = 0; i < 3; i ++)
        {
            cin>>arr[i];
            if( arr[i] != 0)
                chk = 1;
        }

        if( chk == 0 )
            break;

        if( ( arr[2] - arr[1] ) == ( arr[1] - arr[0] ) )
            typ = "AP";
        else
            typ = "GP";

        if( typ == "AP" )
            next = arr[2] + ( arr[2]-arr[1] );
        else
            next = arr[2] * ( arr[2] / arr[1] );

        cout<<typ<<" "<<next<<endl;
    }
}








