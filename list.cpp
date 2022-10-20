#include<iostream>
#include<list>
#include<cstdlib>//for using rand() fn
using namespace std;

void display(list <int> &lst)
{
    list <int>::iterator p;
    for(p = lst.begin();p != lst.end();p++)
    {
        cout<<*p<<" ";
        
    }
}

int main()
{
    list<int>list1;//empty list of zero length
    list<int>list2(5);//empty list of size 5

    for(int i = 0;i<3;i++)
    list1.push_back(rand()/100);

    list<int>::iterator p;
    for(p = list2.begin();p!= list2.end();p++)
    *p = rand()/100;

    cout<<"\nlist 1 : "<<endl;
    display(list1);
    cout<<"\nlist 2 : "<<endl;
    display(list2);

    //add 2 elements at end of list1
    list1.push_front(100);
    list1.push_back(200);

    //remove an element at the front of list 2
    list2.pop_front();

    cout<<"\nnow list 1 : "<<endl;
    display(list1);
    cout<<"\nnow list 2 : "<<endl;
    display(list2);

    list<int>listA,listB;
    listA = list1;
    listB = list2;

    //merging two lists(unsorted)
    list1.merge(list2);
    cout<<"\nmerged unsorted list : "<<endl;
    display(list1);

    //sorting and merging

    listA.sort();
    listB.sort();
    listA.merge(listB);
    cout<<"\nmerged sorted list : "<<endl;
    display(listA);

    //reversing list
    listA.reverse();
    cout<<"\nreversed merged list : "<<endl;
    display(listA);
    
    return 0;
}