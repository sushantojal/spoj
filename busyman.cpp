#include <iostream>
using namespace std;

/*int partition( int **arr, int p, int q )
{
    int r = q;
    int j = 0; int i = j - 1;

    for(; j <= r - 1; j ++ )
    {
        if( arr[1][j] > arr[1][r] )
            continue;
        else if( arr[1][r] >= arr[1][j] )
        {
            i = i + 1;
            int temp = arr[1][i];
            arr[1][i] = arr[1][j];
            arr[1][j] = temp;

            int temp3 = arr[0][i];
            arr[0][i] = arr[0][j];
            arr[0][j] = temp3;
        }
    }

        int temp2 = arr[1][r];
        arr[1][r] = arr[1][i + 1];
        arr[1][i + 1] = temp2;

        int temp4 = arr[0][r];
        arr[0][r] = arr[0][i + 1];
        arr[0][i + 1] = temp4;

    return (i + 1);
}

void qsort( int **arr, int p, int r )
{
    if( p < r )
    {
        int q = partition( arr, p, r );
        qsort( arr, p, q - 1 );
        qsort( arr, q + 1, r );
    }
}*/


void merge( int **arr, int low, int high, int **arr2 );
void merge_sort( int * *arr, int low, int high, int * *scratch )
{
    int pivot;
    if( low < high )
    {
        pivot = ( low + high ) / 2;
        merge_sort( arr, low, pivot, scratch );
        merge_sort( arr, pivot+1, high, scratch );
        merge( arr, low, high, scratch );
    }
}

void merge( int **arr, int low, int high, int **arr2 )
{
    int pivot = ( low + high ) / 2;
    //cout<<"low = "<<low<<endl;
    //cout<<"high = "<<high<<endl;
    int i = low; int j = pivot+1; //int high1 = high;
    int k = low;
    //int chk = 0;
    while( i<=pivot && j<=high)
    {
        if( arr[1][i] <= arr[1][j])
        {
            arr2[1][k] = arr[1][i];
            arr2[0][k] = arr[0][i];
            k++;
            i++;
            //chk = 1;
        }
        else if( arr[1][i] > arr[1][j])
        {
            arr2[1][k] = arr[1][j];
            arr2[0][k] = arr[0][j];
            k++;
            j++;
            //chk = 2;
        }
        //cout<<chk<<endl;
    }

    while( i<= pivot)
    {
        arr2[1][k] = arr[1][i];
        arr2[0][k] = arr[0][i];
        k++;
        i++;
    }

    while( j<= high)
    {
        arr2[1][k] = arr[1][j];
        arr2[0][k] = arr[0][j];
        k++;
        j++;
    }

    for( int i = low; i < k; i ++ )
    {
        arr[1][i] = arr2[1][i];
        arr[0][i] = arr2[0][i];
       // printf( "%d " , arr[i] );
    }
    //printf("\n");

}


int main()
{
    int tc;
    cin>>tc;

    int nact = 0;

    while( tc -- )
    {
        int count = 1;
        cin>>nact;

        int * *act = new int*[2];
        int * *scratch = new int*[2];
        for( int i = 0; i < 2; i ++ )
        {
            act[i] = new int[nact];
            scratch[i] = new int[nact];
        }


        for( int i = 0; i < nact; i ++ )
        {
            cin>>act[0][i];
            cin>>act[1][i];
        }



        int var = nact - 1 ;

        merge_sort( act, 0, var, scratch );
        int j = 0;

        for( int i = 1; i < nact; i ++ )
        {
            if( act[0][i] >= act[1][j] )
            {
                count ++;
                j = i;
            }
        }

        cout<<count<<endl;
    }
}

