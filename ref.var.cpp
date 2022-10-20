#include<iostream>
using namespace std;

void f(int & x)
{
    x = x + 10;
}

int main()
{
    int m = 10;
    f(m);
    cout<<m<<endl;
    return 0;
}