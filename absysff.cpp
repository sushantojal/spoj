#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std;

int chkm( string a, int expnum )
{
    for( int i = 0; i < (a.length()-6); i ++ )
    {
        if( a[i] == 'm' )
            return expnum;
    }
    return 0;
}

int convert( string s )
{
    int number;
    stringstream convert(s);
    if ( !(convert >> number) )
    number = 0;
    return number;

}

int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc-- )
    {
        string exp1, op1 , exp2, op2, exp3;
        cin>>exp1>>op1>>exp2>>op2>>exp3;

        int number1, number2, number3;
        int chk1, chk2, chk3 = 0;

        chk1 = chkm( exp1, 1);
        chk2 = chkm( exp2, 2 );
        chk3 = chkm( exp3, 3 );

        number1 = convert( exp1 );
        number2 = convert( exp2 );
        number3 = convert( exp3 );

        if( chk1 == 1)
        number1 = number3 - number2;

        if( chk2 == 2)
        number2 = number3 - number1;

        if( chk3 == 3)
        number3 = number1+ number2;

     /*





        chk = chkm(exp1, 1 );
        if( !chk )
           number1 = convert( exp1 );
        else
            {
                chkf = chk;
                chk = 0;
            }


        if( !chkf )
        chk = chkm(exp2, 2 );

        if( !chk )
           number2 = convert( exp2 );
        else
            {
                chkf = chk;
                chk = 0;
            }
        if( !chkf )
        chk = chkm( exp3, 3 );

        if( !chk  )
           number3 = convert( exp3 );
        else
            chkf = chk;

        if( chkf == 1 )
        number1 = number3 - number2;
        else if( chkf == 2 )
        number2 = number3 - number1;
        else if( chkf == 3 )
        number3 = number1 + number2;*/

        printf("%d %s %d %s %d\n", number1, "+", number2, "=", number3 );

    }
}
