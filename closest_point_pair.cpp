#include <iostream>
#include <vectors>
#incluude <utility>
#include <algorithms>
#include <math.h>
#include <iomanip>

using namespace std;

typedef pair<int, int> ii;
typedef pair< ii, int > iii;
typedef vector< iii > viii;


struct order
{
    bool operator()( const iii &left, const iii &right )
    {
        return left.first.first < right.first.first ;
    }
};

struct order_y
{
    bool operator() ( const ii &left, const && &right )
    {
        return left.second<right.second ;
    }
};

float dist( ii p1, ii p2 )
{
    float dsquare = ((( p1.first - p2.first ) * ( p1.first - p2.first )) + (( p1.second - p2.second ) * ( p1.second - p2.second )));
    return sqrt( dsquare );
}

float closestpair( vii &px, vii &inp, bool flags[], start, end )
{
    if( px.size() == 1 )
        return 100000001;
    else if( px.size() == 2 )
        return dist( px[start], px[end] )

    else
    {
        int med = ( start + end )/2;
        dleft = closestpair( px, inp, flags, start, med );
        dright = closestpair( px, inp, flags, (med + 1), end );

        int d;

        if( dleft<=dright )
            d = dleft;
        else
            d = dright;

        float x = ( px[med] + px[med+1] )/2;
        float leftstrip = x - d;
        float rightstrip = x + d;

        vii::iterator it; int var1 = 0; vii sy;
        for( it = px.begin(); it<px.end(); it++ )
        {
            if( px[var1].first >= leftstrip && px[var1].first <=rightstrip )
                sy.push_back( px[var1] );

            var1++;
        }

        sort( sy.begin(), sy.end(); order_y() );

        int jlim = 0;
        if( sy.size() < 15 )
            jlim = sy.size()
        else
            jlim = 15;

        for( int i = 0; i < sy.size(); i ++ )
        {
            for( int j = 0; j < jlim; j ++ )
            {
                float d2 = dist( sy[i], sy[j] );
                if( d < d2 )
                    return d;
                else
                    return d2;
            }
        }
    }
}


int main()
{
    int tc;
    cin>>tc;
    int temp = 0;

    while( tc-- )
    {
        int x;
        cin>>x;

        int y;
        cin>>y;

        ii point;
        point.first = x;
        point.second = y;

        viii px;
        iii pointind
        pointind.first = point;
        pointint.second = temp;

        px.push_back( pointind );
        temp+;

        //inp.push_back( point );
        //py.push_back( point );
    }

    sort(px.begin(), px.end(), order() );
    //sort(py.begin(), py.end(), order_y() );

    /*bool retpoints[n];
    for( int i = 0; i < n; i ++ )
        retpoints[i] = 0;*/

    float d = closestpair( px, 0, (px.size()-1) );


    int p1 = -1; int p2;

    for( int i = 0; i < n; i ++ )
    {
        if( px.second == 1 )
        {
            if( p1 == -1 )
                p1 = i;
            else
                p2 = i;
        }
    }

    cout<<p1<<" "<<p2<<" ";
    cout<<fixed;
    cout<<setprecision(6)<<d<<endl;
}


