#include <iostream>
#include <ostream>
#include <fstream>


#include <string>
#include <vector>

using namespace std;

class Arm		/*=============================================================================================== ARM */
{
	private:
		int mPowerConsumed;

	public:
		Arm() {}
		Arm(int aPowerConsumed)  : mPowerConsumed(aPowerConsumed) { }
		Arm(istream& ist)	// Read input from stream to variable
		{
			ist >> mPowerConsumed;
		}
		void mSave(ostream& ost)	// Output variable to stream
		{
			ost  << "#Arm " <<  mPowerConsumed << endl;
		}
};

class Batteries		/*=============================================================================================== BATTERIES */
{
	private:
		int mEnergy;

	public:
		Batteries() {}
		Batteries(int aEnergy)  : mEnergy(aEnergy) { }
		void mSave(ostream& ost)
		{
			ost << "#Batteries " <<  mEnergy << endl;
		}
};

class Head		/*=============================================================================================== HEAD */
{
	public:
		Head() { }
		void mSave(ostream& ost)
		{
			ost << "#Head " << endl;
		}
};

class Locomotor		/*=============================================================================================== LOCOMOTOR */
{
	private:
		int mMaxSpeed;
		int mPowerConsumed;

	public:
		Locomotor() {}
		Locomotor(int aMaxSpeed, int aPowerConsumed)  : mMaxSpeed(aMaxSpeed), mPowerConsumed(mPowerConsumed) { }
		void mSave(ostream& ost)
		{
			ost << "#Locomotor " << mMaxSpeed; 
			ost << "#Locomotor " << mPowerConsumed << endl;
		}
};

class Torso		/*=============================================================================================== TORSO */
{
	private:
		int mBatteryCompartment;

	public:
		Torso() {}
		Torso(int aBatteryCompartment)  : mBatteryCompartment(aBatteryCompartment) { }
		void mSave(ostream& ost)
		{
			ost  << "#Torso " <<  mBatteryCompartment << endl;
		}
};

class Component : public Torso, public Head, public Arm, public Batteries, public Locomotor		// =========================== COMPONENT
{
	private:
		std::string mName;	// if not std:: then get error. Have to use using namespace std here
							// However to avoid including this file ALONG WITH 'using the namespace std', good practice to put std:: instead
		int mPartNum;
		int mWeight;
		int mCost;
		std::string mDescription;


	public:
		std::vector <Torso> vTorso;
		std::vector <Head> vHead;
		std::vector <Arm> vArm;
		std::vector <Batteries> vBatteries;
		std::vector <Locomotor> vLocomotor;

		Component()
		{
			int choice;

			cout << "\nWhat kind of component are you creating?";
			cout << "\n1. Torso\n2. Head\n3. Arm\n4. Batteries\n5. Locomotor\n\nChoice: ";
			cin >> choice;
			cin.ignore();


			cout << "Component Name: ";
			getline(cin, mName);

			cout << "Component Part Number: ";
			cin >> mPartNum;
			cin.ignore();

			cout << "Component Weight: ";
			cin >> mWeight;
			cin.ignore();

			cout << "Component Cost: ";
			cin >> mCost;
			cin.ignore();

			cout << "Component Description: ";
			getline(cin, mDescription);

			switch(choice - 1)
			{
				case 0: { mCreate_Torso(); break; }
				case 1: { mCreate_Head(); break; }
				case 2: { mCreate_Arm(); break; }
				case 3: { mCreate_Batteries(); break; }
				case 4: { mCreate_Locomotor(); break; }
			}
		}

		Component(std::string aName, int aPartNum, int aWeight, int aCost, std::string aDescription, int aChoice)
		 : mName(aName), mPartNum(aPartNum), mWeight(aWeight), mCost(aCost), mDescription(aDescription)
		{
			switch(aChoice - 1)
			{
				case 0:
				{
					mCreate_Torso();
					cout << "\nTorso Created.";
					break;
				}
				case 1:
				{
					mCreate_Head();
					cout << "\nHead Created.";
					break;
				}
				case 2:
				{
					mCreate_Arm();
					cout << "\nArm Created.";
					break;
				}
				case 3:
				{
					mCreate_Batteries();
					cout << "\nBatteries Created.";
					break;
				}
				case 4:
				{
					mCreate_Locomotor();
					cout << "\nLocomotor Created.";
					break;
				}
			}
		}

		void mCreate_Torso()
		{
			int lBatteryCompartment;

			cout << "Number of Batteries: ";
			cin >> lBatteryCompartment;
			cin.ignore();

			Torso torso(lBatteryCompartment);	// this is a locol object, is destroyed once gone, thus a problem when an instance of component instances a class of torso
			vTorso.push_back(torso);			// a rough work around to this problem, component creates a vector to keep them around (inheritance)
		}

