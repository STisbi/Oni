#include "Component.h"

using namespace std;

Component::Component(std::string aName, int aPartNum, int aWeight, int aCost, std::string aDescription, int aChoice)
 : mName(aName), mPartNum(aPartNum), mWeight(aWeight), mCost(aCost), mDescription(aDescription)
{
	switch(aChoice - 1)
	{
		case 0:
		{
			cout << "\nNumber of Batteries: ";
			mCreate_Torso();
			cout << "\nTorso Created.";
			break;
		}
	}
}

void Component::mCreate_Torso()
{
	int lBatteryCompartment;

	cin >> lBatteryCompartment;
	cin.ignore();
	Torso torso(lBatteryCompartment);
}



/*
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
}*/
