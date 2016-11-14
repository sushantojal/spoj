#include <stdio.h>

void merge_sort(int *, int , int, int * );
void merge( int *, int, int, int * );

void merge_sort( int *arr, int low, int high, int * scratch )
{
    int pivot;
    if( low < high )
    {
        pivot = ( low + high ) / 2;
        merge_sort( arr, low, pivot, scratch );
        merge_sort( arr, pivot + 1, high, scratch );
        merge( arr, low, high, scratch );
    }
}

void merge( int *arr, int low, int high, int *scratch )
{
    int pivot = ( low + high ) / 2;
    int i = low; int j = pivot + 1; int k = low;

    while( ( i <= pivot ) && ( j <= high ) )
    {
        if( arr[i] <= arr[j] )
        {
            scratch[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            scratch[k] = arr[j];
            k++;
            j++;
        }
    }

    while( i <= pivot )
    {
        scratch[k] = arr[i];
        i ++;
        k ++;
    }

    while( j <= high )
    {
        scratch[k] = arr[j];
        j ++;
        k ++;
    }

    for( int var1 = low; var1 < k; var1 ++ )
        arr[var1] = scratch[var1];
}


int main()
{
    int tc;
    scanf( "%d", &tc );

    while ( tc-- )
    {
        int n;
        scanf( "%d", &n );
        int *menhotness = new int[n];
        int *nonmenhotness = new int[n];
        int *scratchmen = new int[n];
        int *scratchnonmen = new int[n];

        for( int var1 = 0; var1 < n; var1 ++ )
            scanf( "%d", &menhotness[var1] );

        for( int var1 = 0; var1 < n; var1 ++ )
            scanf( "%d", &nonmenhotness[var1] );

        merge_sort( menhotness, 0, n-1, scratchmen );
        merge_sort( nonmenhotness, 0, n-1, scratchnonmen );

        int sum = 0;

        for( int var1 = 0; var1 < n; var1 ++ )
            sum = sum + ( menhotness[var1] * nonmenhotness[var1] );

        printf( "%d\n", sum );
    }
}



