#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n );

    int zerocurr, onecurr, twocurr = 0;
    int zeroprev, oneprev, twoprev = 1;

    if( n==1 )
        printf("%d/n", 3 );

    for( int i = 2; i <= n; i ++ )
    {
        zerocurr = zeroprev + oneprev;
        onecurr = zeroprev + oneprev + twoprev;
        twocurr = oneprev + twoprev;

        zeroprev = zerocurr;
        oneprev = onecurr;
        twoprev = twocurr;
    }

    printf("%d\n", (zerocurr + onecurr + twocurr) );
}

