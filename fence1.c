#include <stdio.h>
int main()
{
    int tc;
    scanf("%d", &tc );

    while ( tc -- )
    {
        int n;
        scanf("%d", &n );
        long long int ans = n;
        for( int i = 0; i < 4; i ++ )
        {
            ans = ans * ( n - i );
            if( ans >= 1000000007 )
                ans = ans%1000000007;
        }
        ans = ans / 24;
        printf("%lld\n", ans );

    }
}



