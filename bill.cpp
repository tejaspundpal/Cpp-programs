#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
#define size 30
// ****************************************************
class product
{

  int id;
  int quantity;
  float price;
  string name;
  
public:
  
  int getid();
  int getquantity();
  float getprice();
  string getname();
  void setid(int);
  void setquantity(int);
  void setprice(float);
  void setname(string n);

};

class bill : public product
{
   float total_bill;
   public:
   float getbill(product[]);
};

float bill::getbill(product p[]) 
{
    total_bill = 0;
    for (int i = 0; i < size; i++)
  {

    total_bill += (p[i].getprice() * p[i].getquantity());

    if (size == 0)
    {
      cout << "Your list is Empty !!" << endl;
    }
  }
  
  return total_bill;
}

int product::getid()
{
  return id;
}
int product::getquantity()
{
  return quantity;
}
float product::getprice()
{
  return price;
}
string product::getname()
{

  return name;
}
void product::setid(int i)
{
  id = i;
}
void product::setquantity(int q)
{
  quantity = q;
}
void product::setprice(float p)
{
  price = p;
}
void product::setname(string n)
{
  name = n;
}

void display(product a[])
{
  int c = 0;
  for (int i = 0; i < size; i++)
  {
    if (a[i].getid() == 0)
    {
      c++;
      continue;
    }
    else if (a[i].getid() != 0)
    {
       
      cout <<"Item"<<" "<<i + 1 << endl;
      cout << setfill(' ') << left << setw(30) << "Id Number:" << right << " " << a[i].getid() << endl;
      cout << setfill(' ') << left << setw(30) << "Product Name:" << right << " " << a[i].getname() << endl;
      cout << setfill(' ') << left << setw(30) << "Product Price:" << right << " " << a[i].getprice() << endl;
      cout << setfill(' ') << left << setw(30) << "Product Quantity:" << right << " " << a[i].getquantity() << endl;
      cout<<endl;
    
    }

      cout<<endl;
  }
  if (c == size - 1)
  {
    cout << "Nothing to display,as Your cart is Empty !!" << endl;
  }
}


int main()
{
  product d[size];
  bill b;
  string n;
  int idno, q, p, amt, choice, userchoice, ptr;
  for (int i = 0; i < size; i++)
  {
    d[i].setid(0);
  }

  cout << "1.Add Item in Cart" << endl
       << "2.Genearate Bill" << endl
       << "3.display" << endl;
  cout << endl;
  while (1)
  {
    cout << "Enter your choice :";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
      for (int i = 0; i < size; i++)
      {
        cout << "Enter the name of Product :";
        cin >> n;
        cout << "Enter the id of product :";
        cin >> idno;
        cout << "Enter the quantity of product :";
        cin >> q;
        cout << "Enter the price of product :";
        cin >> p;
        cout << endl;
        d[i].setid(idno);
        d[i].setname(n);
        d[i].setprice(p);
        d[i].setquantity(q);
        cout << "Do You want add More items --> Enter 1 otherwise 2 :";
        cin >> userchoice;
        cout << endl;
        if (userchoice == 1)
        {
          continue;
        }
        else
        {
          break;
        }
      }
      break;
    case 2:
      cout << "Your Total bill is :$" << b.getbill(d) << endl;
      break;
    case 3:
      display(d);
      break;
    }
  }
  return 0;
}
