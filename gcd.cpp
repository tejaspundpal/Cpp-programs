#include<iostream>
using namespace std;

int main()
{
    int n1,n2;
    cout<<"Enter two numbers : "<<endl;
    cin>>n1>>n2;
    int smallest,largest,gcd;
    if(n1 < n2){
        smallest = n1;
        largest = n2;
    }
    else{
        smallest = n2;
        largest = n1;
    }
    smallest = abs(smallest);
    if(smallest == 0)
        {
            gcd = largest;
        }
    for (int i = 1;i <= smallest;i++)
    {
        if(n1%i==0 && n2%i==0)
        {
            gcd = i;
        }       
    } 
    cout<<"GCD = "<<gcd<<endl;   
    return 0;
}