#include <stdio.h>
#include <math.h>

int main()
{
    int tc;
    scanf( "%d", &tc );
    long long int k; int n; long long int count;

    while( tc -- )
    {

        scanf( "%d", &n );
        scanf( "%lld", &k );
        n = n - 1;

        count = 0;

        while( 1 )
        {

            if( k == 1  )
            {
                 if( count%2 == 1 )
                    printf( "%d\n", 1 );
                 else
                    printf( "%d\n", 0 );
                 break;
            }

            else
            {
                long long int comp = static_cast<int>( pow ( 2, (n-1) ) );
                if( k == comp )
                    n = n - 1;
                else if( k < comp )
                    n = static_cast<int>( ( ( log10 ( static_cast<double>( k ) ) )/ 0.30102999566 ) + 1 );
                else if( k > comp )
                {
                    k = k - comp;
                    count++;
                    n = static_cast<int>( ( ( log10 ( static_cast<double>( k ) ) )/ 0.30102999566 ) + 1 );
                }
            }
        }
    }
}




