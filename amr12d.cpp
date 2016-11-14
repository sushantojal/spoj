#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc -- )
    {
        string s1;
        cin>>s1;

        int len = s1.length();
        int itr = len / 2;
        bool chk = 0;

        for( int i = 0; i < itr; i ++ )
        {
            if( s1[i] == s1[len-1-i] )
                continue;
            else
                chk = 1;
        }

        if( chk == 1 )
            printf("%s\n", "NO" );
        else
            printf("%s\n", "YES" );
    }
}
