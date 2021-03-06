#include "Shop.h"


Shop::Shop()
{
	int choice;

	while(1)
	{
		cout << "\n1. Create Component\n2. Create Model\n3. List Components\n4. List Models\n5. Add Customer\n6. List Customers\n7. Add Employee\n8. List Employees\n9. Save Shop\n10. Exit\n\nChoice: ";
		cin >> choice;
		cin.ignore();

		switch(choice - 1)
		{
			case 0:
			{
				mCreate_Component();
				break;
			}
			case 1:
			{
				mCreate_Model();
				break;
			}
			case 2:
			{
				mList_Components();
				break;
			}
			case 3:
			{
				mList_Models();
				break;
			}
			case 4:
			{
				mAdd_Customer();
				break;
			}
			case 5:
			{
				mList_Customers();
				break;
			}
			case 6:
			{
				mAdd_Employee();
				break;
			}
			case 7:
			{
				mList_Employees();
				break;
			}
			case 8:
			{
				mSave_Shop();
				break;
			}
			case 9:
			{
				cout << "Goodbye.\n";
				exit(0);
				break;
			}
		}
	}
}

void Shop::mCreate_Component()
{
	Component component;
	vComponent.push_back(component);
}

void Shop::mCreate_Model()
{
	string name;
	int model_number;
	int price;

	cout << "Model Name: ";
	getline(cin, name);

	cout << "Model Number: ";
	cin >> model_number;
	cin.ignore();

	cout << "Model Price: ";
	cin >> price;
	cin.ignore();

	Model model(name, model_number, price);
	vModel.push_back(model);
	cout << "\nModel Created.\n";
}

void Shop::mList_Components()
{
	for(int i = 0; i < vComponent.size(); i++)
	{
		cout << vComponent[i].mComponent_Info();
	}
}

void Shop::mList_Models()
{
	for(int i = 0; i < vModel.size(); i++)
	{
		cout << vModel[i].mModel_Info();
	}
}

void Shop::mAdd_Customer()
{
	std::string name;
	std::string phone;
	std::string email;

	cout << "Customer Name: ";
	getline(cin, name);

	cout << "Customer Phone Number: ";
	getline(cin, phone);

	cout << "Customer Email: ";
	getline(cin, email);

	Customer customer(name, phone, email);
	vCustomer.push_back(customer);
	cout << "\nCustomer Created.\n";
}

void Shop::mList_Customers()
{
	for(int i = 0; i < vCustomer.size(); i++)
	{
		cout << vCustomer[i].mCustomer_Info();
	}
}

void Shop::mAdd_Employee()
{
	std::string name;
	std::string number;

	cout << "Employee Name: ";
	getline(cin, name);

	cout << "Employee Number: ";
	getline(cin, number);

	Employee employee(name, number);
	vEmployee.push_back(employee);
	cout << "\nEmployee Created.\n";
}

void Shop::mList_Employees()
{
	for(int i = 0; i < vEmployee.size(); i++)
	{
		cout << vEmployee[i].mEmployee_Info();
	}
}

void Shop::mSave_Shop()
{
	std::string file;
	int i, j;

	cout << "Save file name: ";
	getline(cin, file);
	std::filebuf fb;
	fb.open(file, std::ios::out);
	std::ostream ost(&fb);

	for(i = 0; i < vComponent.size(); i++)	// for each component object on the vector
	{
		for(j = 0; j < vComponent[i].vArm.size(); j++)	//for each part of the a single component object	ARM
		{
			vComponent[i].vArm[j].mSave(ost);	// access its save function
		}
		for(j = 0; j < vComponent[i].vBatteries.size(); j++)	//BATTERIES
		{
			vComponent[i].vBatteries[j].mSave(ost);
		}
		for(j = 0; j < vComponent[i].vHead.size(); j++)			//HEAD
		{
			vComponent[i].vHead[j].mSave(ost);
		}
		for(j = 0; j < vComponent[i].vLocomotor.size(); j++)	//LOCOMOTOR
		{
			vComponent[i].vLocomotor[j].mSave(ost);
		}
		for(j = 0; j < vComponent[i].vTorso.size(); j++)		//COMPONENT
		{
			vComponent[i].vTorso[j].mSave(ost);
		}		
	}

	fb.close();

}







