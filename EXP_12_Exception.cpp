#include <iostream>
using namespace std;

class date
{
private:
    int d;
    int m;
    int y;

public:
    date()
    {
        d = 0;
        m = 0;
        y = 0;
    }
    void setdate(int d, int m, int y)
    {
        try
        {
            if (d > 31 || d < 0)
            {
                throw(d);
            }
            else if (m > 12)
            {
                throw(m);
            }
            else
            {
                this->d = d;
                this->m = m;
                this->y = y;
                cout<<"YOUR date is "<<d<<" :"<<m<<" :"<<y<<endl;
            }
        }
        catch (int x)
        {
            cout << "oops Enter a valid date " << endl;
        }
    }
};

int main()
{
         date ptr;
         ptr.setdate(22,33,2345);
    return 0;
}