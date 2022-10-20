#include <iostream>
#include <cstdlib>
using namespace std;

class node
{
public:
	int data;
	node *next;
};

class Linklist
{
private:
	node *head;

public:
	Linklist();
	void insertatbeg(int);
	void insertatend(int);
	void display();
	node *deleteatbeg();
	int deleteatend();
};

Linklist ::Linklist()
{
	head = NULL;
}

void Linklist::insertatbeg(int data)
{
	node *temp;
	temp = new node;
	temp->data = data;
	temp->next = head;
	head = temp;
}

void Linklist::display()
{
	node *ptr;
	ptr = head;
	while (ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

void Linklist::insertatend(int data)
{
	node *ptr, *temp;
	ptr = new node;
	ptr->data = data;
	ptr->next = NULL;
	if (head == NULL)
	{
		head = ptr;
		return;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
	}
	temp->next = ptr;
}

node *Linklist::deleteatbeg()
{
	node *temp;

	if (head = NULL)
	{
		cout << "list is empty" << endl;
	}
	else
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	return temp;
}

int Linklist::deleteatend()
{
	node *ptr, *prev;
	if (head == NULL)
	{
		cout << "list is empty" << endl;
	}
	else
	{
		if (head->next = NULL)
		{
			ptr = head;
			head = NULL;
			delete(ptr);
		}
		else
		{
			ptr = head;
			while (ptr->next != NULL)
			{
				prev = ptr;
				ptr = ptr->next;
			}
		}
		prev->next = NULL;
		delete(ptr);
	}
}

int main()
{
	int choice, p, q;
	Linklist l1;
	cout << "insertatbeg" << endl;
	cout << "insertatend" << endl;
	cout << "display" << endl;
	cout << "deleteatbeg" << endl;
	cout << "deleteatend" << endl;
	while (1)
	{
		cout << "enter a choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "ENTER a element" << endl;
			cin >> p;
			l1.insertatbeg(p);
			break;

		case 2:
			cout << "ENTER ELEMENT" << endl;
			cin >> p;
			l1.insertatend(p);
			break;

		case 3:
			l1.display();
			cout << endl;
			break;

		case 4:
			l1.deleteatend();
			break;

		case 5:
			l1.deleteatbeg();
			break;

		case 6:
			exit(0);
			break;

		default:
			cout << "not found" << endl;
			break;
		}
	}
}
