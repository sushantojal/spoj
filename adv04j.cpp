#include <stdio.h>

int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc-- )
    {
        int n;
        scanf( "%d", &n );



        int count = 0;

        while( 1 )
        {
            if( n==2 || n == 3 )
            break;

            if( n%2 != 0 )
            n= n+1;

            n = n/2;
            count ++;
        }

        if( n == 2 )
        count = count + 2;
        else if( n == 3 )
        count = count + 3;

        printf("%d\n", count );
    }
}

