#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


bool sortFunc( const vector<long long int>& p1,
               const vector<long long int>& p2 ) {
 return p1[3] < p2[3];
}

int main()
{
    while (1)
    {

    int n;
    scanf("%d", &n );

    if( n == 0 )
        break;

    int *l = new int[n+1];
    int *b = new int[n+1];
    int *h = new int[n+1];

    for( int i = 1; i <= n; i ++ )
    {
        scanf("%d", &l[i] );
        scanf("%d", &b[i] );
        scanf("%d", &h[i] );
    }

    //cout<<"here"<<endl;

    vector< vector<long long int> > dim;

    for( int i = 0; i <= 3*n; i ++ )
        dim.push_back( vector<long long int>() );

    for( int i = 0; i < 4; i ++ )
        dim[0].push_back(-1 );

    int k = 1;

    for( int i = 1; i <= 3*n; i +=3 )
    {
        dim[i].push_back( l[k] );
        dim[i].push_back( b[k] );
        dim[i].push_back( h[k] );
        dim[i].push_back( dim[i][1] * dim[i][2] );

        dim[i+1].push_back( b[k] );
        dim[i+1].push_back( h[k] );
        dim[i+1].push_back( l[k] );
        dim[i+1].push_back( dim[i+1][1] * dim[i+1][2] );

        dim[i+2].push_back( h[k] );
        dim[i+2].push_back( l[k] );
        dim[i+2].push_back( b[k] );
        dim[i+2].push_back( dim[i+2][1] * dim[i+2][2] );

        k++;

    }



    sort( dim.begin(), dim.end(), sortFunc );

    long long int *sum = new long long int[3*n + 1];

    for( int i = 1; i <= 3*n; i ++ )
        sum[i] = dim[i][0];

    for( int i = 1; i <= 3*n; i ++ )
        for( int j = 1; j<i; j ++ )
            if( dim[j][1] < dim[i][1] && dim[j][2] < dim[i][2] && sum[i] < sum[j] + dim[i][0] )
                sum[i] = dim[i][0] + sum[j];

    long long int max = -100;

    for( int i = 1; i <= 3*n; i ++ )
        if( max < sum[i] )
            max = sum[i];

    printf("%lld\n", max );

    dim.erase( dim.begin(), dim.end() );
    delete[] l;
    delete[] b;
    delete[] h;
    delete[] sum;

    }
}





