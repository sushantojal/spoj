#include <iostream>
#include <stdio.h>

using namespace std;


int max( int i, int j )
{
    if( i >= j )
        return i;
    else
        return j;
}

int max( int i, int j, int k )
{
    if( i >= j )
    {
        if( i >= k )
            return i;
        else
            return k;
    }
    else if( j >= k )
        return j;
    else
        return k;
}


int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc -- )
    {
        int r;
        scanf("%d", &r );

        int c;
        scanf("%d", &c );

        int **arr = new int *[r];
        for( int i = 0; i < r; i ++ )
            arr[i] = new int[c];

        //int arr[r][c];

        for( int i = 0; i < r; i ++ )
            for( int j = 0; j < c; j ++ )
                scanf("%d", &arr[i][j] );

        /*for( int i = 0; i < r; i ++ )
        {
            for( int j = 0; j < c; j ++ )
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }*/

        for( int i = r - 2 ; i >=0; i -- )
        {
            for( int j = 0; j < c; j ++ )
            {
                if( j == 0 )
                    arr[i][j] = arr[i][j] + max( arr[i+1][j], arr[i+1][j+1] );
                else if( j == c - 1 )
                    arr[i][j] = arr[i][j] + max( arr[i+1][j], arr[i + 1][j - 1]);
                else
                    arr[i][j] = arr[i][j] + max( arr[i+1][j-1], arr[i+1][j], arr[i+1][j+1] );
            }
        }

        int max = -100;
        for( int i = 0; i < c; i ++ )
        {
            if( arr[0][i] > max )
                max = arr[0][i];
        }

        /* for( int i = 0; i < r; i ++ )
        {
            for( int j = 0; j < c; j ++ )
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }*/

        printf("%d\n", max );
    }
}

