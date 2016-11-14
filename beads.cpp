#include <iostream>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    string nlace; int len = 0; int smallestbead = 0;
    while( tc-- )
    {
        cin>>nlace;
        len = nlace.length();
        int arrayindices[len];
        for( int i = 0; i < len; i ++)
            arrayindices[i] = 0;

        smallestbead = (int)nlace[0];
        for( int i = 0; i < len; i++ )
        {
            if( (int)nlace[i]<smallestbead )
                smallestbead = (int)nlace[i];
        }

        int counter = 0;
        for( int i = 0; i < len; i++ )
        {
            if( (int)nlace[i] == smallestbead )
            {
                arrayindices[counter] = i;
                counter++;
            }
        }

        int arraycheckbeads[counter][2];

        while ( 1 )
        {
            int counter2 = 0;
            for( int j = 0; j < counter; j ++)
            {
                arraycheckbeads[j][0] = (int) nlace[arrayindices[j]+1];
                arraycheckbeads[j][1] = arrayindices[j];
                arrayindices[j] = arrayindices[j] + 1;
            }

            for(int i1=0;i1<counter-1;i1++)
            {
                for(int i2=0;i2<counter-1;i2++)
                {
                    if(arraycheckbeads[i2][0]>arraycheckbeads[i2+1][0])
                        {
                            int hold=arraycheckbeads[i2][0];
                            arraycheckbeads[i2][0]=arraycheckbeads[i2+1][0];
                            arraycheckbeads[i2+1][0]=hold;
                        }
                }
            }

            if( arraycheckbeads[0][0] == arraycheckbeads[1][0] )
                continue;
            else if( arraycheckbeads[0][0] < arraycheckbeads[1][0] )
            {
                cout<< arraycheckbeads[0][1];
                break;
            }
        }
    }
}
















