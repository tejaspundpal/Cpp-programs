#include <iostream>
using namespace std;

class emp
{
    char n[15];
    int bs;

public:
    void data();
    friend float showdata(emp);
};

void emp::data()
{
    cout << "Enter name and basic salary : ";
    cin >> n >> bs;
}

float showdata(emp z)
{
    float da;
    da = z.bs * 0.85;
    return (da);
}
int main()
{
    emp k;
    k.data();
    cout << "DA is " << showdata(k);
    return 0;
}