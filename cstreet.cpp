#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> P;

struct order
{
    bool operator() ( P const& a, P const& b ) const
    {
        return a.second > b.second || a.second == b.second && a.first < b.first;
    }
};

int main()
{
    int tc;
    cin>>tc;
    while( tc -- )
    {
        int price;
        cin>>price;

        int n;
        cin>>n;
        int e;
        cin>>e;

        int * *adjmat = new int*[n];
        for( int i = 0; i <n; i ++ )
            adjmat[i]= new int[n];

        for( int i = 0; i <n; i ++ )
            for( int j = 0; j <n; j ++ )
                adjmat[i][j] = 100000;

        while( e -- )
        {
            int v1; cin>>v1;
            int v2; cin>>v2;
            int elen; cin>>elen;

            adjmat[v1-1][v2-1] = elen;
            adjmat[v2-1][v1-1] = elen;
        }

        P vertex;
        vertex.first = 0;
        vertex.second = 0;

        priority_queue< P, vector<P>, order > q;
        q.push( vertex );

        long long int len = 0;
        bool popped[n];

        for( int i = 0; i < n; i ++ )
            popped[i] = 0;

        while( !q.empty() )
        {
            P temp;
            temp = q.top();
            q.pop();
            int vertex1 = temp.first;
            if(popped[vertex1] == 0)
            {
                popped[vertex1] = 1;
                //cout<<vertex1<<endl;
                len = len + temp.second;
            }

            for( int i = 0; i < n; i ++ )
            {
                if( popped[i] == 0 && adjmat[vertex1][i]!= 100000)
                {
                    P temp2;
                    temp2.first = i;
                    temp2.second = adjmat[vertex1][i];
                    q.push( temp2 );
                }
            }
        }

        //cout<<len<<" "<<price<<endl;
        int totalprice = price * len;
        cout<<totalprice<<endl;

        for( int i = 0; i <n; i ++ )
            delete[] adjmat[i];
        delete [] adjmat;
    }
}






