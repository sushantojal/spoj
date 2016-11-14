#include <iostream>
using namespace std;


int bsearch( int *arr, int low, int high, int query )
{
    if( low <= high )
    {
        int pivot = (low + high)/2;

        if( query == arr[pivot] )
            return pivot;

        else if( query < arr[pivot] )
            bsearch( arr, low, pivot - 1, query );

        else if( query > arr[pivot] )
            bsearch( arr, pivot + 1, high, query );
    }
    else
        return -1;
}


int main()
{
    int size;
    cin>>size;

    int arr[size];
    //int i = 0;

    for( int i = 0; i < size; i ++ )
        cin>>arr[i];

    for( int i = 0; i < size; i ++ )
        cout<<arr[i]<<" ";

    int tc;
    cin>>tc;

    int query;

    while( tc -- )
    {
        cin>>query;
        cout<<bsearch( arr, 0, size-1, query )<<endl;
    }
}


