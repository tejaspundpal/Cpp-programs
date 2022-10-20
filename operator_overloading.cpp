#include<iostream>
using namespace std;

class matrix
{
    int x[3][3],r,c;
    public:
    void operator+()
    {
        cout<<"Enter matrix numbers : ";
        for(r = 0; r <= 2; r++)
        {
            for(c = 0; c <= 2; c++)
            {
                cin>>x[r][c];
            }
        }
    }
    
    void operator*()
    {
        cout<<"matrix : "<<endl;
        for(r = 0; r <= 2; r++)
        {
            for(c = 0; c <= 2; c++)
            {
                cout<<x[r][c]<<"\t";
            }
            cout<<endl;
        }
    }

    void operator-()
    {
        cout<<"Transpose : "<<endl;
        for(r = 0; r <= 2; r++)
        {
            for(c = 0; c <= 2; c++)
            {
                cout<<x[c][r]<<"\t";
            }
            cout<<endl;
        }
    }
};
int main()
{
    matrix mx;
    +mx;
    *mx;
    -mx;
    
    return 0;
}