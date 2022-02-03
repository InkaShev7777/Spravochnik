#include <iostream>
#include"c_Spravochnik.h"
#include"Col_Spravochnik.h"
using namespace std;
int main()
{
	c_Spravochnik* sp;
	Col_Spravochnik col;
	
	
	/*col.SerchByName("Tem");
	col.Writh();*/
	int choice;
	string name_firm;
	string owner_name;
	string phone;
	string address;
	string ocupation;
	do
	{
		cout << "\t\tMenu\n";
		cout << "1 - Add\n";
		cout << "2 - Shoow all list\n";
		cout << "3 - Write in file\n";
		cout << "4 - Dell company\n";
		cout << "5 - Reading file\n";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Enter name firm: ";
			cin>>name_firm;
			cout << "Enter owner name: ";
			cin >> owner_name;
			cout << "Enter phone number: ";
			cin >> phone;
			cout << "Enter address: ";
			cin >> address;
			cout << "Enter ocupation: ";
			cin >> ocupation;
			sp = new c_Spravochnik(name_firm, owner_name, phone, address, ocupation);
			col.Add(sp);
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			col.Shoow();
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			col.Writh();
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "Enter name firm: ";
			cin >> name_firm;
			col.Dell(name_firm);
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			col.Reading();
			system("pause");
			system("cls");
			break;
		}
	} while (choice != 0);
	
}

