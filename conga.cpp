#include <stdio.h>

int main()
{
    int len;
    while( 1 )
    {
        scanf("%lld", &len);
        if( len == 0)
            break;

        int arr[len];
        int max = 0;

        for( int i = 0; i < len; i ++ )
        {
            scanf("%lld", &arr[i]);
            if( max < arr[i])
                max = arr[i];
        }

        int arr2[max];

        int median;

        if( len%2 == 0)
            median= (len) / 2;
        else
            median= (len+1) / 2;

        int mean = arr[median-1];
        //printf("\n%lld\n", mean);

        for( int i = 0; i < max; i ++)
            arr2[i] = 0;

        for( int i = 0; i < len; i ++)
            arr2[arr[i]-1] = 1;

        //for( int i = 0; i < max; i ++)
          //  printf("%lld\t", arr2[i]);

        int count1 = 0;
        int count2 = 0;


        for( int i = mean; i < max; i++)
        {
            int lastemp;
            if( arr2[i] == 0)
            {
                lastemp = i;
                int j = i + 1;
                while( arr2[j]==0 && j<max)
                    j++;
                if( j == max )
                    break;
                arr2[lastemp] = 1;
                arr2[j] = 0;
                count1= count1 + (j-lastemp) ;
            }
        }

        //printf( "%lld\n", count1);

        for( int i = (mean - 1); i >= 0; i -- )
        {
            int lastemp;
            if( arr2[i] == 0)
            {
                lastemp = i;
                int j = i - 1;
                while( arr2[j]==0 && j>0)
                    j--;
                if( j == 0 )
                    break;
                arr2[lastemp] = 1;
                arr2[j] = 0;
                count2= count2 + (lastemp - j) ;
            }
        }
        //printf( "%lld\n", count2);


        printf("%lld\n", ( count1 + count2 ) );
    }
}













