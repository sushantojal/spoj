#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
    int x;
    int y;
    int d;
};


int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc -- )
    {
        int n, m;
        scanf("%d %d", &n, &m );

        /*int **arr = new int*[n];
        for( int i = 0; i < n; i ++ )
            arr[i] = new int[m];

        int **ans = new int*[n];
        for( int i = 0; i < n; i ++ )
            ans[i] = new int[m];*/

        int ans[n][m];

        for( int i = 0; i < n; i ++ )
            for( int j = 0; j < m; j ++ )
                ans[i][j] = -100000000;

        queue< node > q;

        for( int i = 0; i < n; i ++ )
        {
            char temp[185];
            scanf("%s", temp );

            for( int j = 0; j < m; j ++ )
            {
                if( temp[j] == '1' )
                {
                    //arr[i][j] = 1;
                    node temp;
                    temp.x = i;
                    temp.y = j;
                    temp.d = 0;
                    ans[i][j] = 0;
                    q.push( temp );
                }
            }
            getchar();
        }


        while( !q.empty() )
        {
            node temp2 = q.front();
            q.pop();
            int row = temp2.x;
            int column = temp2.y;
            int d = temp2.d;

            if( row + 1 < n && ans[row+1][column] == -100000000 )
            {
                node temp3;
                temp3.x = row +1;
                temp3.y = column;
                temp3.d = d + 1;
                ans[row+1][column] = d+1;
                q.push( temp3 );
            }
            if( column + 1 < m && ans[row][column+1] == -100000000 )
            {
                node temp3;
                temp3.x = row ;
                temp3.y = column+1;
                temp3.d = d + 1;
                ans[row][column+1] = d + 1;
                q.push( temp3 );
            }
            if( row - 1 >= 0 && ans[row-1][column] == -100000000 )
            {
                node temp3;
                temp3.x = row -1;
                temp3.y = column;
                temp3.d = d + 1;
                ans[row-1][column] = d + 1;
                q.push( temp3 );
            }
            if( column - 1 >= 0 && ans[row][column-1] == -100000000 )
            {
                node temp3;
                temp3.x = row ;
                temp3.y = column - 1;
                temp3.d = d + 1;
                ans[row][column-1] = d + 1;
                q.push( temp3 );
            }
        }

        for( int i = 0; i < n; i ++ )
        {
            for( int j = 0; j < m; j ++ )
                printf("%d ", ans[i][j] );
            printf("\n");
        }
    }
}



