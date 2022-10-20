#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

int main()
{
char str[200];
int i, line, word, ch;
line=word=ch=0;

cout<<"Enter a string in multiple lines :\n";
cin>>str;

//To count lines in text
for(i=0; str[i]!='\0'; i++)
{
if(str[i]=='\n')
{
line++;
word++;
}
else
{
if(str[i]==' '||str[i]=='\t')
{
word++;
ch++;
}
else ch++;
}
}

cout<<"\nCharacter counts = "<<ch;
cout<<"\nWord counts = "<<word;
cout<<"\nLine counts = "<<line;


 }