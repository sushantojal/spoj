#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int temp = 0;

int pos( char * str, int i )
{

    if( i == ( strlen(str)-1 ) )
    {
        cout<<temp<<endl;
        return 1;
    }

    else
    {

        if( str[i] == 'l' )
        {
            temp = pos(str, i + 1 ) + 1;
            cout<<temp<<endl;
        }

        else
        {
            temp = pos( str, i + 1 ) - 1;
            cout<<temp<<endl;
        }
        return temp;

        //cout<<temp<<endl;
    }
}


int main()
{
    char str[1000];
    cin>>str;

    int x = pos( str, 0 );
}
