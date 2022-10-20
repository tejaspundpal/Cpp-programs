#include<iostream>
using namespace std;

int main()
{
    int x,y;

    try
    {
    
    cout<<"Enter the value of x and y: "<<endl;
    cin>>x>>y;
    if(y != 0)
    {
    float z = float(x/y);
    cout<<"Value of z is : "<<z<<endl;
    }
    else{
        throw(y);
    }
    }
    catch(int y)
    {
        cout<<"You cannot divide by "<<y<<endl;
    }
    return 0;
}