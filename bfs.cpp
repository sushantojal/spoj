#include <iostream>
#include <stdio.h>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int > iii;
typedef queue<iii> qiii;

int main()
{
    int tc;
    cin>>tc;


    while( tc -- )
    {

        int ans;
        qiii chessq;

        char startp[5];
        cin>>startp;

        char endp[5];
        cin>>endp;

        int visited[8][8];
        for( int i = 0; i < 8; i ++ )
            for( int j = 0; j < 8; j ++ )
                visited[i][j] = 0;

        iii start;
        start.first.first = (int)startp[0] - (int)('a');
        start.first.second = (int)startp[1] - (int)('1');
        start.second = 0;

        visited[start.first.first][start.first.second] = 1;

        chessq.push(start);

        iii last;
        last.first.first = (int)endp[0] - (int)('a');
        last.first.second = (int)endp[1] - (int)('1');
        last.second = -10;


        while( !chessq.empty() )
        {
            iii curr;
            curr = chessq.front();
            chessq.pop();

            int col = curr.first.first;
            int row = curr.first.second;
            int level = curr.second;

            //cout<<col<<" "<<row<<endl;

            if( col == last.first.first && row == last.first.second )
            {
                ans = curr.second;
                break;
            }

            if( col+2 < 8 && row + 1 <8 && visited[col + 2][row + 1] == 0 )
            {
                iii temp1;
                temp1.first.first = col + 2;
                temp1.first.second = row + 1;
                temp1.second = level + 1;
                visited[col + 2][row + 1] = 1;
                chessq.push( temp1 );
            }
            if( col+2 < 8 && row -1 >= 0 && visited[col + 2][row - 1] == 0 )
            {
                iii temp1;
                temp1.first.first = col + 2;
                temp1.first.second = row - 1;
                temp1.second = level + 1;
                visited[col + 2][row - 1] = 1;
                chessq.push( temp1 );
            }
            if( col-2 >= 0 && row + 1 <8 && visited[col - 2][row + 1] == 0 )
            {
                iii temp1;
                temp1.first.first = col - 2;
                temp1.first.second = row + 1;
                temp1.second = level + 1;
                visited[col - 2][row + 1] = 1;
                chessq.push( temp1 );
            }
            if( col- 2 >= 0 && row -1 >= 0 && visited[col - 2][row - 1] == 0 )
            {
                iii temp1;
                temp1.first.first = col - 2;
                temp1.first.second = row - 1;
                temp1.second = level + 1;
                visited[col - 2][row - 1] = 1;
                chessq.push( temp1 );
            }
            if( col+1 < 8 && row + 2 <8 && visited[col + 1][row + 2] == 0 )
            {
                iii temp1;
                temp1.first.first = col + 1;
                temp1.first.second = row + 2;
                temp1.second = level + 1;
                visited[col + 1][row + 2] = 1;
                chessq.push( temp1 );
            }
            if( col - 1 >= 0 && row + 2 <8 && visited[col -1][row + 2] == 0 )
            {
                iii temp1;
                temp1.first.first = col - 1;
                temp1.first.second = row + 2;
                temp1.second = level + 1;
                visited[col - 1][row + 2] = 1;
                chessq.push( temp1 );
            }
            if( col+1 < 8 && row - 2 >=0 && visited[col + 1][row - 2] == 0 )
            {
                iii temp1;
                temp1.first.first = col + 1;
                temp1.first.second = row - 2;
                temp1.second = level + 1;
                visited[col + 1][row - 2] = 1;
                chessq.push( temp1 );
            }
            if( col - 1 >= 0 && row - 2 >= 0 && visited[col - 1][row - 2] == 0 )
            {
                iii temp1;
                temp1.first.first = col - 1;
                temp1.first.second = row - 2;
                temp1.second = level + 1;
                visited[col - 1][row - 2] = 1;
                chessq.push( temp1 );
            }
        }
        cout<<ans<<endl;
    }
}



