#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


int main()
{
    int tc;
    scanf("%d", &tc );

    for( int i = 0; i < tc; i ++ )
    {
        long long int n, m, k ;
        scanf("%lld %lld %lld", &n, &m, &k );

        long long int ans1 = (n*m*k) - 1;
        int term1, term2, term3;

        if( n == 1 )
            term1 = 0;
        else
            term1 = (int)(ceil( (log( double(n) )) / (log(2) ) ));
        //else
          //  term1 = (int)(( (log( double(n) )) / (log(2) ) ) + 0.5)+ 1;

        if( m == 1 )
            term2 = 0;
        else
            term2 = (int)(ceil( (log( double(m) )) / (log(2) ) ));
       // else
         //   term2 = (int)(( (log( double(m) )) / (log(2) ) ) + 0.5) + 1;

        if( k == 1 )
            term3 = 0;
        else
            term3 = (int)(ceil( (log( double(k) )) / (log(2) ) ));
       // else
         //   term3 = (int)(( (log( double(k) )) / (log(2) ) ) + 0.5) + 1;

        //cout<<term1<<" "<<term2<<" "<<term3<<endl;

        int ans2 = term1 + term2 + term3;


        printf("Case #%d: %lld %d\n", i+1, ans1, ans2 );
    }
}
