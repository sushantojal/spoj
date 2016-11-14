#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

int convert( string s, int number)
{
    stringstream convert(s);
    if ( !(convert >> number) )
    number = 0;
    return number;

}

int main()
{
    int tc;
    scanf("%d", &tc);

    while( tc-- )
    {
        string exp;
        string exp1, exp2, exp3;

        int i = 0; int chk = 0;

        cin>>exp;
        cout<<exp<<endl;


        while( exp[i] != ' ' )
        {
            exp1 = exp1 + exp[i];
            if( exp[i] == 'm')
                chk = 1;
            i++;
        }
        cout<<exp1<<endl;

        i = i+3;

        while( exp[i] != ' ' )
        {
            exp2 = exp2 + exp[i];
            if( exp[i] == 'm')
                chk = 2;
            i++;
        }

        i = i+3;

        while( i<exp.length() )
        {
            exp3 = exp3 + exp[i];
            if( exp[i] == 'm')
                chk = 3;
            i++;
        }
        //int number1 = atoi( exp1.c_str() );
        //int number2 = atoi( exp2.c_str() );
        //int number3 = atoi( exp3.c_str() );

        //cout<<exp1<<endl<<exp2<<endl<<exp3<<endl;

        int number1 = convert( exp1, number1);
        int number2 = convert( exp2, number2);
        int number3 = convert( exp3, number3);


        switch(chk)
        {
            case 1:
                number1 = number3 - number2;
                printf("%d %s %d %s %d\n", number1, "+", number2, "=", number3 );
                break;
            case 2:
                number2 = number3 - number1;
                printf("%d % s % d %s %d\n", number1, "+", number2, "=", number3 );
                break;
            case 3:
                number3 = number1 + number2;
                printf("%d %s %d %s %d\n", number1, "+", number2, "=", number3 );
                break;
            default:
                break;
        }
    }

}




