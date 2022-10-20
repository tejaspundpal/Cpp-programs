#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
    ifstream fin1, fin2;
    ofstream fout1,fout2,fout3;
    char ch, file_name1[20], file_name2[20], file_name3[30];
    string para1,para2;
    
    cout << "\n Enter First File Name with Extension '.txt'    :   ";
    gets(file_name1);
    cout << "\n Enter Second File Name with Extension '.txt'   :   ";
    gets(file_name2);
    cout << "\n Enter Third File Name with Extension '.txt' ";
    gets(file_name3);

    // fout3.open(file_name3);
    // cout<<file_name3<<"is created."<<endl;
     
    fout1.open(file_name1);
    cout<<"Enter text for file 1 : "<<endl;
    getline(cin,para1);
    fout1<<para1;

    fout2.open(file_name2);
    cout<<"Enter text for file 2 : "<<endl;
    getline(cin,para2);
    fout2<<para2;
    
    fout1.close();
    fout2.close();

    fin1.open(file_name1);
    fin2.open(file_name2);
    if (!fin1 || !fin2)
    {
        cout << "\n Invalid File Name. \n There is no such File or Directory ...";
        exit(EXIT_FAILURE);
    }
    fout3.open(file_name3);
    if (!fout3)
    {
        cout << "\n Invalid File Name. \n There is no such File or Directory ...";
        exit(EXIT_FAILURE);
    }
    while (fin1.eof() == 0)
    {
        fin1 >> ch;
        fout3 << ch;
    }
    while (fin2.eof() == 0)
    {
        fin2 >> ch;
        fout3 << ch;
    }
    cout << "\n Two Files have been Merged into " << file_name3 << " File Successfully...!!!";
    //In output there is small error i.e last letter of both f1 and f2 files are printing two times...
    fin1.close();
    fin2.close();
    fout3.close();
    return 0;
}