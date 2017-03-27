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

	cout << "Number of Batteries?\n";
	cin >> battery;
	cin.ignore();

	Torso torso(battery, name, part_number, weight, cost, description);

	return 0;
}
