#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int min( int a, int b )
{
    if( a <=b )
        return a;
    else
        return b;
}


int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc -- )
    {
        char * str1 = new char[2001];
        char * str2 = new char [2001];

        scanf("%s", str1 );
        scanf("%s", str2 );

        int len1 = strlen(str1 );
        int len2 = strlen( str2 );


        //int arr[len1+1][len2+1];

        int ** arr = new int * [len1 + 1];
        for( int i = 0; i <= len1; i ++ )
            arr[i] = new int[len2 + 1];

        for( int i = 0; i <= len1; i ++ )
        {
            for( int j = 0; j <= len2; j ++ )
            {
                if( i == 0 )
                    arr[i][j] = j;
                else if( j == 0 )
                    arr[i][j] = i;
                else
                {
                    if( str1[i-1] == str2[j-1] )
                    {
                        arr[i][j] = arr[i-1][j-1];
                    }
                    else
                    {
                        arr[i][j] = min( (min( arr[i][ j-1] + 1 , arr[i-1][j] + 1 )), arr[i-1][j-1] + 1 );
                    }
                }
            }


        }

        printf("%d\n", arr[len1][len2] );

        for( int i = 0 ; i < len1; i ++ )
            delete[] arr[i];
        delete[] arr;
    }
}
