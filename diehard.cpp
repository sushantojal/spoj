#include <iostream>
#include <stdio.h>

using namespace std;

int min( int a, int b )
{
    if( a <= b )
        return a;
    else
        return b;
}


int main()
{
    int tc;
    scanf("%d", &tc );

    while( tc-- )
    {
        int h, a;
        scanf("%d %d", &h, &a );

        int t = 0; char place = 'w';

        while( 1 )
        {
            if( h<=0 || a<= 0 )
                break;

            else
            {
                if( place!= 'a' )
                {
                    place = 'a';
                    h = h + 3;
                    a = a + 2;
                    t++;
                }
                else
                {
                    int h1 = h - 5;
                    int h2 = h - 20;
                    int a1 = a - 10;
                    int a2 = a + 5;

                    int min1 = min( h1, a1 );
                    int min2 = min( h2, a2 );

                    if( min1 <= 0 && min2 <= 0 )
                        break;

                    else
                    {
                        if( min1 > min2 )
                        {
                            place = 'w';
                            h = h1; a = a1;
                            t++;
                        }
                        else if( min2 > min1 )
                        {
                            place = 'f';
                            h = h2; a = a2;
                            t++;
                        }
                        else if( min1 == min2 )
                        {
                            int other1, other2;
                            if( h1 == min1 )
                                other1 = a1;
                            else
                                other1 = h1;

                            if( h2 == min1 )
                                other2 = a1;
                            else
                                other2 = h1;

                            if( other2 > other1 )
                            {
                                h = h2;
                                a = a2;
                                place = 'f';
                                t++;
                            }
                            else
                            {
                                h = h1; a = a1;
                                place = 'w';
                                t ++;
                            }
                        }
                    }
                }
            }

        }
        printf("%d\n", t );
    }
}
