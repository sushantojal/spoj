#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc -- )
    {
        int n;
        scanf("%d", &n );

        int k;
        scanf("%d", &k );

        int *arr = new int[n];

        for( int i = 0; i < n; i++ )
            scanf("%d", &arr[i] );

        sort(arr, arr+n);

        int diff = 1000000000;

        for( int i = 0; i < n-k+1; i ++ )
        {
            int temp = arr[i+k-1] - arr[i];
            if( temp < diff )
                diff = temp;
        }

        printf("%d\n", diff );
    }
}





