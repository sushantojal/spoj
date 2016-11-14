#include <iostream>
#include <stdio.h>

using namespace std;

long long int pow( long long int n, long long int k )
{
    if( k == 0 )
        return 1;
    else
    {
        if( k% 2 == 0 )
            return ( pow(n, k/2) * pow( n, k/2) );
        else
            return ( pow(n, k/2) * pow( n, k/2) * n );

    }
}

int main()
{
   long long int tc;
   scanf("%lld", &tc );

   while( tc -- )
   {
       long long int a, d, r;
       scanf("%lld %lld %lld", &a, &d, &r );

       long long int n, m;
       scanf("%lld %lld", &n, &m );

       long long int ans;
       if( r == 1 )
       {
           long long int var = n /2;
           ans = ( a + (var*d) ) % m;
       }

       else
       {

           long long int k = (n - 1)/2;
           //cout<<k<<endl;
           long long int temp1 = pow( r, k );


           long long int term1 = (a*temp1) ;
           term1 = term1 % m;

           long long int term2;
           if( n % 2 == 1 )
           {
               term2 = ( (temp1 - 1 ) / (r - 1) ) * d * r;
               term2 = term2 % m;

           }

           else
           {
               term2 = ( (r*temp1 - 1 ) / (r - 1) ) * d;
               term2 = term2 % m;
           }

            //cout<<term1<<" "<<term2<<endl;
           ans = (term1 + term2) % m;
           //ans = ans % m;
           if( ans < 0 )
            ans = ans + m;
       }

       printf("%lld\n", ans );
   }
}
