#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


bool chkm( string s )
{
    int chk = 0;
    for( int i = 0; i < s.length(); i ++ )
        if( s[i] == 'm' )
            chk = 1;
    return chk;
}


int main()
{
    int tc;
    cin>>tc;
    while ( tc -- )
    {
        string exp1, op1 , exp2, op2, exp3;
        cin>>exp1>>op1>>exp2>>op2>>exp3;

        bool chk1 = chkm( exp1 );
        bool chk2 = chkm( exp2 );
        bool chk3 = chkm( exp3 );

        int number1, number2, number3 = 0;
        number1 = atoi( exp1.c_str() );
        number2 = atoi( exp2.c_str() );
        number3 = atoi( exp3.c_str() );

        if( chk1 == 1)
            number1 = number3 - number2;

        if( chk2 == 1)
             number2 = number3 - number1;

        if( chk3 == 1)
             number3 = number1 + number2;

        printf("%d %s %d %s %d\n", number1, "+", number2, "=", number3 );
    }
}






