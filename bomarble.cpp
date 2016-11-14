#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    while( 1 )
    {
         int n;
        scanf("%d", &n );

        if( n == 0 )
            break;

        int temp1 = n - 1;
        int temp2 = n - 2;

        long long int ans = 5 + (7*temp1) + ((3*temp1*temp2)/2);

        printf("%lld\n", ans );
    }
}
