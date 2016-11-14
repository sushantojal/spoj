#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


int gcd( int x, int y )
{
        if( y == 0 )
            return x;
        else
            return gcd(y, x%y);
}



int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc -- )
    {
        string num;
        cin>>num;

        int len = num.length(); int ind = -100;
        for( int i = len - 1; i >= 0; i -- )
        {
            if( num[i] == '.' )
                ind = i;
        }
        if( ind == -100 )
        {
            printf("%d\n", 1 );
            continue;
        }

        int var = len - ind - 1;

        int den= 1;
        for( int i = 0; i < var; i ++ )
            den = den * 10;

        //cout<<den<<endl;



        //string num2;

        char num2[len - 1];
        int j = 0;
        for( int i = 0; i < len; i ++ )
        {

            if( num[i] != '.' )
            {
                num2[j] = num[i];
                //cout<<num2[j]<<endl;
                j++;
            }
        }
        //cout<<num<<endl;
        //cout<<num2.length()<<endl;
        int nume = atoi(num2);

        int gre = gcd( nume, den );
        //if( gre == 0 )
        //cout<<"sadfdsafasf"<<endl;
        int ans = den/gre;

        printf("%d\n", ans );
    }
}


