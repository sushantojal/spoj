#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int count = 1;

    while( 1 )
    {

    int n;
    scanf("%d", &n );

    if( n == 0 )
        break;

    int arr[n][3];

    for( int i = 0; i < n; i ++ )
        for( int j = 0; j < 3; j ++ )
            scanf("%d", &arr[i][j] );

    int dp[n][3];
    for( int i = 0; i < n; i ++ )
        for( int j = 0; j < 3; j ++ )
            dp[i][j] = 0;


    for( int i = 0; i < n ; i ++ )
    {
        for( int j = 0; j < 3; j ++ )
        {
            int temp[5];
            temp[1] = temp[2] = temp[3] = temp[4] = -1000000000;

            if( j-1 >= 0 )
            {
                if( i == 0 && j-1 == 0 ){}else
                temp[1] = dp[i][j-1];
                //cout<<"here"<<endl;
            }


            if( i - 1 >= 0 && j - 1 >= 0 )
            {
                if( i-1 == 0 && j-1 == 0 ){}else
                temp[2] = dp[i-1][j-1];
                //t2 = 1;
            }


            if( (i - 1) >= 0 )
            {
                if( i-1 == 0 && j == 0 ){}else
                temp[3] = dp[i-1][j];
                //t3 = 1;
            }


            if( i - 1 >= 0 && j + 1 < 3 )
            {
                if( i-1 == 0 && j+1 == 0 ){}else
                temp[4] = dp[i-1][j+1];
                //t4 = 1;
            }

           /* if( i == 1 && j == 1 )
                cout<<temp[1]<<endl<<temp[2]<<endl<<temp[3]<<endl<<temp[4]<<endl;*/


            int min = 1000000000;
            for( int k = 1; k <= 4; k ++ )
            {
                if( min > temp[k] && temp[k] != -1000000000)
                    min = temp[k];
            }

            if( min != 1000000000 )
                dp[i][j] = arr[i][j] + min;
            else
                dp[i][j] = arr[i][j];



        }
    }

    /*for( int i = 0; i < n; i ++ )
    {
        for( int j = 0; j < 3; j ++ )
            cout<<dp[i][j] << " ";
        cout<<endl;
    }*/


    printf("%d. %d\n", count, dp[n-1][1] );
    count++;
    }
}


