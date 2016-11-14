#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int x = static_cast<int>( sqrt( static_cast<float>( n ) ) );

    int ans = 0;

    for( int i = 1; i <= x; i ++ )
        ans = ans + ( n/i - ( i - 1 ) );

    cout<<ans<<endl;
}
