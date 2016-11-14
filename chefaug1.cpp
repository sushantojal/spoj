#include "stdio.h"

main()
{
    int tc;
    scanf("%d", &tc);

    int arrout[tc];
    int j = 0;

    int len;
    char * arr1;
    int counter = 0;

    while( tc-- )
    {
        scanf("%d", &len);

        int arr2[len];
        int i = 0;
        for(i = 0; i < len; i ++ )
            arr2[i] = 0;

        scanf("%s", &arr1);

        if( arr1[0] == '1' )
        {
            arr2[0] = 1;
            if( len==1)
            {
                counter++;
            }
            else
            {
                arr2[1] = 1;
                counter+=2;
            }
        }

        int k;
        for( k = 1; k < len-1; k ++ )
        {
            if ( arr1[k] == '1' )
            {
                if( arr2[k]==0)
                {
                    arr2[k] = 1;
                    counter++;
                }
                if( arr2[k-1] == 0 )
                {
                    arr2[k-1] = 1;
                    counter ++;
                }

                if( arr2[k + 1] == 0 )
                {
                    arr2[k+1] = 1;
                    counter ++;
                }
            }
        }

        if( arr1[len-1] == '1' && arr2[len-1] == 0 )
        {
            arr2[len-1] = 1;
            counter++;
            if( arr2[len-2] == 0 )
            {
                arr2[len-2] = 1;
                counter ++;
            }
        }
        printf("%d\n",(len - counter));

        counter=0;
        int l;
        for( l = 0; l < len; l ++ )
            arr2[l] = 0;
    }
}
