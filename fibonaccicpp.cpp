#include <iostream>
using namespace std;

class fibonacci
{
    int n1, n2, n3, number;

public:
    fibonacci()
    {
        cout << "Enter the no. of elements = ";
        cin >> number;
    }

    ~fibonacci()
    {
        n1 = 0, n2 = 1;
        cout << n1 << " " << n2 << " ";
        for (int i = 2; i < number; ++i)
        {
            n3 = n1 + n2;
            cout << n3 << " ";
            n1 = n2;
            n2 = n3;
        }
    }
};

int main()
{
    fibonacci f;
    return 0;
}