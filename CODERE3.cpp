#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc -- )
    {
        int n;
        scanf("%d", &n );

        int arr[n];
        for( int i = 0; i < n; i ++ )
            scanf("%d", &arr[i] );

        /*int *prev = new int[n];
        for( int i = 0; i < n; i ++ )
            prev[i] = i;

        int *next = new int[n];
        for( int i = 0; i < n; i ++ )
            next[i] = i;*/

        int count[n];
        for( int i = 0; i < n; i ++ )
            count[i] = 1;


        for( int i = 0; i < n; i ++ )
        {
            for( int j = 0; j < i; j ++ )
            {
                if( arr[i] > arr[j] )
                {
                    if( count[j] + 1 >= count[i] )
                    {
                        count[i] = count[j] + 1;
                       // prev[i] = j;
                    }
                }
            }
        }


        int count2[n];
        for( int i = 0; i < n; i ++ )
            count2[i] = 1;
        for( int i = n-1; i >= 0; i -- )
        {
            for( int j = n-1; j > i; j -- )
            {
                if( arr[i] > arr[j] )
                {
                    if( count2[j] + 1 >= count2[i] )
                    {
                        count2[i] = count2[j] + 1;
                        //next[i] = j;
                    }
                }
            }
        }

        int max = -1; int ind;

        for( int i = 0; i < n; i ++ )
        {
            if( max < count[i] + count2[i] )
            {
                max = count[i] + count2[i] - 1;
                ind = i;
            }
        }
        /*stack< int > s;
        s.push( ind );
        int temp = ind;

        while( prev[temp] != temp )
        {
            s.push( prev[temp] );
            temp = prev[temp];
        }

        while( !s.empty() )
        {
            printf("%d ", arr[s.top()] );
            s.pop();
        }

        temp = ind;
        while( next[temp] != temp )
        {
            printf("%d ", arr[next[temp]] );
            temp = next[temp];
        }*/
        printf("%d\n", max);
    }
}
