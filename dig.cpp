#include <stdio.h>
#include <iostream>

using namespace std;
#define mod 1000000007

int main()
{
    long long int tc;
    scanf("%lld", &tc );

    while( tc -- )
    {
        long long int n;
        scanf("%lld", &n );

        long long int num1 = n;
        long long int num2 = n - 1;
        long long int num3 = n - 2;
        long long int num4 = n - 3;

        bool check2 = 0; bool check3 = 0; bool check4 = 0;
        if( num1 % 4 == 0 && check4 == 0 )
        {
            num1 = num1/4;
            check4 = 1;
        }
        else if( num2 % 4 == 0 && check4 == 0 )
        {
            num2 = num2/4;
            check4 = 1;
        }
        else if( num3 % 4 == 0 && check4 == 0 )
        {
            num3 = num3/4;
            check4 = 1;
        }
        else if( num4 % 4 == 0 && check4 == 0 )
        {
            num4 = num4/4;
            check4 = 1;
        }

        if( num1 % 3 == 0 && check3 == 0 )
        {
            num1 = num1/3;
            check3 = 1;
        }
        else if( num2 % 3 == 0 && check3 == 0 )
        {
            num2 = num2/3;
            check3 = 1;
        }
        else if( num3 % 3 == 0 && check3 == 0 )
        {
            num3 = num3/3;
            check3 = 1;
        }
        else if( num4 % 3 == 0 && check3 == 0 )
        {
            num4 = num4/3;
            check3 = 1;
        }

        if( num1 % 2 == 0 && check2 == 0 )
        {
            num1 = num1/2;
            check2 = 1;
        }
        else if( num2 % 2 == 0 && check2 == 0 )
        {
            num2 = num2/2;
            check2 = 1;
        }
        else if( num3 % 2 == 0 && check2 == 0 )
        {
            num3 = num3/2;
            check2 = 1;
        }
        else if( num4 % 2 == 0 && check2 == 0 )
        {
            num4 = num4/2;
            check4 = 1;
        }

        long long int ans = num1*num2;
        ans = ans%mod;
        ans = ans * num3;
        ans = ans%mod;
        ans = ans * num4;
        ans = ans%mod;
        printf("%llu\n", ans );



    }
}
