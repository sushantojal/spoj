#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc );
    int count = 1;

    while( tc-- )
    {

        char * inp = new char[100];
        scanf("%s", inp );

        int len = strlen(inp);
        bool *check = new bool[36];

        for( int i = 0; i < 36; i ++ )
            check[i] = 0;

        int *pri = new int[36];
        for( int i = 0; i < 36; i ++ )
            pri[i] = 0;

        int pr = 1;

        for( int i = 0; i < len ; i ++ )
        {
            int index = (int)inp[i];
            if( index >= 97 && index <= 122 )
                index = index-97;
            else
                index = index - 48 + 26;


            if( check[index] == 0 )
            {
                check[index] = 1;
                pri[index] = pr;
                pr++;
            }
        }

        pr--;

        if( pr == 1 )
            pr = 2;


        //cout<<pr<<endl;
        long long int val= 0;
        long long int temp = 0;
        //int ind = 1;
        for( int i = 0; i < len; i ++ )
        {
            int index = (int)inp[i];
            if( index >= 97 && index <= 122 )
                index = index-97;
            else
                index = index - 48 + 26;
            if( pri[index] == 1 )
            {
                temp = pri[index] * pow( pr, len - i - 1 );
                val = val + temp;
                //cout<<"  "<<val<<endl;
                //ind++;
            }
            else if( pri[index] > 2 )
            {
                temp = (pri[index]-1)* pow(pr,len - i - 1);
                val = val + temp;
                //cout<<"  "<<val<<endl;
                //ind++;
            }

        }


        /*for(int i = 0 ; i < len; i ++ )
        {

            int index = (int)inp[i];
            if( index >= 97 && index <= 122 )
                index = index-97;
            else
                index = index - 48 + 26;

            cout<<pri[index]<<endl;
        }*/

        printf("Case #%d: %lld\n", count, val );
        count ++ ;
    }

}



