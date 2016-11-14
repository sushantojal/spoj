#include <iostream>
#include <cmath>
#define con 0.0174532925
using namespace std;

int main()
{
   int tc;
   int u,v,x,y,a,b,ap,bp;
   cin>>tc;
   while(tc--)
    {
        cin>>u>>v>>x>>y;
        if(u>=v)
        {
            a=u;
            b=v;
        }
        else
        {
            a=v;
            b=u;
        }
        if(x>=y)
        {
            ap=x;
            bp=y;
        }
        else
        {
            ap=y;
            bp=x;
        }
        if((ap>=b)&&(ap<a)&&(bp<a)&&(bp<b))
        {
        cout<<"Escape is possible."<<endl;
        }
        else if((ap<a)&&(ap<=b)&&(bp<a)&&(bp<b))
        {
        cout<<"Escape is possible."<<endl;
        }
        else if((ap<(sqrt(2.00)*a))&&(ap>=a)&&(ap>b)&&(bp<b)&&(bp<a))
        {
            bool chk=0;
            double x,y;
            long long rhs= (a*a)+(b*b)+(bp*bp)-(ap*ap);


           unsigned long var1= (a*a)+(bp*bp);
           int var2= 2*a*bp;
           double ang1= (double)var2/var1;
           double ang2= (double)asin(ang1);
           double uang= (double)ang2/con;

            for(int ang=45; ang>uang; ang--)
            {
                y=bp*cos(ang*con);
                x=bp*sin(ang*con);
                long long lhs=(2*a*x)+(2*b*y);
                if((lhs<rhs)&&((ap*cos(ang*con))<a))
                {
                    chk=1;
                    break;
                }
            }
            if(chk==1)
            cout<<"Escape is possible."<<endl;
            else
            cout<<"Box cannot be dropped."<<endl;
        }else
        cout<<"Box cannot be dropped."<<endl;
    }
}
