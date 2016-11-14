#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int tc;
    scanf( "%d", &tc );

    while( tc-- )
    {
        int pos;
        scanf( "%d", &pos );

        int linen = 0;
        int sum = 0;

        while( sum < pos)
        {
            sum = sum + linen;
            linen++;
        }
        linen = linen - 1;
        sum = sum - linen;


        //cout<<linen<<endl;
        //cout<<sum<<endl;


        int num, den;

        if( linen%2 == 0 )
        {
            num = linen - ( pos - sum ) + 1;
            den = linen + 1 - num;
           /* if(den == 0)
            {
                den = linen;
                num = 1;
            }*/

             printf("%s %d %s %d%s%d\n", "TERM", pos, "IS", den, "/", num);
        }
        else if( linen%2 == 1 )
        {
            num = linen - ( pos - sum ) + 1;
            den = linen + 1 - num;
             printf("%s %d %s %d%s%d\n", "TERM", pos, "IS", num, "/", den);
        }


    }
}
