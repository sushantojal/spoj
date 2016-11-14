#include <iostream>
#include <stdio.h>

using namespace std;

int * getfail( char pattern[], int n )
{
    int * fail = new int[n];
    fail[0] = -1;
    int k = -1;

    for( int i = 1; i < n; i ++ )
    {
        while( k > -1 && pattern[i] != pattern[k + 1] )
            k = fail[k];

        if( pattern[i] == pattern[k + 1] && (k + 1 ) >= 0 )
            k += 1;

        fail[i] = k;
    }
    return fail;
}

int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2 );

    char small[n1][n2];
    char temp[1000];
    for( int i = 0; i < n1; i ++ )
    {
        scanf("%s", temp );
        for( int j = 0; j < n2; j ++ )
        {
            small[i][j] = temp[j];
        }
        getchar();
    }

    int m1, m2;
    scanf("%d %d", &m1, &m2 );
    char big[m1][m2];

    for( int i = 0; i < m1; i ++ )
    {
        scanf("%s", temp );
        for( int j = 0; j < m2; j ++ )
            big[i][j] = temp[j];

        getchar();
    }

    bool found = 0;
    int i = 0;
    int *fail = getfail( small[0], n2 );
    //cout<<"here"<<endl;

    while( i < m1 - n1 + 1 )
    {
        int matches = -1;
        int indx, indy;
        for( int x = 0; x < m2 ; x ++ )
        {
            while( matches > -1 && small[0][matches + 1] != big[i][x] )
                matches = fail[matches];
            if( small[0][matches + 1] == big[i][x] )
                matches += 1;
            if( matches == n2 - 1 )
            {
                indx = i;
                indy = x - n2 + 1;
                bool brk = 0;
                for( int i1 = 1; (i1 < n1) && (i1 + indx < m1) && brk == 0; i1 ++ )
                {
                    for( int j1 = 0; j1 < n2 &&  brk == 0 ; j1 ++ )
                    {
                        if( small[i1][j1] != big[i1 + indx][j1 + indy] )
                            brk = 1;
                    }
                }
                if( brk == 0 )
                {
                    printf("(%d,%d)\n", indx + 1, indy + 1 );
                    found = 1;

                }
                matches = fail[matches];
            }


        }

        i++;

    }
    if( found == 0 )
        printf("NO MATCH FOUND...\n" );
}
