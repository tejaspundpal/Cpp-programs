#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
    char para[1000];
    fstream fs;
    int ch = 0,word = 0;

    fs.open("sample.txt",ios::out);
    cout<<"Enter string : "<<endl;
    gets(para);
    fs<<para;
    fs.close();

    while(fs)
    {
        fs.open("sample.txt",ios::in);
        while(!fs.eof())
        {
          for(int i = 0;para[i]!='\0';i++)
          {
              if(para[i] == ' ' || para[i] != '\n' )
              word++;
          }
        }
    }
    cout<<word<<endl;
    fs.close();
    return 0;
}