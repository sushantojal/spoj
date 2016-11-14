#inlcude <iostream>
#include <stdio.h>

using namespace std;

long long int pow( long long int n, k )
{
    if( k == 1 )
        return n;
    else
    {
        pow( n, k/2 );
        long long int ans = n*n;
        if( n%2 == 1 )
            ans = ans*n;
    }
}

int main()
{
    int a = 5;
    cout<<pow(5, 3 )<<endl;
}
