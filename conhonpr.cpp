#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc-- )
    {
        int n; int m;
        scanf("%d %d", &n, &m );

        int arr[n][m];

        for( int i = 0; i < n; i ++ )
            for( int j = 0; j < m; j ++ )
                scanf("%d", &arr[i][j]);

        long long int count = 0;
        bool *teams = new bool[101];
        for( int i = 0; i < 101; i ++ )
            teams[i] = 0;

        for( int i = 0; i<n; i ++ )
        {
            for( int j = 0; j < m; j ++ )
            {
                if( arr[i][j] != -1 && teams[arr[i][j]] == 0 )
                {

                    int newi1 = i + 1;
                    int newi2 = i - 1;
                    int newj1 = j + 1;
                    int newj2 = j - 1;

                    if( ( newi2 >= 0 && arr[newi2][j] == arr[i][j] ) || ( newi2 >=0 && newj1 <= m-1 && arr[newi2][newj1] == arr[i][j] ) || ( newj1 <= m-1 && arr[i][j] == arr[i][newj1] ) || ( newi1 <= n-1 && newj1 <= m-1 && arr[i][j] == arr[newi1][newj1] ) || ( newi1 <= n-1 && arr[i][j] == arr[newi1][j] ) || ( newi1 <= n-1 && newj2 >= 0 && arr[i][j] == arr[newi1][newj2] ) ||( newj2 >= 0 && arr[i][j] == arr[i][newj2] ) || ( newi2 >= 0 && newj2 >= 0 && arr[i][j] == arr[newi2][newj2] ) )
                        teams[arr[i][j]] = 1;

                    /*if( newi2 >=0 && newj1 <= m-1 && arr[newi2][newj1] == arr[i][j] )
                        teams[arr[i][j]] = 1;

                    if( newj1 <= m-1 && arr[i][j] == arr[i][newj1] )
                        teams[arr[i][j]] = 1;

                    if( newi1 <= n-1 && newj1 <= m-1 && arr[i][j] == arr[newi1][newj1] )
                        teams[arr[i][j]] = 1;

                    if( newi1 <= n-1 && arr[i][j] == arr[newi1][j] )
                        teams[arr[i][j]] = 1;

                    if( newi1 <= n-1 && newj2 >= 0 && arr[i][j] == arr[newi1][newj2] )
                        teams[arr[i][j]] = 1;

                    if( newj2 >= 0 && arr[i][j] == arr[i][newj2] )
                        teams[arr[i][j]] = 1;

                    if( newi2 >= 0 && newj2 >= 0 && arr[i][j] == arr[newi2][newj2] )
                        teams[arr[i][j]] = 1;*/
                }

            }
        }

        for( int i = 1; i <= 100; i ++ )
            if( teams[i] == 1 )
                count++;

        printf("%lld\n", count );
    }
}

