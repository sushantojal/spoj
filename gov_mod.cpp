#include <iostream>
#include <stdio.h>

using namespace std;

void findnthpower( long long int *arr, int n, int m)
{
    if( n == 1 )
        return;
    else
    {
        findnthpower( arr, n/2, m );
        long long int *arr2 = new long long int[4];
        for ( int i = 0; i < 4; i ++ )
            arr2[i] = arr[i];
        arr[0] = ( (arr2[0] * arr2[0])%m + (arr2[1] * arr2[2])%m ) % m;
        arr[1] = ((arr2[0] * arr2[1])%m + (arr2[1] * arr2[3])%m)%m;
        arr[2] = ((arr2[2] * arr2[0])%m + (arr2[3] * arr2[2])%m)%m;
        arr[3] = ((arr2[2] * arr2[1])%m + (arr2[3] * arr2[3])%m)%m;
        delete[] arr2;

        /*if( arr[0] >= m )
            arr[0] = arr[0] % m;
        if( arr[1] >= m )
            arr[1] = arr[0] % m;
        if( arr[2] >= m )
            arr[2] = arr[0] % m;
        if( arr[3] >= m )
            arr[3] = arr[0] % m;*/


        if( n%2 == 1)
        {
            long long int *arr3 = new long long int[4];
            for( int i = 0; i < 4; i ++ )
                arr3[i] = arr[i];
            arr[0] = (arr3[0] + arr3[2])%m;
            arr[1] = arr3[0];
            arr[2] = (arr3[2] + arr3[3])%m;
            arr[3] = arr3[2];
            delete[] arr3;
        }

        /*if( arr[0] >= m )
            arr[0] = arr[0] % m;
        if( arr[1] >= m )
            arr[1] = arr[0] % m;
        if( arr[2] >= m )
            arr[2] = arr[0] % m;
        if( arr[3] >= m )
            arr[3] = arr[0] % m;*/

    }

}


int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc -- )
    {
        int k;
        scanf("%d", &k );

        int m;
        scanf("%d", &m );

        int n = k+2;

        long long int A[] = { 1, 1, 1, 0 };
        findnthpower( A, n, m );

        int he = 3 % m;
        int ans = ( ( A[0] + A[1] ) % m - he ) %m;
        if( ans>= 0)
            printf("%d\n", ans );
        else
            printf("%d\n", -ans );

    }
}
