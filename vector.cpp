#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    vector<int> v; //create vector of type int
    cout<<"Initial size = "<<v.size()<<"\n";

    int x;
    cout<<"Enter 5 integer values : "<<endl;
    for(int i = 0;i < 5;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cout<<"size after adding 5 values : "<<endl;
    cout<<v.size()<<"\n";

    cout<<"current contents : "<<endl;
    display(v);

    //add one more value
    v.push_back(6.6);

    cout<<"\nsize = "<<v.size()<<endl;
    cout<<"contents now : "<<endl;
    display(v);

    //inserting elements
    vector<int>::iterator itr = v.begin();
    itr = itr + 3;
    v.insert(itr,1,9);

    cout<<"\ncontents after inserting : "<<endl;
    display(v);

    //removing 4th and 5th element
    v.erase(v.begin()+ 3,v.begin()+5);

    cout<<"contents after deletion: "<<endl;
    display(v);
    cout<<"END"<<endl;

    return 0;
}