#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
int main()
{
    int cx, cy;
    srand(clock());
    int arr[8][8]={ {1,1,1,1,1,1,1,1}, {1,2,2,2,2,2,2,1}, {1,2,3,3,3,3,2,1}, {1,2,3,4,4,3,2,1}, {1,2,3,4,4,3,2,1}, {1,2,3,3,3,3,2,1}, {1,2,2,2,2,2,2,1}, {1,1,1,1,1,1,1,1}};
    bool arr2[8][8]={0};
    int var2=(rand()%2)+1;
    switch(var2)
    {
        case 1:
          cx=rand()%2;
          if(cx==1)
          cx=7;
          cy=rand()%8;
          break;
        case 2;
          cy=rand()%2;
          if(cy==1)
          cy=7;
          cx=rand()%8;
          break;
      }   
      arr2[cx][cy]= 1;
    for(int var1=0; var1<8; var1++)
    {
        
