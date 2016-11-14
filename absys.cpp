#include <iostream>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while( tc-- )
    {
        cout<<" blah "<<endl;
        string exp;
        string exp1, exp2, exp3;

        int i = 0; int chk = 0;

        cin>>exp;

        while( exp[i]!='+' )
        {
            exp1[i] = exp[i];
            if( exp[i] == 'm')
                chk = 1;
            i++;
        }

        i = i++;

        int j = 0;
        while( exp[i]!='=' )
        {

            exp2[j] = exp[i];
            if( exp[i] == 'm')
                chk = 2;
            i++; j++;
        }

        i = i++;

        int k = 0;
        while( i<exp.length() )
        {
            exp3[k] = exp[i];
            if( exp[i] == 'm')
                chk = 3;
            i++; k++;
        }

        int number1, number2, number3;
        number1 = atoi( exp1.c_str() );
        number2 = atoi( exp2.c_str() );
        number3 = atoi( exp3.c_str() );

        switch( chk )
        {
            case 1:
                number1 = number3 - number2;
                cout<< number1 << " + " << number2 << " = " << number3<<endl;
                break;
            case 2:
                number2 = number3 - number1;
                cout<< number1 << " + " << number2 << " = " << number3 << endl;
                break;
            case 3:
                number3 = number1 + number2;
                cout<< number1 << " + " << number2 << " = " << number3 << endl;
                break;
        }
        cout<<" blah "<<endl;
    }

}


