#include <iostream>
#include <math.h>
using namespace std;

int revnum( int number, int numdigits );

int main()
{
    int tc;
    cin>>tc;

    while( tc-- )
    {
        int num1, num2;
        cin>>num1>>num2;

        int numdigits1 = 0;
        int numdigits2 = 0;
        int numdigits3 = 0;

        int num1copy = num1;
        int num2copy = num2;


        while( num1copy > 0 )
        {
            num1copy = num1copy/10;
            numdigits1++;
        }

        while( num2copy > 0 )
        {
            num2copy = num2copy/10;
            numdigits2++;
        }

        int revnum1 = revnum( num1, numdigits1 );
        int revnum2 = revnum( num2, numdigits2 );

        //cout<< revnum1<< " " <<revnum2<<endl;

        int sum = revnum1 + revnum2;
        int sumcopy = sum;

        while( sumcopy > 0 )
        {
            sumcopy = sumcopy/10;
            numdigits3++;
        }

        int revsum = revnum( sum, numdigits3 );

        cout<< revsum <<endl;
    }
}


int revnum( int number, int numberdigits )
{
    int i = 0;
    int revnum = 0;
    int numcopy = number;
    int numzeroes = 0;
    bool chk = 0;

    while( numcopy > 0 )
    {
        int rem = numcopy % 10;
        numcopy = numcopy / 10;
        if( rem!= 0)
            chk = 1;

        if( rem == 0 && chk == 0 )
        {
            numzeroes ++;
            continue;
        }

        else
            revnum = revnum + ( rem * static_cast<int>( pow( 10, ( numberdigits - i - numzeroes - 1 ) ) ) );

        i ++;
    }

    return revnum;
}






