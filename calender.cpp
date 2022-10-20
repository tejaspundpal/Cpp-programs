#include <iostream>
using namespace std;

const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string mon[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

struct calender
{
  int date, month, year;
};

int check_leap(int year)
{

  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
  {
    // cout << year << " is a leap year." << endl;
    return 1;
  }
  else
  {
    // cout << year << " is not a leap year." << endl;
    return 0;
  }
}
int no_of_days_in_month(int month, int year)
{
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    return 31;

  if (month == 4 || month == 6 || month == 9 || month == 11)
    return 30;

  if (month == 2)
  {
    int n = check_leap(year);
    if (n == 1)
      return 29;

    else
      return 28;
  }
}

struct calender insert(calender &cl)
{
  int choice;
  cout << "Enter the year : " << endl;
  cin >> cl.year;
  int yr = cl.year;

  if (check_leap(yr))
  {
    cout << cl.year << " is a leap year." << endl;
  }
  else
  {
    cout << cl.year << " is not a leap year." << endl;
  }

  do
  {
    cout << "Enter the month no.: " << endl;
    cin >> cl.month;
    int m = cl.month;
    if (cl.month > 12 || cl.month < 0)
    {
      cout << "**** There are 12 months in every year..!! ****" << endl;
    }
  } while (cl.month > 12 || cl.month < 0);

// if(cl.month == 1 || cl.month == 3 ||cl.month == 5 ||cl.month == 7 ||cl.month == 8 ||cl.month == 10||cl.month == 12 )
//   do{
//   cout << "Enter the date : " << endl;
//   cin >> cl.date;
//   //int dt = cl.date;
//   if (cl.date > 31)
//   {
//   cout<<"**** There are 31 days in enterd month..!! ****"<<endl;
//   }
//   }while(cl.date > 31);

// else if(cl.month == 4 || cl.month == 6 ||cl.month == 9 ||cl.month == 11 )
//   do{
//   cout << "Enter the date : " << endl;
//   cin >> cl.date;

//   if (cl.date > 30)
//   {
//   cout<<"**** There are 30 days in enterd month..!! ****"<<endl;
//   }
//   }while(cl.date > 30);

// else if(cl.month == 2 && check_leap(yr) == 1)
// {
//   do{
//   cout << "Enter the date : " << endl;
//   cin >> cl.date;
//   if (cl.date > 29)
//   {
//   cout<<"**** There are max 29 days in enterd month in leap year..!! ****"<<endl;
//   }
//   }while(cl.date > 29);

// }
// else
// {
// do{
//   cout << "Enter the date : " << endl;
//   cin >> cl.date;
//   if (cl.date > 28)
//   {
//   cout<<"**** "<<cl.year<<" is not leap year snd entered month has max 28 days ..!! ****"<<endl;
//   }
//   }while(cl.date > 28);
// }
reenter:
  cout << "Enter the date : " << endl;
  cin >> cl.date;
  if (check_leap(yr) == 0 && (cl.date < 0 || cl.date > days[cl.month - 1]) || (check_leap(yr) == 1 && cl.month == 2 && (cl.date < 0 || cl.date > 29)))
  {
    cout << "You enterd the invalid date..Please check your date...!!" << endl;
    cout << "Re-enter the date...." << endl;
    goto reenter;
  }
  return cl;
}

void display(calender cl)
{
  int choice;
  cout << "\nSelect the format to display....\n1)dd-mm-yyyy\n2)dd-month-yyyy\n3)exit" << endl;
  cin >> choice;

  switch (choice)
  {
  case 1:
    cout << cl.date << "-" << cl.month << "-" << cl.year << endl;
    break;
  case 2:
    cout << cl.date << "-" << mon[cl.month - 1] << "-" << cl.year << endl;
    break;
  case 3:
    exit(0);
  default:
    cout << "Enter the valid choice...!!";
  }
}
void increment(calender cl)
{
  calender nd;
  int yr = cl.year;
  if (((cl.date > 0 && cl.date <= days[cl.month - 1]) && (cl.month > 0 && cl.month <= 12)) || (cl.date == 29 && cl.month == 2 && check_leap(yr) == 1))
  {
    if (cl.date < days[cl.month - 1])
    {
      nd.date = cl.date + 1;
      nd.month = cl.month;
      nd.year = cl.year;
    }
    else if (cl.month == 12)
    {
      nd.date = 1;
      nd.month = 1;
      nd.year = cl.year + 1;
    }
    else if (cl.date == 28 && cl.month == 2 && check_leap(yr) == 1)
    {
      nd.date = cl.date + 1;
      nd.month = cl.month;
      nd.year = cl.year;
    }
    else
    {
      nd.date = 1;
      nd.month = cl.month + 1;
      nd.year = cl.year;
    }
  }
  cout << "Next date is : " << nd.date << "-" << mon[nd.month - 1] << "-" << nd.year << endl;
}

long int difference_of_days(calender cl, calender cl2)
{
  cout << "diff date is called..." << endl;
  if (cl.year == cl2.year)
  {
    if (cl.month == cl2.month)
    {
      if (cl.date == cl2.date) // for same dates
        return 0;
      else
        return abs(cl.date - cl2.date); // for same year, same month but diff days
    }
    else if (cl.month < cl2.month)
    {
      int result = 0;
      for (int i = cl.month; i < cl2.month; i++)
        result = result + no_of_days_in_month(i, cl.year);

      if (cl.date == cl2.date) // for same year, same day but diff month
        return result;
      else if (cl.date < cl2.date)
      {
        result = result + (cl2.date - cl.date);
        return result;
      }
      else
      {
        result = result - (cl.year - cl2.date);
        return result;
      }
    }
    else
    {
      int result = 0;
      for (int i = cl2.month; i < cl.month; i++)
        result = result + no_of_days_in_month(i, cl.year);

      if (cl.date == cl2.date)
        return result;
      else if (cl2.date < cl.date)
      {
        result = result + (cl.date - cl2.date);
        return result;
      }
      else
      {
        result = result - (cl2.date - cl.date);
        return result;
      }
    }
  }
  else if (cl.year < cl2.year)
  {
    int temp = 0;
    for (int i = cl.year; i < cl2.year; i++)
    {
      if (check_leap(i))
        temp = temp + 366;
      else
        temp = temp + 365;
    }

    if (cl.month == cl2.month)
    {
      if (cl.date == cl2.date) // for same month, same day but diff year
        return temp;
      else if (cl.date < cl2.date)
        return temp + (cl2.date - cl.date);
      else
        return temp - (cl.date - cl2.date);
    }
    else if (cl.month < cl2.month)
    {
      int result = 0;
      for (int i = cl.month; i < cl2.month; i++)
        result = result + no_of_days_in_month(i, cl2.year);

      if (cl.date == cl2.date) // for same day, diff year and diff month
        return temp + result;
      else if (cl.date < cl2.date)
      {
        result = result + (cl2.date - cl.date);
        return temp + result;
      }
      else
      {
        result = result - (cl.date - cl2.date);
        return temp + result;
      }
    }
    else
    {
      int result = 0;
      for (int i = cl2.month; i < cl.month; i++)
        result = result + no_of_days_in_month(i, cl2.year);

      if (cl.date == cl2.date)
        return temp - result;
      else if (cl2.date < cl.date)
      {
        result = result + (cl.date - cl2.date);
        return temp - result;
      }
      else
      {
        result = result - (cl2.date - cl.date);
        return temp - result;
      }
    }
  }
  else
  {
    int temp = 0;
    for (int i = cl2.year; i < cl.year; i++)
    {
      if (check_leap(i))
        temp = temp + 366;
      else
        temp = temp + 365;
    }

    if (cl.month == cl2.month)
    {
      if (cl.date == cl2.date) // for same day, same month but diff year
        return temp;
      else if (cl2.date < cl.date)
        return temp + (cl.date - cl2.date);
      else
        return temp - (cl2.date - cl.date);
    }
    else if (cl2.month < cl.month)
    {
      int result = 0;
      for (int i = cl2.month; i < cl.month; i++)
        result = result + no_of_days_in_month(i, cl.year);

      if (cl.date == cl2.date)
        return temp + result;
      else if (cl2.date < cl.date)
      {
        result = result + (cl.date - cl2.date);
        return temp + result;
      }
      else
      {
        result = result - (cl2.date - cl.date);
        return temp + result;
      }
    }
    else
    {
      int result = 0;
      for (int i = cl.month; i < cl2.month; i++)
        result = result + no_of_days_in_month(i, cl.year);

      if (cl.date == cl2.date) // for same day, diff year and diff month
        return temp - result;
      else if (cl.date < cl2.date)
      {
        result = result + (cl2.date - cl.date);
        return temp - result;
      }
      else
      {
        result = result - (cl.date - cl2.date);
        return temp - result;
      }
    }
  }
}

int main()
{
  calender cl;
  calender cl2;
  long int n;
  int ch;
  char dec;

  insert(cl);
  display(cl);

  while (1)
  {
    cout << "\n1)Increment the date.\n2)Find difference between two dates.\n3)Exit." << endl;
    cout << "\nEnter choice as per your wish : ";
    cin >> ch;
    switch (ch)
    {
    case 1:

      increment(cl);
      break;

    case 2:

      insert(cl2);
      n = difference_of_days(cl, cl2);
      cout << "Differnece between dates is " << n << " days." << endl;
      break;

    case 3:
      exit(0);
      break;

    default:
      cout << "Enter the valid choice...!!";
    }
  }

  return 0;
}
