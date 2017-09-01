#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<windows.h>
using namespace std;

vector<string>contacts;
map <string, int>m;
int i;
string s;


void wait()
{
	for (unsigned long long i = 0; i<1e8; i++);

}

void SetColor(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

void space(int x)
{

	for (int i = 0; i<x; i++)
		cout << " ";
}

void welcome()
{
	for (int i = 2; i < 7; i++)
	{
		if (i == 4)
			continue;

		SetColor(i);

		space(15);
		cout << "Welcome to the mobile phone book application" << endl;
		space(15);
		cout << "********************************************" << endl;
		cout << "Enter contact names and enter the word done to continue when finished.\n(case sesitive)" << endl;
		cout << "______________________________________________________________________________" << endl;
		wait();
		system("CLS");

	}
	SetColor(7);


	space(15);
	cout << "Welcome to the mobile phone book application" << endl;
	space(15);
	cout << "********************************************" << endl;
	cout << "Enter contact names and enter the word done to continue when finished.\n(case sesitive)" << endl;
	cout << "______________________________________________________________________________" << endl;


}
void firstInput()
{


	while (true)
	{
		getline(cin, s);
		if (s == "done")
			break;
		if (m[s] > 0)
		{
			SetColor(4);
			cout << "This name was entered before please enter another one\n";
			SetColor(7);
			continue;
		}
		contacts.push_back(s);
		m[s]++;


	}
	cout << endl;
}

void PrintContacts()
{
	system("cls");
	cout << "Your contacts are : " << endl;
	cout << "--------------------- " << endl;
	sort(contacts.begin(), contacts.end());
	for (int i = 0; i<contacts.size(); i++)
	{
		cout << i + 1 << "- " << contacts[i] << endl;
	}

	cout << "_____________________________ " << endl;
}

void PrintfContacts()
{
	system("cls");
	cout << "Your final contacts are : " << endl;
	cout << "------------------------------ " << endl;
	sort(contacts.begin(), contacts.end());
	for (int i = 0; i<contacts.size(); i++)
	{
		cout << i + 1 << "- " << contacts[i] << endl;
	}

	cout << "_____________________________ " << endl;
}
void exit()
{

	for (int i = 2; i < 7; i++)
	{
		if (i == 4)
			continue;
		SetColor(i);
		PrintfContacts();
		cout << endl << endl;
		cout << "\t\t*********************************" << endl;
		cout << "\t\t*Thanks for using my application*" << endl;
		cout << "\t\t*********************************" << endl;
		cout << endl;
		wait();
		system("CLS");
	}
	SetColor(7);

	PrintfContacts();

	cout << endl << endl;
	cout << "\t\t*********************************" << endl;
	cout << "\t\t*Thanks for using my application*" << endl;
	cout << "\t\t*********************************" << endl;
	cout << endl;


}
void AddContact()
{
	cin.ignore();
	while (1)
	{
		cout << "Enter the name of the new contact\n";
		getline(cin, s);
		if (m[s] > 0)
		{
			SetColor(4);
			cout << "This name was entered before please enter another one\n";
			SetColor(7);
			continue;
		}

		contacts.push_back(s);
		m[s]++;
		break;
	}
}

void SearchByIndex()
{
	cout << "Enter the index number of the contact you want to make operation on \n";
	cin >> i;

	while (i > contacts.size() || i == 0)
	{
		SetColor(4);
		cout << "Wrong index !\n";
		SetColor(7);
		cout << "Please enter another right index\n";
		cin >> i;
	}
	cout << endl;
}

void SearchByName()
{
	cout << "Enter the name (case senstive)\n";
	cin.ignore();
Name:
	getline(cin, s);
	for (int j = 0; j < contacts.size(); j++)
	{
		//cout << "s " << s << " " << contacts[j] << endl;
		if (contacts[j] == s)
		{
			i = j + 1;
			//cout << "entered";
			break;
		}

		if (j == contacts.size() - 1)

		{
			SetColor(4);
			cout << "Name not found ! \n";
			SetColor(7);
			cout << "Please enter another name \n";
			goto Name;
		}


	}
}
void EditName()
{
	cout << "Enter the other name of " << contacts[i - 1] << endl;
	m[contacts[i - 1]] = 0;
	cin.ignore();
entername:
	getline(cin, s);
	if (m[s] > 0)
	{
		SetColor(4);
		cout << "this contact was entered before !\nPlease enter other name\n";
		SetColor(7);
		goto entername;

	}
	m[s]++;
	contacts[i - 1] = s;
}

void DeleteName()
{
	m[contacts[i - 1]] = 0;
	cout << "Contact " << contacts[i - 1] << " deleted.\n ";
	contacts.erase(contacts.begin() + i - 1);
}

