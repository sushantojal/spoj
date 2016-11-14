#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc );
    int count = 1;

    while( tc -- )
    {
        int n;
        scanf("%d", &n );

        if( n== 0 )
        {
            printf("Case %d: 0\n", count );
            count++;
            continue;
        }

        int *arr = new int[n];
        for( int i = 0; i < n; i ++ )
            scanf("%d", &arr[i] );

        long long int *maxval = new long long int[n];
        for( int i = 0; i < n; i++ )
            maxval[i] = 0;

        maxval[0] = arr[0];
        if( arr[1] > arr[0] )
            maxval[1] = arr[1];
        else
            maxval[1] = arr[0];

        for( int i = 2; i < n; i ++ )
        {
            long long int temp = arr[i] + maxval[i-2];
            if( temp >= maxval[i-1] )
                maxval[i] = temp;
            else
                maxval[i] = maxval[i-1];
        }
        printf("Case %d: %lld\n", count, maxval[n-1] );
        count++;
    }
}



