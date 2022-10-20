#include<iostream>
using namespace std;

class item
{
    public:
    int itemno,avqn;
    float price;

    void data()
    {
        cout<<"Enter the item number : ";
        cin>>itemno;
        cout<<"Enter the available quantity : ";
        cin>>avqn;
        cout<<"Enter the price of item : ";
        cin>>price;
    }
};

class sale:public virtual item
{
    public:
    int saleqn;

    void saledata()
    {
        cout<<"Enter the sale quantity : ";
        cin>>saleqn;
    }
};

class purchase: public virtual item
{
    public: 
    int purqn;

    void purdata()
    {
        cout<<"Enter the purchase quntity : ";
        cin>>purqn;
    }
};

class stock: public purchase,public sale
{
    int total;
    float saleprice,purprice;
public:
    void totalqn()
    {
        total = avqn - saleqn + purqn;
        saleprice = saleqn * price;
        purprice = purqn * price;

        cout<<"\nTotal quantity is : "<<total;
        cout<<"\nsale quantity price is : "<<saleprice;
        cout<<"\npurchase quantity price is : "<<purprice<<endl;
    }
};

int main()
{
   stock st;
   st.data();
   st.saledata();
   st.purdata();
   st.totalqn();

   return 0;
}









