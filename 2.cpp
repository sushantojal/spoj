#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream in("d.txt");
    ofstream out("o.txt");
    string line;
    in>>line;
    out<<line;
    cout<<line<<endl;
    string line1;
    in>>line1;
    cout<<line1<<endl;
    system("pause");
}
