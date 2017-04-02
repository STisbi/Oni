#include <iostream>
#include <string>
#include <vector>

#include "Component.h"
#include "Torso.h"
#include "Head.h"
#include "Arm.h"
#include "Locomotor.h"
#include "Batteries.h"

using namespace std;

int main(void)
{
	string name;
	int part_number;
	int weight;
	int cost;
	string description;
	int battery;
	int choice;
	int powerConsumed;
	int maxSpeed;
	int energy;

	cout << "Name?\n";
	getline(cin, name);

	cout << "Part Number?\n";
	cin >> part_number;
	cin.ignore();

	cout << "Weight?\n";
	cin >> weight;
	cin.ignore();

	cout << "Cost?\n";
	cin >> cost;
	cin.ignore();

	cout << "Desciption?\n";
	getline(cin, description);

	cout << "1. Torso\n2. Head\n3. Arm\n4. Locomotor\n5. Batteries\n\nChoice: ";
	cin >> choice;
	cin.ignore();
/*
	switch(choice - 1)
	{
		case 0:
		{
			cout << "\nTorso";
			cout << "\nNumber of Batteries?: ";
			cin >> battery;
			cin.ignore();
			Torso torso(battery, name, part_number, weight, cost, description);
			cout << "\nCreated.\n";
			break;
		}
		case 1:
		{
			cout << "\nHead\n";
			cout << "Created.\n";
			Head head(name, part_number, weight, cost, description);
			break;
		}
		case 2:
		{
			cout << "\nArm";
			cout << "\nPower Consumed (in watts): ";
			cin >> powerConsumed;
			cin.ignore();
			Arm arm(powerConsumed, name, part_number, weight, cost, description);
			cout << "\nCreated.\n";
			break;
		}
		case 3:
		{
			cout << "\nLocomotor";
			cout << "\nMax Speed: ";
			cin >> maxSpeed;
			cin.ignore();
			cout << "Power Consumed (in watts): ";
			cin >> powerConsumed;
			cin.ignore();
			Locomotor(maxSpeed, powerConsumed, name, part_number, weight, cost, description);
			cout << "\nCreated.\n";
			break;
		}
		case 4:
		{
			cout << "\nBatteries";
			cout << "\nEnergy: ";
			cin >> energy;
			cin.ignore();
			Batteries batteries(energy, name, part_number, weight, cost, description);
			cout << "\nCreated.\n";
			break;
		}
	}
*/
	return 0;
}
