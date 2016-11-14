#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
using namespace std;


long long int maxval( long long int n, map <long long int, long long int> maap[]  )
{
    if( n==0 )
    {
        //maap[n]= 0;
        return 0;
    }


    if( maap[n] == 0 )
    {
        long long int sum = maxval(n/2, maap ) + maxval(n/3, maap )+ maxval(n/3, maap );
        if( sum < n )
        {
            maap[n] = sum;
            return sum;
        }
        else
        {
            maap[n] = n;
            return n;
        }
    }
    else
        return maap[n];
}

int main()
{
    int scanfval = 1; long long int n;
    map <long long int, long long int > maap;
    while( 1 )
    {
        scanfval = scanf("%lld",&n );
        if( scanfval == EOF )
            break;

        cout<<maxval(n, maap)<<endl;
    }
}
