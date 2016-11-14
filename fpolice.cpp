#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair< int, int > ii;
typedef vector< ii > vii;
//typedef vector< vii > G;

int main()
{
    int tc;
    cin>>tc;

    while( tc-- )
    {
        vector< vector< pair<int, int> > > G;
        vii::iterator it;

        int n;
        cin>>n;

        int time_limit;
        cin>>time_limit;

        for( int i = 0; i < n; i++ )
            G.push_back( vii() );

        int e = 0;

        int * *adjmat = new int*[n];
        for( int i = 0; i < n; i ++ )
            adjmat[i] = new int[n];

        for( int i = 0; i < n; i ++ )
            for( int j = 0; j < n; j ++ )
                cin>>adjmat[i][j];


        for( int i = 0; i < n; i ++ )
        {
            for( int j = 0; j < n; j ++ )
            {
                int risk; cin>>risk;
                if( i!= j )
                {
                    ii temp;
                    temp.first = j;
                    temp.second = risk;
                    G[i].push_back( temp );
                    e++;
                }
            }
        }


        /*for( int i = 0; i < n; i ++ )
        {
            cout<<i<<" - ";
            for( int j = 0; j < G[i].size(); j ++ )
            {
                cout<<G[i][j].first<<","<<G[i][j].second<<" ";
            }
            cout<<endl;
        }*/




        int D[n]; int parent[n];
        for( int i = 0; i < n; i ++ )
        {
            D[i] = 100001;
            parent[i] = -1;
        }

        priority_queue< ii, vector<ii>, greater<ii> > Q;

        int ini_cell = 0;
        int exit_cell = n - 1;

        D[ini_cell] = 0;

        ii s;
        s.first = ini_cell;
        s.second = 0;

        Q.push(s);

        while( !Q.empty() )
        {
            ii temp2 = Q.top();
            Q.pop();

            int v = temp2.first; int d = temp2.second;

            if( d <= D[v] )
            {
                int var1 = 0;
                for( it = G[v].begin(); it < G[v].end(); it++ )
                {
                    ii temp3 = G[v][var1];
                    int u = temp3.first;
                    int dvu = temp3.second;

                    if( D[u] > D[v] + dvu )
                    {
                        D[u] = D[v] + dvu;
                        ii temp4;
                        temp4.first = u;
                        temp4.second = D[u];
                        parent[u] = v;
                        Q.push( temp4 );
                    }
                    var1++;
                }
            }
        }

        int min_risk = D[exit_cell];
        int curr_city = exit_cell;
        int t = 0;

        while( curr_city!=ini_cell )
        {
            t = t + adjmat[parent[curr_city]][curr_city];
            curr_city = parent[curr_city];
        }

        if( t > time_limit )
            cout<<"-1"<<endl;
        else
            cout<<min_risk<<" "<<t<<endl;
    }
}



