#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;


bool foo ( int i, int j ){ return (j < i) ; }

int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc -- )
    {
        int n; int m; int k;
        scanf("%d %d %d", &n, &m, &k );

        int ar[n];
        for( int i = 0; i < n ; i ++ )
            ar[i] = 0;

        for( int i = 0; i < n; i ++ )
        {
            string temp;
            //char *temp = new char[m];
            //scanf( "%s", temp );
            //cout<<temp<<endl;
            cin>>temp;
            for( int j = 0; j < m; j ++ )
            {
                if( temp[j] == '.' )
                    ar[i] = ar[i] + 1;
                //cout<<j<<endl;
            }
        }



        sort( ar, ar+n, foo );


        int ans = 0;

        // off states > on states for all n

        if( ar[n - 1] >= (m - ar[n - 1]) )
        {

            if( k <= n )
            {
                for( int i = 0; i < k; i ++ )
                   ans = ans + ar[i];
                for( int i = k ; i < n; i ++ )
                    ans = ans + m - ar[i];
            }
            else
            {
                for( int i = 0; i < n-1; i ++ )
                {
                    ans = ans + ar[i];
                }
                if( (k - (n-1)) % 2 == 0 )
                    ans = ans + m - ar[n - 1];
                else
                    ans = ans + ar[n - 1];
            }
        }


        // on states > off states for all n

        else if( ar[0] <= (m - ar[0]) )
        {
            for( int i = 0; i < n; i ++ )
            {
                if( k % 2 == 0 )
                {
                    ans = ans + m - ar[i];
                }
                else
                {
                    if( i == 0 )
                        ans = ans + ar[i];
                    else
                        ans = ans + m - ar[i];
                }
            }
        }

        // on + off states
        else
        {
            int count = 0;

            for( int i = 0; i < n; i ++ )
            {
                if( ar[i] >= (m - ar[i]) )
                    count ++ ;
                else
                    break;
            }


            //K <= COUNT

            if( k <= count )
            {
                for( int i = 0; i < k; i ++ )
                    ans = ans + ar[i];
                for( int i = k; i < n; i ++ )
                    ans = ans + m - ar[i];
            }

            //K > COUNT
            else if( k > count)
            {
                //cout<<count<<endl;
                for( int i = 0; i < count - 1; i ++ )
                {
                    ans = ans + ar[i];
                    //cout<<ans<<endl;
                }


                int remaintog = k - ( (count - 1) + (n - (count + 1) ) );
                if( remaintog % 2 == 1)
                {
                    ans = ans + ar[count - 1];
                    for( int i = count; i < n; i ++ )
                        ans = ans + m - ar[i];
                }
                else
                {
                    int onoffc = ar[count - 1] - ( m - ar[count - 1] );
                    int onoffcp1 =  - ar[count] + ( m - ar[count] );

                    if( onoffc > onoffcp1 )
                    {
                        ans = ans + ar[count - 1];
                        ans = ans + ar[count];
                        for( int i = count + 1; i < n; i ++ )
                            ans = ans + m - ar[i];
                    }
                    else if( onoffc <= onoffcp1 )
                    {
                        for( int i = count - 1; i < n; i ++ )
                        {
                            ans = ans + m - ar[i];
                        }

                    }
                }

            }

        }
        printf("%d\n", ans );
    }
}
