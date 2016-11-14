#include <iostream>
#include <stdio.h>
#include <utility>
#include <queue>

using namespace std;
typedef pair<int, int> ii;

int main()
{
    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d );

    ii start;
    start.first = s;
    start.second = 0;

    queue<ii> q;
    q.push( start );
    bool *arr = new bool[f+1];
    for( int i = 0; i < f+1; i ++ )
        arr[i] = 0;

    arr[s] = 1;
    bool chk = 0;

    while( !q.empty() )
    {
        ii temp1 = q.front();
        q.pop();

        if( temp1.first == g )
        {
            chk = 1;
            printf("%d\n", temp1.second );
            break;
        }

        else
        {
            ii temp2, temp3;
            if( temp1.first + u <= f && arr[temp1.first+u] == 0 )
            {
                temp2.first = temp1.first + u;
                temp2.second = temp1.second + 1;
                q.push( temp2 );
                arr[temp1.first + u] = 1;
            }

            if( temp1.first - d >= 0 && arr[temp1.first - d] == 0 )
            {
                temp3.first = temp1.first - d;
                temp3.second = temp1.second + 1;
                q.push( temp3 );
                arr[temp1.first - d] = 1;
            }
        }
    }

    if(chk == 0 )
        printf("use the stairs\n");
}
