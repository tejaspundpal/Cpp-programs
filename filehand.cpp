#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
using namespace std;

class cricket
{
    char pnm[20], dec, snm[20],dnm[20];
    int runs, inns;
    float avg;
    fstream fs;

public:
    void playdata()
    {
        fs.open("play.dat", ios::out);
        do
        {
            cout << "Enter name,runs and innings : ";
            cin >> pnm >> runs >> inns;
            fs << pnm << "\t" << runs << "\t" << inns << endl;
            cout << "Repeat?";
            cin >> dec;
        } while (dec == 'y');
        fs.close();
    }
    void showavg()
    {
        fs.open("play.dat", ios::in);
        while (fs)
        {
            fs >> pnm >> runs >> inns;
            if (fs.eof() == 0)
            {
                avg = (float)(runs / inns);
                cout << pnm << "\t" << avg << endl;
            }
        }
        fs.close();
    }
    void search()
    {
        fs.open("play.dat", ios::in);
        cout << "enter name to search ";
        cin >> snm;
        while (fs)
        {
            fs >> pnm >> runs >> inns;
            if (fs.eof() == 0)
            {
                if (strcmp(snm, pnm) == 0)
                {
                    avg = (float)(runs / inns);
                    cout << pnm << "\t" << avg << endl;
                }
            }
        }
        fs.close();
    }

    void delinfo()
    {
        fstream tmp;
        fs.open("play.dat", ios::in);
        tmp.open("temp.dat", ios::out);
        cout << "enter name to delete ";
        cin >> dnm;
        while (fs)
        {
            fs >> pnm >> runs >> inns;
            if (fs.eof() == 0)
            {
                if (strcmp(dnm, pnm) != 0)
                {
                    tmp <<pnm<<"\t"<<avg<<endl;
                }
            }
        }
        fs.close();
        tmp.close();
        remove("play.dat");
        rename("temp.dat", "play.dat");
    }
};
int main()
{
    cricket ct;
    int choice;

    cout<<"1)Calculate\n2)Display\n3)Search\n4)Delete"<<endl;
    while(1)
    {
        cout<<"Enter your choice : "<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
                ct.playdata();
                break;

            case 2:
                ct.showavg();
                break;

            case 3:
                ct.search();
                break;

            case 4:
                ct.delinfo();
                break;

            case 5:
                exit(0);
                break;

            default:
                cout<<"Enter the valid choice...!!";
   
        }
    }


    return 0;
}