#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    long long int cat[1001];
    for( int i = 0; i <= 1000; i ++ )
        cat[i] = 0;

    cat[0] = 1;

    for( int i = 1; i < 1001; i ++ )
    {
        for( int j = 0; j < i; j ++ )
        {
            cat[i] = cat[i] + cat[j]*cat[i - 1 - j];
            if( cat[i] >= 1000000 )
                cat[i] = cat[i] % 1000000;
        }
    }

    while( 1 )
    {
        int n;
        scanf("%d", &n );

        if( n== 0 )
            break;

        printf( "%lld\n", cat[n] );
    }
}
