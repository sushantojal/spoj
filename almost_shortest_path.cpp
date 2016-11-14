#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef vector< ii > vii;
typedef vector< vii > graph;


/*struct order
{
    bool operator() ( const pair< int, int > &left, const pair< int, int > &right )
    {
        return left.second < right.second;
    }
};*/


int main()
{
    while( 1 )
    {

    int n;
    cin>>n;

    int m;
    cin>>m;

    if( n == 0 && m == 0 )
        break;

    int ini_city;
    cin>>ini_city;

    int exit_city;
    cin>>exit_city;

    graph G;
    vii::iterator it;
    for( int i = 0; i < n; i ++ )
        G.push_back( vii() );


    while( m -- )
    {
        int a;
        cin>>a;

        int b;
        cin>>b;

        int t;
        cin>>t;

        ii temp1;
        temp1.first = b;
        temp1.second = t;

        G[a].push_back( temp1 );
    }

    int D[n]; int parent[n]; bool path[n];
    for( int i = 0; i < n; i ++ )
    {
        D[i] = 100001;
        parent[i] = -1;
        path[i] = 0;
    }

    priority_queue< ii, vector<ii>, greater<ii> > Q;

    D[ini_city] = 0;

    ii s;
    s.first = ini_city;
    s.second = 0;

    Q.push(s);

    while( !Q.empty() )
    {
        ii temp2 = Q.top();
        Q.pop();

        int v = temp2.first; int d = temp2.second;

        if( d <= D[v] )
        {
            if( v == exit_city )
                break;
           // path[v] = 1;
            //cout<<v<<endl;

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
    int check = D[exit_city];
    if( check == 1000001 )
    {
        cout<<"-1"<<endl;
        continue;
    }


    path[exit_city] = 1;
    int curr_city = exit_city;
    while ( curr_city!=ini_city )
    {
        path[curr_city] = 1;
        if( parent[curr_city] >= 0 )
            curr_city = parent[curr_city];
        else
            break;
    }
    path[curr_city] = 1;




    for( int i = 0; i < n; i ++ )
    {
        if( path[i] == 1 && i!=ini_city )
        {
            if( parent[i] >= 0 )
            {
                for( int j = 0; j < G[parent[i]].size(); j ++ )
                {
                    if( G[parent[i]][j].first == i )
                    {
                        G[parent[i]].erase( G[parent[i]].begin() + j );
                        break;
                    }
                }
            }
        }
    }



    /*for( int i = 0; i < n; i ++ )
    {
        cout<<i<<" - ";
        for( int j = 0; j < G[i].size(); j ++ )
        {
            cout<<G[i][j].first<<" ";
        }
        cout<<endl;
    }*/

//--------------------------------------------------------------------------------------------------------------------------------


    priority_queue< ii, vector<ii>, greater<ii> > Q2;

    while( check == D[exit_city] && check!= 1000001 )
    {
        int *D2 = new int[n];   bool *path2 = new bool[n]; int *parent2 = new int[n];
        for( int i = 0; i < n; i ++ )
        {
            D2[i] = 1000001;
            path2[i] = 0;
            parent2[i] = -1;
        }


        D2[ini_city] = 0;

        ii s2;
        s2.first = ini_city;
        s2.second = 0;

        Q2.push(s2);

        while( !Q2.empty() )
        {

            ii temp2 = Q2.top();
            Q2.pop();
            //cout<<"blah"<<endl;
            int v = temp2.first; int d = temp2.second;

            if( d <= D2[v] )
            {
                if( v == exit_city )
                    break;
                int var1 = 0;
                for( it = G[v].begin(); it < G[v].end() ; it++ )
                {
                    ii temp3 = G[v][var1];
                    int u = temp3.first;
                    int dvu = temp3.second;

                    if( D2[u] > D2[v] + dvu )
                    {
                        D2[u] = D2[v] + dvu;
                        ii temp4;
                        temp4.first = u;
                        temp4.second = D2[u];
                        parent2[u] = v;
                        Q2.push( temp4 );
                    }
                    var1++;
                }
            }
        }

        check = D2[exit_city];
        if( check == 1000001 )
            break;

        /*for( int i = 0; i < n; i ++ )
        {
            cout<<i<<" - ";
            for( int j = 0; j < G[i].size(); j ++ )
            {
                cout<<G[i][j].first<<" ";
            }
            cout<<endl;
        }*/


        path2[exit_city] = 1;
        int curr_city = exit_city;
        while ( curr_city!=ini_city )
        {
            path2[curr_city] = 1;
            if( parent2[curr_city] >= 0 )
                curr_city = parent2[curr_city];
            else
                break;
        }
        path2[curr_city] = 1;

        cout<<endl<<endl;
        for( int i = 0; i < n; i ++ )
            cout<<parent2[i]<<endl;
        cout<<endl<<endl;
        for( int i = 0; i < n; i ++ )
                cout<<path2[i]<<endl;

        for( int i = 0; i < n; i ++ )
        {
            if( path2[i] == 1 && i!=ini_city )
            {
                if( parent2[i] >= 0 )
                {
                    for( int j = 0; j < G[parent2[i]].size(); j ++ )
                    {
                        if( G[parent2[i]][j].first == i )
                        {
                            G[parent2[i]].erase( G[parent2[i]].begin() + j );
                            break;
                        }
                    }
                }
            }
        }

        /*for( int i = 0; i < n; i ++ )
        {
            cout<<i<<" - ";
            for( int j = 0; j < G[i].size(); j ++ )
            {
                cout<<G[i][j].first<<" ";
            }
            cout<<endl;
        }*/

        delete[] D2;
        delete[] path2;
        delete[] parent2;


        //Q2 = priority_queue < ii, vector< ii >, greator< ii > >();
    }


    if( check == 1000001 )
        cout<<"-1"<<endl;
    else
        cout<<check<<endl;
    }
}








