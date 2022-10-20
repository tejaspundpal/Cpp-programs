#include<iostream>
using namespace std;

class complex
{
   int real,img;

public:
   complex();
   void getvalue();
   void showvalue();
   complex operator+(complex);
   void operator++();
   void operator++(int);
};

complex::complex()
{
   real = 0;
   img = 0;
}

void complex::getvalue()
{
   cout<<"Enter the real part of comlex no. : "<<endl;
   cin>>real;
   cout<<"Enter the imaginary part of comlex no. : "<<endl;
   cin>>img;
}

void complex::showvalue()
{
   cout<<real<<" + "<<img<<" i "<<endl;
}

void complex::operator++()
{
  real = real + 1;
  img = img + 1;
}

void complex::operator++(int i)
{
  real = real + 1;
  img = img + 1;
}

complex complex::operator+(complex c2)
{
  complex c3;
  c3.real = real + c2.real;
  c3.img = img + c2.img;

  return c3;
}

int main()
{
   complex c1,c2,c3;
  
   cout<<endl;
   cout<<"Enter info of 1st complex number..."<<endl;
   c1.getvalue();
   cout<<endl;
   cout<<"Enter info of 2nd complex number... "<<endl;
   c2.getvalue();
   
   cout<<"1st complex no is : "<<endl;
   c1.showvalue();
   cout<<"1st complex no is : "<<endl;
   c2.showvalue();    
  
   c3 = c1 + c2;
  
   cout<<"Addition of complex no is : "<<endl;
   c3.showvalue(); 

   cout<<"Increment of 1st complex no : ";
   c1++;

   c1.showvalue();

   cout<<"Increment of 1st complex no : ";
   ++c1;

   c1.showvalue();

  return 0;
}










