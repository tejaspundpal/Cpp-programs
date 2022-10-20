#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

class product
{

  int id;
  string name;
  float gst;
  float discount;
  float price;
  int stock;

public:
  int getid();
  float getprice();
  string getname();
  float getgst();
  float getdiscount();
  int getstock();
  void setid(int);
  void setgst(float);
  void setprice(float);
  void setname(string n);
  void setdiscount(float);
  void setstock(int);
  void viewproduct();
  product();
};

product::product()
{
  id = 0;
  name = "nothing";
  price = 0;
  gst = 0;
  discount = 0;
  stock = 0;
}

int product::getid()
{
  return id;
}

float product::getprice()
{
  return price;
}
string product::getname()
{

  return name;
}

float product::getgst()
{
  return gst;
}

float product::getdiscount()
{
  return discount;
}

int product::getstock()
{
  return stock;
}

void product::setid(int i)
{
  id = i;
}

void product::setgst(float g)
{
  gst = g;
}

void product::setprice(float p)
{
  price = p;
}

void product::setname(string n)
{
  name = n;
}

void product::setdiscount(float d)
{
  discount = d;
}

void product::setstock(int st)
{
  stock = st;
}

void product::viewproduct()
{
  cout << endl;
  cout << setfill(' ') << left << setw(30) << "Product id:" << right << " " << getid() << endl;
  cout << setfill(' ') << left << setw(30) << "Product Name:" << right << " " << getname() << endl;
  cout << setfill(' ') << left << setw(30) << "Product Price:" << right << " " << getprice() << endl;
  cout << setfill(' ') << left << setw(30) << "GST on product:" << right << " " << getgst() << endl;
  cout << setfill(' ') << left << setw(30) << "Product discount:" << right << " " << getdiscount() << endl;
  cout << setfill(' ') << left << setw(30) << "Product stock:" << right << " " << getstock() << endl;
}

class purchase_product : public product
{
  int quantity;

public:
  int getquantity();
  void setquantity(int);
  float calgst();
  float caldiscount();
  float calprice();
};

int purchase_product::getquantity()
{
  return quantity;
}

void purchase_product::setquantity(int q)
{
  quantity = q;
}

float purchase_product::calgst()
{
  float gstprice;
  gstprice = product::getprice() * ((product::getgst()) / 100.0) * quantity;
  return gstprice;
}

float purchase_product::caldiscount()
{
  float discountprice;
  discountprice = product::getprice() * (product::getdiscount() / 100.0) * quantity;
  return discountprice;
}

float purchase_product::calprice()
{
  float totalprice;
  totalprice = (product::getprice() * quantity) + calgst() - caldiscount();
  return totalprice;
}

class node
{
public:
  purchase_product *pd;
  node *next;
  // node(purchase_product*);
};

// node::node(purchase_product *pd){
// 	this->pd = pd;
// 	next = NULL;
// }

class Linklist
{

public:
  node *head;
  Linklist();
  int insertnode(purchase_product *);
  node *gethead();
  void Display();
  void Deletenode();
};

node *Linklist ::gethead()
{
  return head;
}

Linklist ::Linklist()
{
  head = NULL;
}

int Linklist::insertnode(purchase_product *pd)
{
  node *temp, *ptr;
  temp = new node;
  temp->next = NULL;

  if (head == NULL)
  {
    temp->pd = pd;
    head = temp;
    return 0;
  }

  ptr = head;
  temp->pd = pd;

  while (ptr->next != NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = temp;
}

void Linklist::Deletenode()
{
  node *temp;
  node *pre, *con;
  con = head;
  if (head->next == NULL)
  {
    head = NULL;
  }
  else
  {
    while (con->next != NULL)
    {
      pre = con;
      con = con->next;
    }
    pre->next = NULL;
    temp = con;
    delete con;
  }
}

void Linklist::Display()
{
  if (head == NULL)
  {
    cout << "List is empty" << endl;
  }
  else
  {
    cout << "---------------------------" << left << "" << setw(15) << left << "PRODUCT DETAIL"
         << "---------------------------" << endl;
    cout << setw(10) << left << "ID" << setw(10) << left << "NAME" << setw(10) << left << "PRICE" << setw(10) << left << "GST" << setw(10) << left << "STOCK" << setw(10) << left << "DISCOUNT" << endl;
    cout << setw(69) << endl;
    node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
      ptr->pd->viewproduct();
      cout << setw(10) << left << ptr->pd->getprice() << endl;
      ptr = ptr->next;
    }
  }
}

