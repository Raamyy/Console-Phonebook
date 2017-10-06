#include"Header.h"
int main()
{
	int decide;


	welcome();
    getContactFromFileonStart();
	firstInput();


NewEntry:
	PrintContacts();

	cout << "Press 1 to add a new contact, \nor press 2 to make operations on existing contacts," << endl << "any thing else will exit the program." << endl;
	cin >> decide;
	if (decide == 1)
	{
		AddContact();
	}
	else if (decide == 2)
	{
		cout << "Press 1 to search by index or press 2 to search by name\n";
		cin >> decide;
		if (decide == 1)
		{
			SearchByIndex();
		}
		else if (decide == 2)
		{
			SearchByName();

		}
		cout << "Press 1 to edit it\n" << "press 2 to delete it.\n";
		cin >> decide;
		if (decide == 1)
		{
			EditName();
		}
		else if (decide == 2)
		{
			DeleteName();
		}
		else
		{
			cout << "Wrong decision !\n";
			goto NewEntry;
		}
	}
	else
	{
		exit();
		return 0;
	}

	PrintContacts();
	cout << endl << "If you want to continue press 1 any thing else will exit the program.\n";
	cin >> decide;
	if (decide == 1)
		goto NewEntry;
	else
	{
		exit();
		return 0;
	}
	return 0;
}
