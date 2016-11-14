#include <iostream>
using namespace std;

int main()
{
    int size;
    cin>>size;

    int tc;
    cin>>tc;

    int *arr = new int[size];
    for( int i = 0; i < size; i++ )
        cin>>arr[i];

    while( 1 )
    {
        int lower, upper;
        cin>>lower;

        if( lower == 0 )
            break;

        cin>>upper;

        if( size == 1 )
        {
            cout<<"1"<<endl;
            continue;
        }

        if( lower == upper )
        {
            cout<<"1"<<endl;
            continue;
        }

        lower = lower - 1;
        upper = upper - 1;

        int currcount = 1; int maxcount = 0;

        for( int i = lower+1; i <= upper; i ++ )
        {
            if( arr[i] == arr[i - 1] )
                currcount++;
            else
            {
                if( currcount > maxcount )
                     maxcount = currcount;
                currcount = 1;
            }
            if( i == upper && arr[upper] == arr[upper - 1] )
            {
                if( currcount > maxcount )
                     maxcount = currcount;
            }
        }

        cout<<maxcount<<endl;
    }
    delete[] arr;
}

