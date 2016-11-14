#include <stdio.h>

int main()
{
    int len;
    while( 1 )
    {
        scanf("%d", &len);
        if( len == 0)
            break;

        int arr[len];

         for( int i = 0; i < len; i ++ )
            scanf("%d", &arr[i]);

        if( len == 1)
        {
            printf("%d\n", 0 );
            continue;
        }

        int median;

        if( len%2 == 0)
            median= ((len) / 2 ) - 1 ;
        else
            median= ((len+1) / 2 ) - 1;

        int count1 = 0;
        int count2 = 0;

        int j = median;
        int k = median;

        for( int i = median+1; i < len; i ++ )
        {
            count1 = count1 + ( arr[i] - arr[j] - 1 );
            arr[i] = arr[j] + 1;
            j++;
        }

        for( int i = median - 1; i >= 0; i -- )
        {
            count2 = count2 + ( arr[k] - arr[i] - 1 );
            arr[i] = arr[k] - 1;
            k--;
        }

        printf( "%d\n", ( count1 + count2 ) );
    }
}
