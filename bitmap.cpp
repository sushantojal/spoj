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

        int **arr = new int*[n];
        for( int i = 0; i < n; i ++ )
            arr[i] = new int[m];

        for( int i = 0; i < n; i ++ )
        {
            char temp[185];
            scanf("%s", temp );

            for( int j = 0; j < m; j ++ )
            {
                if( temp[j] == '0' )
                    arr[i][j] = 0;
                else
                    arr[i][j] = 1;
            }
            getchar();
        }

        bool ** visited = new bool*[n];
        for( int i = 0; i < n; i ++ )
            visited[i] = new bool[m];
        for( int i = 0; i < n; i ++ )
            for( int j = 0; j < m; j ++ )
                visited[i][j] = 0;

        int **ans = new int*[n];
        for( int i = 0; i < n; i ++ )
            ans[i] = new int[m];
        for( int i = 0; i < n; i ++ )
            for( int j = 0; j < m; j ++ )
                ans[i][j] = 100000000;

        for( int i = 0; i < n; i ++ )
        {
            for( int j = 0; j < m; j ++ )
            {
                if ( arr[i][j] == 0 )
                    continue;

                queue< node > q;
                node temp;
                temp.x = i;
                temp.y = j;
                temp.d = 0;
                ans[i][j] = 0;

                q.push( temp );

                while( !q.empty() )
                {
                    node temp2 = q.front();
                    q.pop();
                    int row = temp2.x;
                    int column = temp2.y;
                    int dist = temp2.d;
                    visited[row][column] = 1;
                    if( ans[row][column] > dist )
                        ans[row][column] = dist;

                    node temp3;

                    if( row + 1 < n && visited[row+1][column] == 0  )
                    {
                        temp3.x = row+1;
                        temp3.y = column;
                        temp3.d = dist + 1;
                        if( ans[row+1][column] > dist + 1 )
                            q.push(temp3);
                    }
                    if( column -1 >= 0 && visited[row][column-1] == 0  )
                    {
                        temp3.x = row;
                        temp3.y = column-1;
                        temp3.d = dist + 1;
                        if( ans[row][column-1] > dist + 1 )
                        q.push(temp3);
                    }
                    if( row -1 >= 0 && visited[row-1][column] == 0  )
                    {
                        temp3.x = row-1;
                        temp3.y = column;
                        temp3.d = dist + 1;
                        if( ans[row-1][column] > dist + 1 )
                        q.push(temp3);
                    }
                    if( column + 1 < m && visited[row][column+1] == 0  )
                    {
                        temp3.x = row;
                        temp3.y = column+1;
                        temp3.d = dist + 1;
                        if( ans[row][column+1] > dist + 1 )
                        q.push(temp3);
                    }
                }
                /*for( int i = 0; i < n; i ++ )
                {
                    for( int j = 0; j < m; j ++ )
                        printf("%d ", ans[i][j] );
                    printf("\n" );
                }cout<<endl;*/

                for( int i = 0; i < n; i ++ )
                    for( int j = 0; j < m; j ++ )
                        visited[i][j] = 0;
            }
        }
        for( int i = 0; i < n; i ++ )
        {
            for( int j = 0; j < m; j ++ )
                printf("%d ", ans[i][j] );
            printf("\n" );
        }
    }
}










