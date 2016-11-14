#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n );

    int zerocurr = 0;
    int onecurr  = 0;
    int twocurr = 0;
    int zeroprev = 1;
    int oneprev = 1;
    int twoprev = 1;

    if( n==1 )
        printf("%d\n", 3 );
    else
    {
        for( int i = 2; i <= n; i ++ )
        {
            zerocurr = zeroprev + oneprev;
            onecurr = zeroprev + oneprev + twoprev;
            twocurr = oneprev + twoprev;

            zeroprev = zerocurr;
            oneprev = onecurr;
            twoprev = twocurr;
        }
        int total = zerocurr + onecurr + twocurr;

        printf("%d\n", total );
    }
}

