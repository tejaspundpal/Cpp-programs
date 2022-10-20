#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;
#define size 30

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
  bill(product[]);
  float getbill(product[], int);
};

bill::bill(product p[])
{
  for (int i = 0; i < size; i++)
  {
    p[i].setid(-1);
  }
}

float bill::getbill(product p[], int count)
{
  total_bill = 0;
  for (int i = 0; i < count; i++)
  {
    total_bill = total_bill + (p[i].getprice() * p[i].getquantity());
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

void display(product a[], int count)
{

  for (int i = 0; i < count; i++)
  {
    if (a[i].getid() == -1)
    {
      cout << "Your cart is empty..!";
      break;
    }
    else
    {
      // cout<<"hello";
      cout << "Item"
           << " " << i + 1 << endl;
      cout << setfill(' ') << left << setw(30) << "Id Number:" << right << " " << a[i].getid() << endl;
      cout << setfill(' ') << left << setw(30) << "Product Name:" << right << " " << a[i].getname() << endl;
      cout << setfill(' ') << left << setw(30) << "Product Price:" << right << " " << a[i].getprice() << endl;
      cout << setfill(' ') << left << setw(30) << "Product Quantity:" << right << " " << a[i].getquantity() << endl;
      cout << endl;
      cout << "--------------------------------------------------";
      cout << endl;
    }
  }
  cout << endl;
}

int main()
{
  product d[size];
  bill b(d);
  string n;
  int idno, q, p, amt, choice, ptr, count;
  char ch;
  
  cout << "1.Add Item in Cart." << endl
       << "2.Genearate Bill." << endl
       << "3.Show cart." << endl
       << "4.exit." << endl;
  cout << endl;
  while (1)
  {
    cout << "Enter your choice :";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
      count = 0;
      for (int i = 0; i < size; i++)
      {
        cout << "Enter the name of Product :";
        cin >> n;
        d[i].setname(n);

        cout << "Enter the id of product :";
        cin >> idno;
        d[i].setid(idno);

        cout << "Enter the quantity of product :";
        cin >> q;
        d[i].setquantity(q);

        cout << "Enter the price of product :";
        cin >> p;
        d[i].setprice(p);
        cout << endl;

        count++;
        cout << count << endl;
      choice:
        cout << "Enter y to add more items in cart and n for stop." << endl;
        cin >> ch;
        if (ch == 'y')
        {
          continue;
        }
        else if (ch == 'n')
        {
          break;
        }
        else
        {
          cout << "You entered the wrong letter...Enter correct letter...!!" << endl;
          goto choice;
        }
      }
      break;

    case 2:
      for (int i = 0; i < size; i++)
      {
        if (d[i].getid() == -1)
        {
          cout << "Your cart is empty..!" << endl;
          break;
        }
        else
        {
          cout << "Your Total bill is :Rs." << b.getbill(d, count) << endl;
          break;
        }
      }
      break;
    case 3:
      for (int i = 0; i < size; i++)
      {
        if (d[i].getid() == -1)
        {
          cout << "Your cart is empty..!" << endl;
          break;
        }
        else
        {
          display(d,count);
          break;
        }
      }
      break;

    case 4:
      exit(0);
    }
  }
  return 0;
}