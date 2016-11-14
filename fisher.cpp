#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;
void getans( int **dp, int **marr, int **tarr, int i, int t, int n);


int main()
{
    while( 1 )
    {

    int n, t;
    scanf("%d %d", &n, &t );

    if( n == 0 && t == 0 )
        break;

    int **tarr = new int*[n];
    for( int i = 0; i < n; i ++ )
        tarr[i] = new int[n];

    for( int i = 0; i < n; i ++ )
        for( int j = 0; j < n; j ++ )
            scanf("%d", &tarr[i][j] );

    int **marr = new int*[n];
    for( int i = 0; i < n; i ++ )
        marr[i] = new int[n];

    for( int i = 0; i < n; i ++ )
        for( int j = 0; j < n; j ++ )
            scanf("%d", &marr[i][j] );


    int **dp = new int*[n];
    for( int i = 0; i < n; i ++ )
        dp[i] = new int[t+1];


    for( int i = 0; i < n; i ++ )
        for( int j = 0; j <= t; j ++ )
            dp[i][j] = 100000000;

    for( int i = 0; i <= t; i ++)
        dp[0][i] = 0;

    getans( dp, marr, tarr, n - 1, t, n );
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j <= t; j ++ )
            cout<<setw(11)<<dp[i][j];
        cout<<endl;
    }

    printf("%d\n", dp[n-1][t] );
    }
}

void getans( int **dp, int **marr, int **tarr, int i, int t, int n )
{
    if( i == 1 || t == 0  )
        return;
    int min = 100000000;
    for( int k = 0; k < n; k ++ )
    {
        if( k != i && k!= n - 1 )
        {
            if( (t - tarr[k][i]) >= 0 )
            {
                if( dp[k][t - tarr[k][i]] < 100000000 )
                {
                    int temp = dp[k][t - tarr[k][i]] + marr[k][i];
                    if( min > temp )
                        min = temp;
                }
                else
                {
                    getans( dp, marr, tarr, k, t - tarr[k][i], n );
                    int temp = dp[k][t - tarr[k][i]] + marr[k][i];
                    if( min > temp )
                        min = temp;
                }
            }
        }
    }
    if( dp[i][t-1] < 100000000 )
    {
        if( min > dp[i][t-1] )
            min = dp[i][t-1];
    }
    else
    {
        getans( dp, marr, tarr, i, t-1, n );
        if( min > dp[i][t-1] )
            min = dp[i][t-1];
    }
    dp[i][t] = min;
}
