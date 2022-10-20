#include<iostream>
using namespace std;

class salesman
{
    int e,w,s,n,t,a;
    float c;
    char m[20];

    public:
    void getdata()
    {
        cout<<"Name : ";
        cin>>m;
        cout<<"Sale in 4 region : ";
        cin>>e>>w>>s>>n;
        t = e + w + s + n;
        c =  t * (1.5 / 100);
        
    }
    void showsale()
    {
        cout<<"Total:"<<t<<"\tCommission:"<<c<<"\n";
    }
    friend salesman operator+(salesman ob1,salesman ob2)
    {
        salesman z;
        
        z.t=ob1.t+ob2.t;
        z.c=ob1.c+ob2.c;
        return(z);
    }
    void showname()
    {
        cout<<m<<"\t";
    }
};

int main()
{
    salesman obj1,obj2,obj3;
    obj1.getdata();
    obj2.getdata();
    obj1.showsale();
    obj2.showsale();
    obj3=operator+(obj1,obj2);      /*obj3=obj1.operator+(obj2)*/
    obj3.showsale();
    return 0;
}