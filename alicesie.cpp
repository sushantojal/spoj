#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc -- )
    {
        int n;
        scanf( "%d", &n );

        if( n == 2 )
        {
            printf( "%d\n", 1 );
            continue;
        }
        else if( n == 3 )
        {
            printf("%d\n", 2 );
            continue;
        }


        int * arr = new int[n-1];
        for( int i = 0; i < n-1; i ++ )
            arr[i] = 0;

        int p;
        int count = n - 2 ;

        while( count >= 0 )
        {
            if( arr[count] == 0 )
                p = count + 2;
            else
            {
                count--;
                continue;
            }

            for( int i = 2; i<=(p/2); i ++ )
            {

                int chk = p%i ;
                if( chk == 0 )
                    arr[i-2] = 1;
            }
            count -- ;
        }


        int count2 = 0;

        for( int i = 0; i < n-1; i ++ )
        {
            if( arr[i] == 0 )
                count2++;
        }
        printf("%d\n", count2 );
    }
}






