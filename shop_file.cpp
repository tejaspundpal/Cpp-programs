#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

class shop
{
  int item_id, avl_qnt, sale_qnt;
  // string item_name;
  float price, sale_amt;
  char item_name[20], snm[20], dec;
  fstream fs;

public:
  void data();
  void display();
  void search();
};
void shop::data()
{
  fs.open("shop.txt", ios::out);
  do
  {
    cout << "Enter the item ID : ";
    cin >> item_id;
    cout << "Enter name of the item : ";
    // getline(cin,item_name);
    cin >> item_name;
    cout << "Enter the item price : ";
    cin >> price;
    cout << "Enter the available quantity of the item : ";
    cin >> avl_qnt;
    fs << item_id << "\t" << item_name << "\t" << price << "\t" << avl_qnt << endl;
    cout << "Enter y if you want to repeate..?" << endl;
    cin >> dec;
    cout << endl;
  } while (dec == 'y');
  fs.close();
}
void shop::display()
{
  fs.open("shop.txt", ios::in);
  while (fs)
  {
    fs >> item_id >> item_name >> price >> avl_qnt;
    if (fs.eof() == 0)
    {
      cout << item_id << "\t" << item_name << "\t" << price << "\t" << avl_qnt << endl;
    }
  }
  fs.close();
}
void shop::search()
{
  fs.open("shop.txt", ios::in);
  cout << "Enter name to search : ";
  cin >> snm;
  while (fs)
  {
    fs >> item_id >> item_name >> price >> avl_qnt;
    if (fs.eof() == 0)
    {
      if (strcmp(snm, item_name) == 0)
      {
        cout << item_id << "\t" << item_name << "\t" << price << "\t" << avl_qnt << endl;
      }
    }
  }
  fs.close();
}
int main()
{
  shop s;
  s.data();
  s.display();
  s.search();
  return 0;
}