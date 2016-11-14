#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

int main()
{
    while( 1 )
    {
        float mw; float mi; float tw; float ti;
        scanf( "%f %f %f %f", &mw, &mi, &tw, &ti );

        if( mw == 0 && mi == 0 && tw == 0 && ti == 0 )
            break;
        float cw = 4.19; float ci = 2.09;
        float x = mw * cw * tw;
        float y = mi * ci * ( 0 - ti );

        if( x > y )
        {
            float t1 = tw - ( y / (mw*cw) );
           // cout<<"t1 = "<<t1<<endl;
            float x1 = mw*cw*t1;
            float y1 = mi*335;

            if( y1 > x1 )
            {
                //cout<<"check 1"<<endl;
                float m = (mw*cw*t1) / 335;
                cout<<fixed;
                cout<<setprecision(1)<< mi - m <<" g of ice and "<<setprecision(1)<<mw + m<<" g of water at 0.0 C"<<endl;
                //mi - m grams of ice at 0 k
                //mw + m grams of water at 0 k
            }
            else if( x1 > y1 )
            {
                //cout<<" check 2 "<<endl;
                float t2 = t1 - ((mi*335) / (mw*cw) );
               // cout<<"t2 = "<<t2<<endl;
                float temp = mw*cw*t2/(mi*cw + mw*cw);
                //cout<<"temp = "<<temp<<endl;
                cout<<fixed;
                cout<<"0.0 g of ice and "<<setprecision(1)<<mw + mi<<" g of water at "<<setprecision(1)<<temp<<" C"<<endl;
                //mi + mw grams of water at temp k
            }
            else if( x1 == y1 )
            {
                               // cout<<" check 3 "<<endl;

                cout<<fixed;
                cout<<"0.0 g of ice and "<<setprecision(1)<<mw + mi<<" g of water at 0.0 C"<<endl;
                //mi + mw grams of water at 0 k
            }
        }
        else if( x == y )
        {
            cout<<fixed;
            cout<<setprecision(1)<< mi <<" g of ice and "<<setprecision(1)<< mw <<" g of water at 0.0 C"<<endl;
            //mi grams of ice at 0 k
            //mw grams of water at 0 k
        }

        else if( x < y )
        {
            float tf = ( (x) / (mi*ci) ) + ti;
            //cout<<" tf = "<<tf<<endl;
            float x1 = mw*335;
            float y1 = mi*ci*(0 - tf);

            if( x1 > y1 )
            {
                                //cout<<" check 5 "<<endl;

                float a = mi*ci*(0 - tf) / 335;
                //cout<<"a = "<<a<<endl;
                cout<<fixed;
                cout<<setprecision(1)<< mi + a <<" g of ice and "<<setprecision(1)<<mw - a<<" g of water at 0.0 C"<<endl;
                //mw - a water at 0
                //mi + a ice at 0
            }
            else if( y1 > x1 )
            {
                                //cout<<" check 6 "<<endl;

                float t2 = ( (mw*335)/ (mi*ci) ) + tf;
                //cout<<"t2 = "<<endl;
                float temp = (mi*ci*t2)/(mi*ci + mw*ci);
                //cout<<"temp = "<<temp<<endl;
                cout<<fixed;
                cout<<setprecision(1)<< mi + mw <<" g of ice and 0.0 g of water at "<<setprecision(1)<< temp<< " C"<<endl;
                //mw + mi ice at temp
            }
            else if( y1 == x1 )
            {
                                //cout<<" check 7 "<<endl;

                cout<<fixed;
                cout<<setprecision(1)<< mi + mw <<" g of ice and 0.0 g of water at 0.0 C"<<endl;
                //mw + mi ic at 0
            }
        }
    }
}