		void mCreate_Head()
		{
			Head head;
			vHead.push_back(head);
		}

		void mCreate_Arm()
		{
			int powerConsumed;

			cout << "Power Consumed (in watts): ";
			cin >> powerConsumed;
			cin.ignore();

			Arm arm(powerConsumed);
			vArm.push_back(arm);	
		}

		void mCreate_Batteries()
		{
			int energy;

			cout << "Energy in batteries: ";
			cin >> energy;
			cin.ignore();

			Batteries batteries(energy);
			vBatteries.push_back(batteries);
		}

		void mCreate_Locomotor()
		{
			int maxSpeed;
			int powerConsumed;

			cout << "Max Speed: ";
			cin >> maxSpeed;
			cin.ignore();
			cout << "Power Consumed (in watts): ";
			cin >> powerConsumed;

			Locomotor locomotor(maxSpeed, powerConsumed);
			vLocomotor.push_back(locomotor);
		}

		std::string mComponent_Info()
		{
			std::string partNum = std::to_string(mPartNum);
			std::string weight = std::to_string(mWeight);
			std::string cost = std::to_string(mCost);

			return("\nComponent Name: " + mName + "\nComponent Part Number: " + partNum + "\nComponent Weight: " + weight + 
					"\nComponent Cost: " + cost + "\nComponent Description: " + mDescription + "\n");
		}	
};

class Model		/*=============================================================================================== MODEL */
{
	private:
		std::string mModelName;
		int mModelNumber;
		int mModelPrice;

	public:
		Model(std::string aModelName, int aModelNumber, int aModelPrice) : mModelName(aModelName), mModelNumber(aModelNumber), mModelPrice(aModelPrice)
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

		std::string mModel_Info()
		{
			std::string modelNumber = std::to_string(mModelNumber);	
			std::string modelPrice = std::to_string(mModelPrice);
			return ("\nModel Name: " + mModelName + "\nModel Number: " + modelNumber + "\nModel Price: " + modelPrice + "\n");
		}
};

class Customer		/*=============================================================================================== CUSTOMER */
{
	private:
		std::string mCustomerName;
		std::string mCustomerPhone;
		std::string mCustomerEmail;

	public:
		Customer(std::string aCustomerName, std::string aCustomerPhone, std::string aCustomerEmail) 
			: mCustomerName(aCustomerName), mCustomerPhone(aCustomerPhone), mCustomerEmail(aCustomerEmail) { }

		std::string mCustomer_Info()
		{
			return ("\nCustomer Name: " + mCustomerName + "\nCustomer Phone Number: " + mCustomerPhone + "\nCustomer Email: " + mCustomerEmail + "\n");
		}
};


class Employee		/*=============================================================================================== EMPLOYEE */
{
	private:
		std::string mEmployeeName;
		std::string mEmployeeNumber;
		int mPassword;
	public:
		Employee(std::string aEmployeeName, std::string aEmployeeNumber) 
			: mEmployeeName(aEmployeeName), mEmployeeNumber(aEmployeeNumber) { }

		std::string mEmployee_Info()
		{
			return ("\nEmployee Name: " + mEmployeeName + "\nEmployee Number: " + mEmployeeNumber + "\n");
		}
};

class Shop		/*=============================================================================================== SHOP */
{
	private:
		std::vector<Model> vModel;
		std::vector<Component> vComponent;
		std::vector<Customer> vCustomer;
		std::vector<Employee> vEmployee;

	public:
		Shop()
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

		void mCreate_Component()
		{
			Component component;
			vComponent.push_back(component);
		}

		void mCreate_Model()
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

		void mList_Components()
		{
			for(int i = 0; i < vComponent.size(); i++)
			{
				cout << vComponent[i].mComponent_Info();
			}
		}

		void mList_Models()
		{
			for(int i = 0; i < vModel.size(); i++)
			{
				cout << vModel[i].mModel_Info();
			}
		}

		void mAdd_Customer()
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

		void mList_Customers()
		{
			for(int i = 0; i < vCustomer.size(); i++)
			{
				cout << vCustomer[i].mCustomer_Info();
			}
		}

		void mAdd_Employee()
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

		void mList_Employees()
		{
			for(int i = 0; i < vEmployee.size(); i++)
			{
				cout << vEmployee[i].mEmployee_Info();
			}
		}

		void mSave_Shop()
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
};

/*===================================================================================================================================================================
=====================================================================================================================================================================
================================================================== THE MAIN FUNCTION ================================================================================
=====================================================================================================================================================================
===================================================================================================================================================================*/

int main(void)
{
	Shop shop;

	return 0;
}








