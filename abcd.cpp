#include <iostream>
#include <stdio.h>
using namespace std;


int returnnum ( char c )
{
    if( c== 'A' )
        return 0;
    else if( c== 'B' )
        return 1;
    else if( c == 'C' )
        return 2;
    else if( c =='D' )
        return 3;
}

char returnchar( int x )
{
    if( x==0 )
        return 'A';
    else if( x==1 )
        return 'B';
    else if( x==2 )
        return 'C';
    else if( x == 3)
        return 'D';
}


int main()
{
    int n;
    scanf("%d", &n );

    //while( tc -- )
    //{
        string a;
        cin>>a;

        int n2 = a.length();

        int arr[4];
        for( int i = 0; i <4; i ++ )
            arr[i] = n2/2;

        for( int i = 0; i < a.length(); i ++ )
        {
            if( a[i] == 'A' )
                arr[0]--;
            else if( a[i] == 'B' )
                arr[1]--;
            else if( a[i] == 'C' )
                arr[2]--;
            else if( a[i] == 'D' )
                arr[3]--;
        }

        //for( int i = 0; i < 4; i ++ )
          //  cout<<arr[i]<<endl;

        string arr2;

        for( int i = 0; i < n2; i ++ )
        {
            int max = -100000000; char maxchar;
            for( int j = 0; j < 4; j ++ )
            {

                if( i != 0  )
                {
                    if( arr[j] >= max && arr[j]!=0 && j != returnnum(a[i]) && j!= returnnum(arr2[i-1] ) )
                    {
                        max = arr[j];
                        maxchar = returnchar( j );
                    }
                }
                else if( i == 0 )
                {
                    if( arr[j] >= max && arr[j]!=0 && j!= returnnum( a[0] ) )
                    {
                        max = arr[j];
                        maxchar = returnchar( j );
                    }
                }
            }
            //cout<<maxchar<<endl;
            arr2 = arr2 + maxchar;
            arr[returnnum(maxchar)]--;
        }

        cout<<arr2<<endl;

}

