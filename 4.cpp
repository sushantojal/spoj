#include<iostream>
#include<fstream>
using namespace std;
int main()
{
  ifstream in("brain.pgm");
  ofstream out("output.txt");
  string type;
  in>>type;
  if(type=="P5")
    {
      out<<"P5"<<endl;
      int width,height,maxval,threshhold;
      in>>width>>height>>maxval;  
      out<<width<<" "<<height<<" "<<maxval<<endl;
      cout<<"threshold value ?\n";
      cin>>threshhold;
      string line;
      for(int i=0;i<height;i++)
      {
       getline(in,line);
       for(unsigned int j=0;j<line.length();j++)
       {
			 if((int)line[j]<threshhold)
			   out<<0;
			 else
			   out<<(char)maxval;
         }
       out<<endl;
       }
  }
  else
    cout<<"file doesnt match"<<endl;
 system("pause");
  return 0;
  }
