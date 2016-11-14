#include <iostream>
#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int main()
{
    int count = 1;
    while( 1 )
    {
        int h, w;
        scanf("%d %d", &h, &w );
        if( h == 0 && w== 0 )
            break;

        int **arr = new int*[h];
        for( int i = 0; i < h; i ++ )
            arr[i] = new int[w];

        for( int i = 0; i < h; i ++ )
        {
            char * inp = new char[100];
            scanf("%s", inp );

            for( int j = 0; j < w; j ++ )
            {
                char temp = inp[j];
                //scanf("%c", &temp );
                arr[i][j] = (int)temp;
            }
        }



        bool **chk = new bool*[h];
        for( int i = 0; i < h; i ++ )
            chk[i] = new bool[w];

        /*for( int i = 0; i < h; i ++ )
            for( int j = 0; j < w; j ++ )
                chk[i][j] = 0;*/

        queue<iii> q; int currval = 0; int max = -100000;

        for( int i = 0; i < h; i ++ )
        {
            for( int j = 0; j < w; j ++ )
            {

                //cout<<"Erawea"<<endl;

                if( arr[i][j] == 65  )
                {
                    for( int d = 0; d < h; d ++ )
                        for( int f = 0; f < w; f ++ )
                            chk[d][f] = 0;

                    iii temp;
                    temp.first.first = i;
                    temp.first.second = j;
                    temp.second = 65;
                    q.push( temp );
                    chk[i][j] = 1;

                    while( !q.empty() )
                    {
                        iii temp = q.front();
                        q.pop();
                        currval = temp.second;
                        int i = temp.first.first;
                        int j = temp.first.second;

                        //cout<<currval<<endl;

                        if( i != h-1 )
                        {
                            if( arr[i+1][j] == currval+1 && chk[i+1][j] == 0)              //directly below
                            {
                                iii temp2;
                                temp2.first.first = i+1;
                                temp2.first.second = j;
                                temp2.second = currval+1;
                                q.push( temp2 );
                                chk[i+1][j] = 1;
                                //currval = arr[i+1][j];
                            }
                        }

                        if( i!= h-1 && j!= w-1 )
                        {
                            if( arr[i+1][j+1] == currval+1 && chk[i+1][j+1] == 0 )              //diagonally below right
                            {
                                iii temp2;
                                temp2.first.first = i+1;
                                temp2.first.second = j+1;
                                temp2.second = currval+1;
                                q.push( temp2 );
                                chk[i+1][j+1] = 1;
                                //currval = arr[i+1][j+1];
                            }
                        }

                        if( j!= w-1 )
                        {

                            if( arr[i][j+1] == currval+1 && chk[i][j+1] == 0 )              //right
                            {
                                iii temp2;
                                temp2.first.first = i;
                                temp2.first.second = j+1;
                                temp2.second = currval+1;
                                q.push( temp2 );
                                chk[i][j+1] = 1;
                                //currval = arr[i][j+1];
                            }
                        }

                        if( j!= w-1 && i!= 0 )
                        {
                            if( arr[i-1][j+1] == currval+1 && chk[i-1][j+1] == 0 )              //diagonally up right
                            {
                                iii temp2;
                                temp2.first.first = i-1;
                                temp2.first.second = j+1;
                                temp2.second = currval+1;
                                q.push( temp2 );
                                chk[i-1][j+1] = 1;
                                //currval = arr[i-1][j+1];
                            }
                        }

                        if( i!= 0 )
                        {
                            if( arr[i-1][j] == currval+1 && chk[i-1][j] == 0 )              //up
                            {
                                iii temp2;
                                temp2.first.first = i-1;
                                temp2.first.second = j;
                                temp2.second = currval+1;
                                q.push( temp2 );
                                chk[i-1][j] = 1;
                                //currval = arr[i-1][j];
                            }
                        }

                        if( i!= 0 && j!= 0)
                        {
                            if( arr[i-1][j-1] == currval+1 && chk[i-1][j-1] == 0 )              //diagonally up left
                            {
                                iii temp2;
                                temp2.first.first = i-1;
                                temp2.first.second = j-1;
                                temp2.second = currval+1;
                                q.push( temp2 );
                                chk[i-1][j-1] = 1;
                                //currval = arr[i-1][j-1];
                            }
                        }

                        if( j!= 0 )
                        {
                            if( arr[i][j-1] == currval+1 && chk[i][j-1] == 0 )              //left
                            {
                                iii temp2;
                                temp2.first.first = i;
                                temp2.first.second = j-1;
                                temp2.second = currval+1;
                                q.push( temp2 );
                                chk[i][j-1] = 1;
                                //currval = arr[i][j-1];
                            }
                        }

                        if( i!= h-1 && j!= 0)
                        {
                            if( arr[i+1][j-1] == currval+1 && chk[i+1][j-1] == 0 )              //diagonally belowleft
                            {
                                iii temp2;
                                temp2.first.first = i+1;
                                temp2.first.second = j-1;
                                temp2.second = currval+ 1;
                                q.push( temp2 );
                                chk[i+1][j-1] = 1;
                                //currval = arr[i+1][j-1];
                            }
                        }

                        if( max <= currval )
                            max = currval;
                    }
                }
            }
        }
        if( max < 0 )
            max = 0;
        else
            max = max - 64;

        printf("Case %d: %d\n", count, max );
        count++;
    }
}




