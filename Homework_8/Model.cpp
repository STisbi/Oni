#include "Model.h"

using namespace std;

Model::Model(std::string aModelName, int aModelNumber, int aModelPrice) : mModelName(aModelName), mModelNumber(aModelNumber), mModelPrice(aModelPrice)
{
	int choice;
	std::string name;
	int part_number;
	int weight;
	int cost;
	std::string description;
	bool run = true;

	while(run)
	{
		cout << "\nWhat kind of component are you adding?";
		cout << "\n1. Torso\n2. Head\n3. Arm\n4. Batteries\n5. Locomotor\n\nChoice: ";
		cin >> choice;
		cin.ignore();


		cout << "Component Name: ";
		getline(cin, name);

		cout << "Component Part Number: ";
		cin >> part_number;
		cin.ignore();

		cout << "Component Weight: ";
		cin >> weight;
		cin.ignore();

		cout << "Component Cost: ";
		cin >> cost;
		cin.ignore();

		cout << "Component Description: ";
		getline(cin, description);

		Component component(name, part_number, weight, cost, description, choice);
		cout << "\nComponent Created. Would you like to add an additional part?\n1. Yes\n2. No\n\nChoice: ";
		cin >> choice;
		cin.ignore();

		run = (choice == 1) ? true : false;
	}
}

std::string Model::mModel_Info()
{
	std::string modelNumber = std::to_string(mModelNumber);	
	std::string modelPrice = std::to_string(mModelPrice);
	return ("\nModel Name: " + mModelName + "\nModel Number: " + modelNumber + "\nModel Price: " + modelPrice + "\n");
}




