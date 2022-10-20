#include <iostream>
using namespace std;

// void print(int *a)
// {
//     for(int i = 0; i < 5; i++)
//     {
//         cout<<a[i]<<" ";
//     }
// }

template <class T>
T print(T *p)
{
    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }
    return 0;
}


void sort(int *a)
{
    int temp;

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (a[j] < a[i])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}

void sort(float *b)
{
    float temp;

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (b[j] > b[i])
            {
                temp = b[j];
                b[j] = b[i];
                b[i] = temp;
            }
        }
    }
}

void sort(char *c)
{
    float temp;

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (c[j] < c[i])
            {
                temp = c[j];
                c[j] = c[i];
                c[i] = temp;
            }
        }
    }
}

int main()
{
    int a[5];
    float b[5];
    char c[5];

    cout << "\nEnter any five inegers : ";
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    cout<<"Integers in ascending order ---> ";
    sort(a);
    print(a);
    
    cout << "\nEnter any five float values : ";
    for (int i = 0; i < 5; i++)
    {
        cin >> b[i];
    }
    cout<<"Float values in descending order ---> ";
    sort(b);
    print(b);

    cout << "\nEnter any five characters : ";
    for (int i = 0; i < 5; i++)
    {
        cin >> c[i];
    }
    cout<<"Characters in ascending order ---> ";
    sort(c);
    print(c);
    
    return 0;
}