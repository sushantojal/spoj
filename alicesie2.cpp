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

        int ans = n/2;

        if( n%2 == 0)
        printf("%d\n", ans );
        else
        printf("%d\n", (ans+1) );
    }
}

