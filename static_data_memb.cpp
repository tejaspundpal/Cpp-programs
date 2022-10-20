#include<iostream>
using namespace std;

class num
{
    static int c;
    int n;
    public:
    void getdata()
    {
        cout<<"Enter integer : ";
        cin>>n;
        c++;
    }
     void showcount()
    {
        cout<<"Count : "<<c<<endl;
    }
    void shownum()
    {
        cout<<"Number : "<<n<<endl;
    }
};
int num::c;

int main()
{
    num x,y;
    x.showcount();
    y.showcount();
    x.getdata();
    y.getdata();
    x.showcount();
    y.showcount();
    x.shownum();
    y.shownum();
    return 0;
}