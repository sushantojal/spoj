#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include<utility>

using namespace std;
int move[][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        queue< pair<int,int> > q;
        cin>>n>>m;
        int ans[n+3][m+3];
        char a[n+4][m+5];
        for(int i=0;i<n;i++)
        //for(int j=0;j<m;j++)
            scanf("%s",&a[i]);//cin>>a[i];///

        //for(int i=0;i<n;i++)
          ///  cout<<a[i][1];

        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            {
                if(a[i][j]=='0')
                  ans[i][j]=-1;
                else
                    {
                        ans[i][j]=0;
                        q.push(pair<int,int>(i,j));
                    }
            }
/*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                printf("%d ",ans[i][j]);
            printf("\n");
        }
        */

        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();
            //cout<<temp.first<<endl;
            for(int i=0;i<4;i++)
            {
                int x=temp.first-move[i][0];
                int y=temp.second-move[i][1];
                if(x<0 || x>=n || y<0 || y>=m)
                    continue;

                if(ans[x][y]==-1)
                    {
                        ans[x][y]=ans[temp.first][temp.second]+1;
                        q.push(pair<int,int>(x,y));
                    }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                printf("%d ",ans[i][j]);
            printf("\n");
        }
    }
}
