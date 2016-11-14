#include <iostream>
#include <stdio.h>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int, int> ii;
typedef pair< ii, int > iii;

class compare
{
    public:
    bool operator()( const iii &l, const iii &r )
    {
        return l.second > r.second;
    }

};

int main()
{
    while( 1 )
    {
        int x1, y1, x2, y2;
        if( scanf("%d %d %d %d", &x1, &y1, &x2, &y2 ) == EOF )
            break;

        if( x1 == x2 && y1 == y2 )
        {
            printf("0\n");
            continue;
        }

        int arr[8][8];
        for( int i = 0; i < 8; i ++ )
            for( int j = 0; j < 8; j++ )
                arr[i][j] = i*j;

        bool visited[8][8];
        for( int i = 0; i < 8; i ++ )
            for( int j = 0; j < 8; j ++ )
                visited[i][j] = 0;

        int d[8][8];
        for( int i = 0; i < 8; i ++ )
            for( int j = 0; j < 8; j ++ )
                d[i][j] = 100000000;

        d[x1][y1] = 0;

        iii s;
        s.first.first = x1; s.first.second = y1; s.second = 0;

        priority_queue< iii, vector<iii>, compare > q;

        q.push( s );
        int xadd[]= { -1, 1, 2, 2, 1, -1, -2, -2 };
        int yadd[] = { -2, -2, 1, -1, 2, 2, 1, -1 };
        int ans = -1;

        while( !q.empty() )
        {
            iii temp = q.top();
            q.pop();


            int i = temp.first.first; int j = temp.first.second; int dist = temp.second;
            //cout<<i<<j<<endl;
            visited[i][j] = 1;
            if( i == x2 && j == y2 )
            {
                ans = dist;
                break;
            }


            for( int k = 0; k < 8; k ++ )
            {
                if( i + xadd[k] >= 0 && i + xadd[k] < 8 && j + yadd[k] >= 0 && j + yadd[k] < 8 && visited[i+xadd[k]][j+yadd[k]] == 0 && ( dist + (( i + xadd[k] )*i) + (( j+ yadd[k] )*j) ) < d[i+xadd[k]][j+yadd[k]] )
                {
                    d[i+xadd[k]][j+yadd[k]] = dist + (( i + xadd[k] )*i) + (( j+ yadd[k] )*j);
                    iii temp2;
                    temp2.first.first = i + xadd[k];
                    temp2.first.second = j + yadd[k];
                    temp2.second = dist + (( i + xadd[k] )*i) + (( j+ yadd[k] )*j);
                    q.push( temp2 );
                }
            }
        }

        printf( "%d\n", ans );
    }
}



