#include<iostream>
using namespace std;

class abc
{
    int a,b,c;
    public:
    void getdata();
    void show();
};
void abc::getdata()
{
    cout<<"Enter two numbers : ";
    cin>>a>>b;
}
void abc::show()
{
    cout<<"Address : "<<this<<endl;
    c = this->a + this->b;
    cout<<"sum : "<<this->c;
}
int main()
{
    abc *t;
    t = new abc;
    t->getdata();
    t->show();

    delete t;
    
    return 0;
}