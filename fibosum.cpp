#include <iostream>
#include <stdio.h>

using namespace std;
#define mod 1000000007

void findnthpower( long long int *arr, int n)
{
    if( n == 1 )
        return;
    else
    {
        findnthpower( arr, n/2);
        long long int *arr2 = new long long int[4];
        for ( int i = 0; i < 4; i ++ )
            arr2[i] = arr[i];
        arr[0] = ((arr2[0] * arr2[0])%mod + (arr2[1] * arr2[2])%mod)%mod;
        arr[1] = ((arr2[0] * arr2[1])%mod + (arr2[1] * arr2[3])%mod)%mod;
        arr[2] = ((arr2[2] * arr2[0])%mod + (arr2[3] * arr2[2])%mod)%mod;
        arr[3] = ((arr2[2] * arr2[1])%mod + (arr2[3] * arr2[3])%mod)%mod;
        delete[] arr2;


        if( n%2 == 1)
        {
            long long int *arr3 = new long long int[4];
            for( int i = 0; i < 4; i ++ )
                arr3[i] = arr[i];
            arr[0] = (arr3[0] + arr3[2])%mod;
            arr[1] = arr3[0];
            arr[2] = (arr3[2] + arr3[3])%mod;
            arr[3] = arr3[2];
            delete[] arr3;
        }

    }

}


int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc -- )
    {
        int n;
        scanf("%d", &n );

        int m;
        scanf("%d", &m );

        long long int rs;
        long long int ls;
        if( n==0 )
            rs = 1;
        else if( n == 1 )
            rs = 1;
        else
        {
            long long int arr[] = { 1, 1, 1, 0 };

            findnthpower( arr, n - 1 );
            rs = (arr[0] + arr[1])%mod;
            //cout<<rs<<endl;
        }

        if( m == 0 )
            ls = 1;
        else if( m == 1 )
            ls = 2;
        else
        {
            long long int arr2[] = { 1, 1, 1, 0 };
            findnthpower( arr2, m   );
            ls = (arr2[0] + arr2[1])%mod;
            //cout<<ls<<endl;
        }

        long long int ans = (ls - rs)%mod;
        if( ans < 0 )
            ans = mod + ans;
        printf("%lld\n", ans );



    }
}
