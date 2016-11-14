#include <iostream>
#include <stdio.h>

using namespace std;

bool f( int x )
{
    while( x > 0 )
    {
        int dig = x%10;
        if( dig == 2 || dig == 4 || dig == 6 || dig == 8 || dig == 0 )
            return true;
        x = x/10;
    }
    return false;
}



int main()
{
    int tc;
    scanf("%d", &tc );
    while( tc-- )
    {
        int l; int r;
        scanf("%d %d", &l , &r );

        int count = 0;
        for( int i = l ; i<=r; i ++ )
        {
            if(f(i) == true )
                count++;
        }

        printf("%d\n", count );
    }
}
