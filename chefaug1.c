#include <iostream>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    int len;
    string arr1;
    int counter = 0;

    while( tc-- )
    {
        cin>>len;

        int arr2[len];
        for( int i = 0; i < len; i ++ )
            arr2[i] = 0;

        cin>>arr1;

        if( arr1[0] == '1' )
        {
            arr2[0] = 1;
            counter++;
        }

        for( int i = 1; i < len-1; i ++ )
        {
            if ( arr1[i] == '1' )
            {
                if( arr2[i]==0)
                {
                    arr2[i] = 1;
                    counter++;
                }
                if( arr2[i-1] == 0 )
                {
                    arr2[i-1] = 1;
                    counter ++;
                }

                if( arr2[i + 1] == 0 )
                {
                    arr2[i+1] = 1;
                    counter ++;
                }
            }
        }

        if( arr1[len-1] == '1' && arr2[len-1] == 0 )
        {
            arr2[len-1] = 1;
            counter++;
            if( arr2[len-2] == 0 )
            {
                arr2[len-2] = 1;
                counter ++;
            }
        }
        cout<< len-counter<<endl;
    }
}





