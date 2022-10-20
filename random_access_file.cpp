#include <iostream>
#include <fstream>
using namespace std;

class player
{
    char pnm[20];
    int runs, inns;
    float avg;

public:
    void playdata()
    {
        cout << "Enter name,runs and innings : ";
        cin >> pnm >> runs >> inns;
    }
    void showavg()
    {

        avg = (float)(runs / inns);
        cout << pnm << "\t" << avg << endl;
    }
};

int main()
{
    player py;
    fstream fs;
    int b,r;
// fs.open("cricket.txt",ios::out|ios::binary);
// for(int i = 1;i <= 5;i++)
// {
//     py.playdata();
//     fs.write((char *)&py,sizeof(py));
// }
// fs.close();

fs.open("cricket.txt",ios::in|ios::binary);
cout<<"\nRecord No To Search?";
cin>>r;
b=(r-1)*sizeof(py);
cout<<"\nByte:"<<b<<endl;
fs.seekp(b);
    fs.read((char *)&py,sizeof(py));
    py.showavg();

fs.close();

return 0;
}
