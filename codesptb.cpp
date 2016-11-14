#include <stdio.h>

int main()
{
    int tc;
    scanf( "%d", &tc );
    while ( tc -- )
    {
        int len;
        scanf( "%d", &len );

        int * arr = new int[len];
        for( int i = 0; i < len; i ++ )
            scanf( "%d", &arr[i] );

        int count = 0;

        for( int j = 1; j < len ; j ++ )
        {
            int i = j;
            while( i > 0 )
            {

                if( (arr[i] < arr[i-1]) )
                {
                    int temp = arr[i];
                    arr[i] = arr[i-1];
                    arr[i-1] = temp;
                    count ++ ;
                }
                else
                    break;

                i -- ;
            }
        }

        printf( "%d\n", count );
    }

}

