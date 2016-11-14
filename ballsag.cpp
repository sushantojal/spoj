#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    while( 1 )
    {
        int n;
        scanf("%d", &n );

        if( n == 0 )
            break;

        int **arr = new int*[n];
        for( int i = 0; i < n; i ++ )
            arr[i] = new int[i+1];

        for( int i = 0; i < n; i ++ )
            for( int j = 0; j <= i; j ++ )
                scanf("%d", &arr[i][j] );


        int **val = new int*[n];
        for( int i = 0; i < n; i ++ )
            val[i] = new int[i+1];

        int **ld = new int*[n];
        for( int i = 0; i < n; i ++ )
            ld[i] = new int[i+1];

        int **rd = new int*[n];
        for( int i = 0; i < n; i ++ )
            rd[i] = new int[i+1];

        val[0][0] = arr[0][0];
        ld[0][0] = arr[0][0];
        rd[0][0] = arr[0][0];

        int max = -1000000000;

        for( int i = 0; i < n; i ++ )
        {
            for( int j = 0; j <= i; j ++ )
            {
                if( i == 0 && j == 0 )
                    continue;
                else
                {
                    if( j == 0 )
                        ld[i][j] = arr[i][j];
                    else
                        ld[i][j] = arr[i][j] + ld[i-1][j-1];

                    if( j == i )
                        rd[i][j] = arr[i][j];
                    else
                        rd[i][j] = arr[i][j] + rd[i-1][j];
                }
            }
        }

        for( int i = 0; i < n; i ++ )
        {
            for( int j = 0; j <=i; j++ )
            {
                if( i == 0 && j == 0 )
                {
                    if( val[i][j] > max )
                    max = val[i][j];
                    continue;
                }

                else
                {
                    if( j == 0 )
                        val[i][j] = rd[i][j];
                    else if( j == i )
                        val[i][j] = ld[i][j];
                    else
                        val[i][j] = val[i][j-1] - ld[i][j-1] + rd[i][j];
                }

                if( val[i][j] > max )
                    max = val[i][j];
            }
        }

        printf("%d\n", max );


        for( int i = 0; i < n; i ++ )
        {
            delete[] arr[i];
            delete[] val[i];
            delete[] rd[i];
            delete[] ld[i];
        }
        delete[] arr;
        delete[] val;
        delete[] rd;
        delete[] ld;
    }

}


