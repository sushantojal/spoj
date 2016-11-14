#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n );

    int *arr = new int[n+1];
    //bool *chk = new bool[1000000000];
    int *chk = new int[n+1];
    for( int i = 0; i <= n; i ++ )
        chk[i] = 0;

    chk[0] = 1;

    //for( int i = 0; i < 1000000000; i ++ )
      //  chk[i] = 0;

    for( int i = 1; i < n+1; i ++ )
        scanf("%d", &arr[i]);

    int count = 0;

    for( int i = 2; i < n+1; i ++ )
    {
        if( chk[i] == 0 )
        {
            int val = arr[i];
            int d = arr[i] - 1;
            //arr[i] = -1;
            count++;
            for( int j = i; j <= n; j++ )
            {
                if( val == arr[j] )
                {
                    chk[j] = 1;
                    val = val + d;
                }
            }
        }

    }
    printf("%d\n", count );
}


