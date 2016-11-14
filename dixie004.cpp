#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char *num = new char[20];
    bool valid = 0;
    while( scanf("%s", num)!= EOF )
    {
        if( num[0] == '5' )
        {
            if( num[1] == '1' || num[1] == '2' || num[1] == '3' || num[1] == '4' || num[1] == '5' )
                valid = 1;
        }
        else if( num[0] == '4' )
            valid = 1;

        if( valid == 0 )
            printf("%s,FALSE\n", num );

        else
        {
            bool echeck = 0;
            int tevensum = 0;
            int oddsum = 0;
            //int len = strlen(num);
            for( int i = 15; i >=0; i -- )
            {
                if( echeck == 0 )
                {
                    oddsum = oddsum + ((int)(num[i]) - 48);
                    echeck = 1;
                }
                else if( echeck == 1 )
                {
                    int temp = 2*((int)num[i] - 48);
                    if( temp<=9 )
                        tevensum = tevensum +temp;
                    else
                    {
                        int temp2 = temp - 10;
                        tevensum = tevensum + 1 + temp2;
                    }
                    echeck = 0;
                }
            }

            //cout<<oddsum<<endl<<tevensum<<endl;
            int sum = oddsum + tevensum;
            if( sum % 10 == 0 )
                printf("%s,TRUE\n", num );
            else
                printf("%s,FALSE\n", num );


        }
    }
}

