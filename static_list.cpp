#include <iostream>
#include <cstdlib>
using namespace std;

int insert(int *array, int &lastposition, int data, int &pos, int &size)
{
    int final_pos = pos - 1;
    if (lastposition == size)
    {
        return -1;
    }
    else
    {
        if (final_pos > lastposition + 1)
        {
            return -2;
        }
        else
        {
            if (final_pos == lastposition + 1)
            {
                int n = final_pos;
                *(array + n) = data;
                lastposition = final_pos;
            }
            else
            {
                for (int i = lastposition + 1; i > final_pos; i--)
                {
                    *(array + i) = *(array + i - 1);
                }
                int m = final_pos;
                *(array + m) = data;
                lastposition = lastposition + 1;
            }
        }
    }
    return 0;
}

int deletedata(int *array,int& lastpostion,int& pos)
{
    if(lastpostion==0)
    {
        return -1;
    }
    else
    {
        if((pos)-1>(lastpostion))
        {
            return -2;
        }
        else
        {
            for(int i=pos-1;i<=lastpostion;i++)
            {
                *(array+i)=*(array+(i+1));
            }
                lastpostion=lastpostion-1;
        }
    }
    return 0;
}

int searching_data(int *array,int lastposition,int data)
{
    if(lastposition==-1)
    {
        printf("Empty list.\n");

    }
    else if(lastposition>=0)
    {
        int i;
        for(i=0;i<=lastposition;i++)
        {
             if(*(array+i)==data)
             {
                return i+1;
             }
        }
        if(i==lastposition+1)
        {
           return -1;
        }
    }
    return 0;
}

void printlist(int *array,int lastpostion,int sizeOFList)
{
    if((lastpostion)>sizeOFList)
    {
        printf("List is less than your last position.\n");
        return;
    }
    else
    {
        for(int i=0;i<=(lastpostion);i++)
        {
            printf("%d ",*(array+i));
        }
        cout<<endl;
    }
}

int main()
{
    int a[10];
    int Last_position=0;
    int List_size = 10;
    int Data;
    int pos, pos1, pos2, num, x;
    while (1)
    {
        cout << "1.Insert" << endl
             << "2.Delete" << endl
             << "3.Search" << endl
             << "4.Display" << endl
             << "5.Exit"<<endl;;
        cin >> num;
        switch (num)
        {
        case 1:
            cout << "Enter position :";
            cin >> pos;
            cout << "Enter data to insert:";
            cin >> Data;
            x = insert(a, Last_position, Data, pos, List_size);
            if (x == -1)
            {
                cout << "No Space to insert in list" << endl;
            }
            else if (x == -2)
            {
                cout << "Data can not be entered" << endl;
            }
            else if (x == 0)
            {
                cout << "data entered successfully" << endl;
            }
            break;
            case 2:
                cout<<"Enter position to delete:";
                cin>>pos1;
                x=deletedata(a, Last_position, pos1);
                if(x==-1)
                {
                    cout<<"Array is empty"<<endl;
                }
                else if(x==-2)
                {
                    cout<<"No element is present at possition"<<endl;
                }
                else if(x==0)
                {
                    cout<<"Data deleted successfully";
                }
                break;
            case 3:
                int Ldata;
                cout<<"Enter data for matching in list:";
                cin>>Ldata;
                x=searching_data(a, Last_position, Ldata);
                if(x==-1)
                {
                    cout<<"Element not found";
                }
                else
                {
                    cout<<"Element found at position "<<x<<endl;
                }
                break;
            case 4:
                printlist(a, Last_position, List_size);
                break;
            case 5:
                exit(0);
            }
        }
        return 0;
    }