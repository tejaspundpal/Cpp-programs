#include<iostream>
using namespace std;

class fibonacci
{
    int n;
    public:
    void data();
    friend void result(fibonacci);
};

void fibonacci::data()
{
    cout<<"Enter the number the elements : ";
    cin>>n;
}

void result(fibonacci f)
{
    int n1 = 0,n2 = 1,n3;
    cout<<n1<<" "<<n2<<" ";
    for(int i = 2;i < f.n;i++)
    {
        n3 = n1 + n2;
        cout<<n3<<" ";
        n1 = n2;
        n2 = n3;
    }
}

int main()
{
    fibonacci fi;
    fi.data();
    result(fi);

return 0;
}