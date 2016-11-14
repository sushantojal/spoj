#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    int tc;
    scanf( "%d", &tc );

    while( tc-- )
    {

        int ng, nm = 0;
        scanf("%d %d", &ng, &nm );

        int *arrg = new int[ng];
        int *arrm = new int[nm];

        for( int i = 0; i < ng; i ++ )
        scanf( "%d", &arrg[i] );

        for( int i = 0; i < nm; i ++ )
        scanf( "%d", &arrm[i] );

        sort( arrg, arrg + ng );
        sort( arrm, arrm + nm );

        int i = 0; int j = 0;

        while( (i<ng)&&(j<nm) )
        {
            if( arrg[i] >= arrm[j] )
            {
                arrm[j] = 0;
                j++;
            }

            else if( arrg[i] < arrm[j] )
            {
                arrg[i] = 0;
                i++;
            }
        }

        if( arrg[ng-1] == 0 )
            printf("%s\n", "MechaGodzilla" );
        else if ( arrm[nm-1] == 0 )
            printf("%s\n", "Godzilla" );

    }
}





