#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc -- )
    {
        long long int n;
        scanf("%lld", &n );

        //long long int m;
        //scanf("%lld", &m );


        int a = 1;
        int b = 1;
        long long int c = 0;
        //long long int sum = 0;
        long long int count = 0;

        while( count < n )
        {
            c = a+b;
            a = b;
            b = c;
            //sum = sum + c;
            count ++ ;
        }

        //cout<<sum<<endl;
        //long long int ans = sum%m;
        printf("%lld\n", c);


    }
}


