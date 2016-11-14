#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc );
    while( tc -- )
    {
        long long int n;
        scanf("%lld", &n );

        long long int sum = 0;

        long long int *arr = new long long int[n];
        for( int i = 0; i < n; i ++ )
        {
            scanf("%lld", &arr[i] );
            sum = sum + arr[i];
        }

        long long int *sl = new long long int[n];
        long long int *sr = new long long int[n];
        sl[0] = 0;

        long long int min1 = 1000000005; long long int min2 = 1000000005;


        for( int i = 1; i < n ; i ++ )
            sl[i] =  arr[i-1] + sl[i-1];

        sr[0] = 0;
        for( int i = 1; i < n; i ++ )
            sr[i] = sr[i-1] + arr[n-i];


        int arrtemp1[n];
        int arrtemp2[n];
        for( int i = 0; i < n; i ++ )
        {
            arrtemp1[i] = sum - arr[i] + sl[i];
            if( min1 > ( sum - arr[i] + sl[i] ) )
                min1 = sum - arr[i] + sl[i];
        }

        for( int i = 0; i < n; i ++ )
        {
            arrtemp2[i] = sum - arr[n-i-1] + sr[i];
            if( min2 > ( sum - arr[n-i-1] + sr[i] ) )
                min2 = sum - arr[n-i-1] + sr[i];
        }

        /*for( int i = 0; i < n; i ++ )
            cout<<sr[i]<<" ";
        cout<<endl;

        for( int i = 0 ; i < n; i ++ )
            cout<<sl[i]<<" ";
        cout<<endl;

        for( int i = 0 ; i < n; i ++ )
            cout<<arrtemp1[i]<<" ";
        cout<<endl;

        for( int i = 0 ; i < n; i ++ )
            cout<<arrtemp2[i]<<" ";
        cout<<endl;*/

        if( min1 <= min2 )
            printf("%lld\n", min1 );
        else
            printf("%lld\n", min2 );

        delete[] sr;
        delete[] sl;
        delete[] arr;
    }
}