class Cart : protected Linklist
{
  float gsttotal = 0.0, discounttotal = 0.0, pricetotal = 0.0;
  node *n;

public:
  void AddProduct(purchase_product *);
  void RemoveProduct();
  void viewCart();
  void GenerateBill();
  void DisplayBill();
};

void Cart::AddProduct(purchase_product *pd)
{
  insertnode(pd);
}
void Cart::RemoveProduct()
{
  Deletenode();
}

void Cart::viewCart()
{
  Display();
}

void Cart::GenerateBill()
{
  cout << "In Generate Bill";
  if (head == NULL)
  {
    cout << "List is empty" << endl;
  }
  else
  {

    node *ptr;
    ptr = head;

    while (ptr != NULL)
    {
      cout << ptr->pd->getid();
      gsttotal = gsttotal + ((ptr->pd->getquantity() * ptr->pd->getprice()) * (ptr->pd->getgst() / 100));
      discounttotal = discounttotal + ((ptr->pd->getquantity() * ptr->pd->getprice()) * (ptr->pd->getdiscount() / 100));
      pricetotal = pricetotal + ((ptr->pd->getquantity() * ptr->pd->getprice()));
      ptr = ptr->next;
    }
  }
}

void Cart::DisplayBill()
{
  n = gethead();
  if (n == NULL)
  {
    cout << "List is empty" << endl;
  }
  else
  {
    cout << "-------------------------------------" << left << "" << setw(15) << left << "PRODUCT DETAIL"
         << "-------------------------------------" << endl;
    cout << setw(10) << left << "ID" << setw(10) << left << "NAME" << setw(10) << left << "PRICE" << setw(10) << left << "GST" << setw(10) << left << "STOCK" << setw(10) << left << "DISCOUNT" << setw(10) << left << "QUANTITY" << setw(10) << left << "FINAL PRICE" << endl;
    cout << setw(69) << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    node *ptr;
    ptr = n;
    while (ptr != NULL)
    {
      ptr->pd->viewproduct();
      cout << setw(10) << right << ptr->pd->getquantity() << setw(10) << right << (ptr->pd->getprice() * ptr->pd->getquantity()) << endl;
      ptr = ptr->next;
    }
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "                                                            " << setw(15) << right << "TOTAL = " << setw(6) << right << pricetotal << endl;
    cout << "                                                            " << setw(15) << right << "GST = " << setw(6) << right << gsttotal << endl;
    cout << "                                                            " << setw(15) << right << "DISCOUNT = " << setw(6) << right << discounttotal << endl;
    cout << "                                                            " << setw(15) << right << "FINAL BILL = " << setw(6) << right << ((pricetotal + gsttotal) - discounttotal) << endl;
  }
}

int main()
{
  int id, stock, quantity, choice;
  float gst, discount, price;
  string name;
  purchase_product *pd;
  Cart c;

  while (1)
  {
    cout << "1.Add Item in Cart." << endl
         << "2.Delete item from cart." << endl
         << "3.Show cart." << endl
         << "4.Generate bill." << endl
         << "5.Exit." << endl;
    cout << endl;

    cout << "Enter your choice :";
    cin >> choice;
    cout << endl;
    switch (choice)
    {

    case 1:

      pd = new purchase_product;
      cout << "Enter the product id : ";
      cin >> id;
      pd->setid(id);
      cout << "Enter the product name : ";
      cin >> name;
      pd->setname(name);
      cout << "Enter the product price : ";
      cin >> price;
      pd->setprice(price);
      cout << "Enter the GST in percentage on product : ";
      cin >> gst;
      pd->setgst(gst);
      cout << "Enter the discount in percentage on product : ";
      cin >> discount;
      pd->setdiscount(discount);
      cout << "Enter the stock of product : ";
      cin >> stock;
      pd->setstock(stock);
      cout << "Enter the quantity of product : ";
      cin >> quantity;
      pd->setquantity(quantity);

      pd->viewproduct();
      cout << "Quantity of product is " << pd->getquantity() << endl;
      cout << "GST price on product is " << pd->calgst() << endl;
      cout << "Discount on product is " << pd->caldiscount() << endl;
      cout << "Total price on product is " << pd->calprice() << endl;
      cout << endl;
      break;

    case 2:

      c.RemoveProduct();
      break;

    case 3:

      c.viewCart();
      break;

    case 4:

      c.GenerateBill();
      c.DisplayBill();
      break;

    case 5:
      exit(0);

    default:

      cout << "\nInvalid choice...!!" << endl;
      cout << endl;
    }
  }

  return 0;
}
