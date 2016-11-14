#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int  lasti, ind;
    bool con = 0; bool con2 = 0;
    int *arr = new int[10];
    for( int i = 0; i < 10; i ++ )
    {
        int temp;
        scanf("%d", &temp );
        if( con2 == 0 )
        {
            if( i == 0 )
                arr[i] = temp;
            else
                arr[i] = arr[i-1] + temp;

            lasti = i;

            if( arr[i] >= 100 )
            {
                con = 1;
                con2 = 1;
                continue;
            }
        }
    }

    if( con == 0 )
        printf("%d\n", arr[lasti]);
    else
    {
        if( arr[lasti] == 100 )
            printf("%d\n", arr[lasti]);
        else
        {
            int diffg = arr[lasti] - 100;
            int diffl = 100 - arr[lasti-1];
            if( diffl<diffg )
                printf("%d\n", arr[lasti-1]);
            else
                printf("%d\n", arr[lasti]);
        }
    }
}





