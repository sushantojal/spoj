#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

bool capson( char a )
{
    if( (int)a >= 97 && (int)a<=122 )
        return 0;
    else
        return 1;
}

int main()
{
    char arr[1002];
    while( scanf("%s",arr)!=EOF )
    {
        int len = strlen(arr);


        int count = 0;
        bool arr1[len];
        for( int i = 0; i < len; i ++ )
            arr1[i] = 0;

        if( capson(arr[0]) )
        {
            count++;
            //arr1[0] = 0;
        }

        for( int i = 1; i < len; i ++ )
        {
            if( capson( arr[i] ) )
                arr1[i] = 1;

            if( arr1[i] == arr1[i-1] )
            {
                arr1[i] = !arr1[i];
                count++;
            }
        }

        int count2 = 0;
        bool arr2[len];
        for( int i = 0; i < len; i ++ )
            arr2[i] = 1;

        if( !capson(arr[0]) )
        {
            count2++;
            //arr2[0] = 1;
        }

        for( int i = 1; i < len; i ++ )
        {
            if( !capson(arr[i]) )
                arr2[i] = 0;

            if( arr2[i] == arr2[i-1] )
            {
                arr2[i] = !arr2[i];
                count2 ++;
            }
        }

        if( count<=count2 )
            printf("%d\n", count );
        else
            printf("%d\n", count2 );
    }
}



