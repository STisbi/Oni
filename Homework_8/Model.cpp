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

	cout << "\n\nWhat kind of component are you adding?";
	cout << "\n1. Torso\n\nChoice: ";
	cin >> choice;
	cin.ignore();

	switch(choice - 1)
	{
		case 0:
		{
			cout << "\nNew Torso";

			cout << "\nName: ";
			getline(cin, name);

			cout << "\nPart Number: ";
			cin >> part_number;
			cin.ignore();

			cout << "\nWeight: ";
			cin >> weight;
			cin.ignore();

			cout << "\nCost: ";
			cin >> cost;
			cin.ignore();

			cout << "\nDescription: ";
			getline(cin, description);

			Component component(name, part_number, weight, cost, description, choice);
			cout << "\nComponent Created.";
			break;
		}
	}
}
