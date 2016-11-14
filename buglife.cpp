#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>

using namespace std;
typedef pair< int, int > ii;
typedef pair< ii, int > iii;
typedef vector< ii > vii;
typedef vector< vii > vvii;

int main()
{
	int tc;
	scanf("%d", &tc );
	int count = 1;

	while( tc -- )
	{
	    int n; int r;
	    scanf("%d %d", &n, &r );

	    vector< vii >  g;
	    for( int i = 0; i < n; i ++ )
            g.push_back( vii() );
	    for( int i = 0; i < r; i ++ )
	    {
	        int v1, v2;
	        scanf("%d %d", &v1, &v2 );

	        ii temp;
	        temp.first = v2-1; temp.second = 0;

	        g[v1-1].push_back( temp );
	        temp.first = v1-1; temp.second = 0;
	        g[v2-1].push_back( temp );
	        //cout<<"check"<<endl;
	    }

	    bool check = 0;
	    bool *visited = new bool[n];
	    for( int i = 0; i <n; i ++ )
            visited[i] = 0;

        int *color = new int[n];
        for( int i = 0; i < n; i ++ )
            color[i] = 0;


        queue< ii > q;
        for( int i = 0; i < n; i ++ )
        {
            if( visited[i] == 0 )
            {
                ii s;
                s.first = i;
                s.second = 1;
                q.push( s );
                color[i] = 1;
                visited[i] = 1;
            }

            while( !q.empty() )
            {
                ii temp = q.front();
                q.pop();
                for( int i = 0; i < g[temp.first].size(); i ++ )
                {
                    if( visited[g[temp.first][i].first] == 1 )
                    {
                        if( color[g[temp.first][i].first] == color[temp.first] )
                        {
                            check = 1;
                            break;
                        }
                    }
                    else
                    {
                        ii temp2;
                        temp2.first = g[temp.first][i].first;
                        if( color[temp.first] == 1 )
                            color[temp2.first] = 2;
                        else if( color[temp.first] == 2 )
                            color[temp2.first] = 1;

                        visited[temp2.first] = 1;
                        temp2.second = 0;
                        q.push( temp2 );
                    }
                    if( check == 1 )
                        break;
                }
                if( check == 1 )
                    break;
            }
            if( check == 1 )
                break;
        }

        if( check == 1 )
            printf("Scenario #%d:\nSuspicious bugs found!\n", count);
        else
            printf("Scenario #%d:\nNo suspicious bugs found!\n", count);

        count++;
	}
}
