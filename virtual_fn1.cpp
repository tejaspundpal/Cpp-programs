#include<iostream>
using namespace std;

class nation
{
    public: 
    virtual void show()
    {
        cout<<"\nIndia";
    }
};
class college:public nation
{
    public: 
    void show()
    {
        cout<<"\nDKTE";
    }
};

int main()
{
    college cg;
    nation nt;
    nation *p[2];

    p[0] = &cg;
    p[1] = &nt;

    p[0]->show();
    p[1]->show();
    return 0;
}